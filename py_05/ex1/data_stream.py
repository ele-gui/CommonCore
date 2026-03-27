from typing import Any, List, Dict, Union, Optional
from abc import ABC, abstractmethod


class DataStream(ABC):
    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.processed_count: int = 0 #tiene traccia dei dati elaborati

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str: #Process a batch of data
        pass


    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]: #Filter data based on criteria
        return data_batch


    def get_stats(self) -> Dict[str, Union[str, int, float]]: #Return stream statistics
        return {"stream_id": self.stream_id, "processed": self.processed_count}



class SensorStream(DataStream):
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.stream_type: str = "Environmental Data"


    def process_batch(self, data_batch: List[Any]) -> str:
        values: List[float] = []
        for item in data_batch:
            try:
                parts = str(item).split(":")
                values.append(float(parts[1]))
            except (ValueError, IndexError) as e:
                print(f"Scartato: {item}, errore: {e}")

        self.processed_count += len(values)
        avg: float = sum(values) / len(values) if values else 0.0
        return f"Sensor analysis: {len(values)} readings processed, avg temp: {avg}°C"
        

    def filter_data(self, data_batch: List[Any], criteria:Optional[str] = None) -> List[Any]:
        if criteria == "high":
            #tengo solo i valori sopra una certa soglia
            result: List[Any] = [
                item for item in data_batch
                if float(str(item).split(":")[1]) > 100
            ]
            return result
        return data_batch
        

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = super().get_stats() #prende stream_id e processed dalla base
        stats["type"] = self.stream_type
        return stats

class TransactionStream(DataStream):
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.stream_type: str = "Financial Data"


    def process_batch(self, data_batch: List[Any]) -> str:
        values: List[float] = []
        for item in data_batch:
            try:
                parts = str(item).split(":")
                values.append(int(parts[1]))
            except (ValueError, IndexError):
                pass

        self.processed_count += len(values)
        net_flow: int = 0
        for item in data_batch:
            try:
                parts = str(item).split(":")
                op: str = parts[0]
                val: int = int(parts[1])
                if op == "buy":
                    net_flow += val
                elif op == "sell":
                    net_flow -= val
            except (ValueError, IndexError):
                pass
        #mancano il segno + quando stampo
        return f"Transaction analysis: {len(values)} operations, net flow: {net_flow} units"
    

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]:
        if criteria == "large":
            result: List[Any] = [
                item for item in data_batch
                if int(str(item).split(":")[1]) > 50 #decido io la soglia
            ]
            return result
        return data_batch


    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats = super().get_stats() #prende stream_id e processed dalla base
        stats["type"] = self.stream_type
        return stats

class EventStream(DataStream):
    pass


#serve a gestire tutte le stream insieme, senza sapere di che tipo sono
#lo uso alla fine quando metto tutto insieme
class StreamProcessor:
    def __init__(self):
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream) -> None:
        ...

    def process_all(self, batches: List[List[Any]]) -> None:
        ...



if __name__ == "__main__":
    print("=== TEST SENSOR STREAM ===\n")
    
    sensor: SensorStream = SensorStream("SENSOR_001")
    batch: List[Any] = ["temp:22.5", "humidity:65", "pressure:1013"]
    
    print(f"Stream ID: {sensor.stream_id}, Type: {sensor.stream_type}")
    print(f"Processing batch: {batch}")
    
    try:
        result: str = sensor.process_batch(batch)
        print(result)
    except ValueError as e:
        print(f"Error: {e}")
    
    print(f"Stats: {sensor.get_stats()}")
    
    print("\n=== TEST FILTER ===")
    filtered: List[Any] = sensor.filter_data(batch, "high")
    print(f"Filtered (high): {filtered}")

    print("\n\n=== TEST TRANSACTION STREAM ===\n")

    trans: TransactionStream = TransactionStream("TRANS_001")
    batch_t: List[Any] = ["buy:100", "sell:250", "buy:75"]

    print(f"Stream ID: {trans.stream_id}, Type: {trans.stream_type}")
    print(f"Processing batch: {batch_t}")

    try:
        result_t: str = trans.process_batch(batch_t)
        print(result_t)
    except ValueError as e:
        print(f"Error: {e}")

    print(f"Stats: {trans.get_stats()}")

    print("\n=== TEST FILTER TRANSACTION ===")
    filtered_t: List[Any] = trans.filter_data(batch_t, "large") #fare la prova senza la str
    print(f"Filtered (large): {filtered_t}")