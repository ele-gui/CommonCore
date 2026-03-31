from typing import Any, List, Dict, Union, Optional
from abc import ABC, abstractmethod


class DataStream(ABC):
    def __init__(self, stream_id: str) -> None:
        self.stream_id = stream_id
        self.processed_count: int = 0  # tiene traccia dei dati elaborati

    # Process a batch of data
    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    # Filter data based on criteria
    def filter_data(
            self,
            data_batch: List[Any],
            criteria: Optional[str] = None
    ) -> List[Any]:

        return data_batch

    # Return stream statistics
    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {"stream_id": self.stream_id, "processed": self.processed_count}


class SensorStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.stream_type: str = "Environmental Data"

    def process_batch(self, data_batch: List[Any]) -> str:
        values: List[float] = []
        temp_values: List[float] = []
        for item in data_batch:
            try:
                parts = str(item).split(":")
                values.append(float(parts[1]))
                if parts[0] == "temp":
                    temp_values.append(float(parts[1]))
            except IndexError:
                raise ValueError(
                    f"Invalid format: '{item}'. Expected 'type:value'"
                )

            except ValueError:
                raise ValueError(f"Invalid value: '{item}'. Must be numeric")

        self.processed_count += len(values)
        avg: float = (
            sum(temp_values) / len(temp_values) if temp_values else 0.0
        )
        return (
            f"Sensor analysis: {len(values)} "
            f"readings processed, avg temp: {avg:.1f}°C")

    def filter_data(
            self,
            data_batch: List[Any],
            criteria: Optional[str] = None
    ) -> List[Any]:

        result: List[Any] = []

        for item in data_batch:
            try:
                parts = str(item).split(":")
                value = float(parts[1])

                if criteria == "high" and value > 60:
                    result.append(item)
                elif criteria == "medium" and value > 50:
                    result.append(item)

            except IndexError:
                raise ValueError(
                    f"Invalid format: '{item}'. Expected 'type:value'"
                )

            except ValueError:
                raise ValueError(f"Invalid value: '{item}'. Must be numeric")

        return result if criteria else data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = super().get_stats()
        stats["type"] = self.stream_type
        return stats


class TransactionStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.stream_type: str = "Financial Data"

    def process_batch(self, data_batch: List[Any]) -> str:
        values: List[int] = []
        for item in data_batch:
            try:
                parts = str(item).split(":")
                if len(parts) != 2:
                    raise ValueError(
                        f"Invalid format: '{item}'. Expected 'op:value'"
                    )
                op = parts[0]
                values.append(int(parts[1]))

                if op not in ("buy", "sell"):
                    raise ValueError(f"Invalid operation: '{op}'")
            except ValueError as e:
                raise ValueError(f"TransactionStream error on '{item}': {e}")

        self.processed_count += len(values)
        net_flow: int = 0
        for item in data_batch:
            parts = str(item).split(":")
            op: str = parts[0]
            val: int = int(parts[1])
            if op == "buy":
                net_flow += val
            elif op == "sell":
                net_flow -= val
        sign: str = "+" if net_flow > 0 else ""
        return (
            f"Transaction analysis: {len(values)} operations, "
            f"net flow: {sign}{net_flow} units"
        )

    def filter_data(
            self,
            data_batch: List[Any],
            criteria: Optional[str] = None
    ) -> List[Any]:

        result: List[Any] = []
        for item in data_batch:
            try:
                parts = str(item).split(":")
                if len(parts) != 2:
                    raise ValueError(
                        f"Invalid format: '{item}'. Expected 'op:value'"
                    )
                val = int(parts[1])
                if criteria == "large" and val > 100:
                    result.append(item)
            except ValueError as e:
                raise ValueError(
                    f"TransactionStream filter error on '{item}': {e}"
                )
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = super().get_stats()  # prende stream_id e processed dalla base
        stats["type"] = self.stream_type
        return stats


class EventStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.stream_type: str = "System Events"

    def process_batch(self, data_batch: List[Any]) -> str:
        events: List[str] = []
        errors: int = 0
        for event in data_batch:
            try:
                if not isinstance(event, str):
                    raise ValueError(
                        f"Invalid event: '{event}'. Must be a string"
                    )
                events.append(str(event))
                if str(event) == "error":
                    errors += 1
            except (ValueError, IndexError) as e:
                raise ValueError(f"EventStream error: {e}")

        self.processed_count += len(events)
        return f"Event analysis: {len(events)} events, {errors} error detected"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None
    ) -> List[Any]:

        result: List[Any] = []
        for item in data_batch:
            try:
                if not isinstance(item, str):
                    raise ValueError(
                        f"Invalid event: '{item}'. Must be string"
                    )
                if criteria == "errors" and item == "error":
                    result.append(item)
            except ValueError as e:
                raise ValueError(f"EventStream filter error on '{item}': {e}")
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = super().get_stats()
        stats["type"] = self.stream_type
        return stats


# serve a gestire tutte le stream insieme, senza sapere di che tipo sono
# lo uso alla fine quando metto tutto insieme
class StreamProcessor:
    def __init__(self) -> None:
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream) -> None:
        self.streams.append(stream)

    def process_all(self, batches: List[List[Any]]) -> None:
        for stream, batch in zip(self.streams, batches):
            try:
                stream.process_batch(batch)
                if isinstance(stream, SensorStream):
                    print(f"- Sensor data: {len(batch)} readings processed")
                elif isinstance(stream, TransactionStream):
                    print(
                        f"- Transaction data: "
                        f"{len(batch)} operations processed"
                    )
                elif isinstance(stream, EventStream):
                    print(f"- Event data: {len(batch)} events processed")

            except ValueError as e:
                print(f"- Stream {stream.stream_id} FAILED: {e}")
                continue


def main() -> None:
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")

    batches_info = [
        (
            "Sensor",
            SensorStream("SENSOR_001"),
            ["temp:22.5", "humidity:65", "pressure:1013"]
        ),
        (
            "Transaction",
            TransactionStream("TRANS_001"),
            ["buy:100", "sell:150", "buy:75"]
        ),
        (
            "Event",
            EventStream("EVENT_001"),
            ["login", "error", "logout"]
        )
    ]

    for name, stream, batch in batches_info:
        print(f"Initializing {name} Stream...")
        print(f"Stream ID: {stream.stream_id}, Type: {stream.stream_type}")
        batch_str = ", ".join(str(item) for item in batch)
        print(f"Processing {name.lower()} batch: [{batch_str}]")

        try:
            result = stream.process_batch(batch)
            print(result)
        except ValueError as e:
            print(f"Error in {name} stream {stream.stream_id}: {e}")

        print()

    print("=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...\n")

    processor: StreamProcessor = StreamProcessor()
    processor.add_stream(SensorStream("SENSOR_002"))
    processor.add_stream(TransactionStream("TRANS_002"))
    processor.add_stream(EventStream("EVENT_002"))

    batches: List[List[Any]] = [
        ["temp:22.5", "humidity:65"],
        ["buy:100", "sell:50", "buy:75", "sell:30"],
        ["login", "error", "logout"],
    ]

    print("Batch 1 Results:")
    processor.process_all(batches)

    print("\nStream filtering active: High-priority data only")
    try:
        sensor_filtered: List[Any] = processor.streams[0].filter_data(
            batches[0], "high"
        )
    except (ValueError, IndexError) as e:
        print(f"Filter error (sensor): {e}")
        sensor_filtered = []

    try:
        trans_filtered: List[Any] = processor.streams[1].filter_data(
            batches[1], "large"
        )
    except (ValueError, IndexError) as e:
        print(f"Filter error (transaction): {e}")
        trans_filtered = []

    try:
        event_filtered = processor.streams[2].filter_data(batches[2], "errors")
    except ValueError as e:
        print(f"Filter error (event): {e}")
        event_filtered = []

    print(
        f"Filtered results: {len(sensor_filtered)} critical sensor alerts, "
        f"{len(trans_filtered)} large transactions, "
        f"{len(event_filtered)} error events"
    )

    print("\nAll streams processed successfully. Nexus throughput optimal.")


if __name__ == "__main__":
    main()
