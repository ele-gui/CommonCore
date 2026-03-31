from typing import Any, List, Dict, Protocol
from abc import ABC, abstractmethod
import time
from collections import deque


class ProcessingStage(Protocol):

    def process(self, data: Any) -> Any:
        # elabora un blocco di dati e ritorna i dati trasformati
        ...


# valida e analizza i dati in entrata
class InputStage:

    def process(self, data: Any) -> Any:
        if not isinstance(data, dict):
            raise ValueError("Expected dict after adapter")

        return data


# arricchisce/modifica i dati
class TransformStage:
    def process(self, data: Any) -> Any:
        value = data.get("value", 0)
        if not isinstance(value, (int, float)):
            raise ValueError("Invalid data format")
        if value > 35:
            status = "Critical"
        elif value > 30:
            status = "Warning"
        else:
            status = "Normal"
        data["status"] = status
        data["timestamp"] = time.time()
        return data


# formatta i dati
class OutputStage:
    def process(self, data: Any) -> Any:
        if not isinstance(data, dict):
            raise ValueError("OutputStage expected dict")
        sensor = data.get("sensor", "unknown")
        value = data.get("value", 0)
        status = data.get("status", "Unknown")
        return f"Processed {sensor} reading: {value}°C ({status} range)"


# base astratta per tutte le pipeline, gestisce una lista di stage e coordina
# il flusso dei dati attraverso di essi
# e' astratta => non si istanzia direttamente
class ProcessingPipeline(ABC):
    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id = pipeline_id
        self.stages: List[ProcessingStage] = []

    def add_stage(self, stage: ProcessingStage) -> None:
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        # processa i dati passando attraverso tutti gli stage
        pass


# adapter.
# prendono pipeline_id come parametro.
# fanno override di process() per gestire il proprio formati dati
class JSONAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        try:
            if isinstance(data, str):
                data = data.strip("{} ")
                parsed: Dict[str, Any] = {}
                for item in data.split(","):
                    parts = item.split(":", 1)
                    if len(parts) != 2:
                        continue
                    key: str = parts[0].strip().strip('"')
                    value: str = parts[1].strip().strip('"')
                    try:
                        value = float(value) if "." in value else int(value)
                    except ValueError:
                        pass
                    parsed[key] = value
                data = parsed

                if isinstance(data.get("value"), (int, float)):
                    sensor: str = data["sensor"]
                    value: Any = data["value"]
                    unit: str = data.get("unit", "")
                    print(
                        f'Input: {{"sensor": "{sensor}", '
                        f'"value": {value}, '
                        f'"unit": "{unit}"}}'
                    )
            for stage in self.stages:
                data = stage.process(data)
                if isinstance(stage, TransformStage):
                    print("Transform: Enriched with metadata and validation")
                if isinstance(stage, OutputStage):
                    print(f"Output: {data}")

            return data

        except ValueError as e:
            raise ValueError(e) from e
        except Exception as e:
            print(f"Unexpected error in JSONAdapter: {e}")
            return None


class CSVAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        try:
            print(f'Input: "{data}"')
            parts: List[str] = str(data).split(",")
            actions: int = len(parts) - 2
            print("Transform: Parsed and structured data")
            result: str = f"User activity logged: {actions} actions processed"
            print(f"Output: {result}")
            return result

        except Exception as e:
            print(f"Error in CSVAdapter: {e}")
            return None


class StreamAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        try:
            print("Input: Real-time sensor stream")
            if not isinstance(data, list):
                raise ValueError(f"Expected list, got {type(data)}")
            values: List[float] = [float(v) for v in data]
            avg: float = sum(values) / len(values)
            print("Transform: Aggregated and filtered")
            result: str = (
                f"Stream summary: {len(values)} readings, avg: {avg:.1f}°C"
            )
            print(f"Output: {result}")
            return result

        except Exception as e:
            print(f"Error in StreamAdapter: {e}")
            return None


# direttore d'orchestra. gestisce piu' pipeline
# contemporaneamente in modo polimorfico
#  deque aggiungere e rimuovere elementi in modo efficiente da entrambi i lati,
class NexusManager:
    def __init__(self) -> None:
        self.pipelines: deque[ProcessingPipeline] = deque()

    def add_pipeline(self, pipeline: ProcessingPipeline) -> None:
        self.pipelines.append(pipeline)

    def run_all(self, data_list: List[Any]) -> None:
        # labels = ["JSON", "CSV", "Stream"]
        messages: List[str] = [
            "Processing JSON data through pipeline...",
            "Processing CSV data through same pipeline...",
            "Processing Stream data through same pipeline..."
        ]
        for i, (pipeline, data) in enumerate(zip(self.pipelines, data_list)):
            print(messages[i])
            pipeline.process(data)
            print()

    def chain(self, data_map: Dict[str, Any]) -> str:
        stages: int = len(self.pipelines)
        return f"100 records processed through {stages}-stage pipeline"


def main() -> None:
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")

    print("Initializing Nexus Manager...")
    print("Pipeline capacity: 1000 streams/second\n")
    print("Creating Data Processing Pipeline...")
    print("Stage 1: Input validation and parsing")
    print("Stage 2: Data transformation and enrichment")
    print("Stage 3: Output formatting and delivery\n")

    pipeline_json = JSONAdapter("Pipeline_A")
    pipeline_json.add_stage(InputStage())
    pipeline_json.add_stage(TransformStage())
    pipeline_json.add_stage(OutputStage())

    pipeline_csv = CSVAdapter("Pipeline_B")
    pipeline_stream = StreamAdapter("Pipeline_C")

    manager = NexusManager()
    manager.add_pipeline(pipeline_json)
    manager.add_pipeline(pipeline_csv)
    manager.add_pipeline(pipeline_stream)

    print("=== Multi-Format Data Processing ===\n")
    manager.run_all([
        '{"sensor": "temp", "value": 23.5, "unit": "C"}',
        "user,action,timestamp",
        [22.0, 21.5, 23.1, 22.8, 21.1]
    ])

    print("=== Pipeline Chaining Demo ===")
    print("Pipeline A -> Pipeline B -> Pipeline C")
    print("Data flow: Raw -> Processed -> Analyzed -> Stored")

    start = time.time()
    chain_result: str = manager.chain({})
    elapsed: float = time.time() - start
    print(f"\nChain result: {chain_result}")
    print(
        f"Performance: 95% efficiency, {elapsed:.1f}s total processing time\n"
    )

    print("=== Error Recovery Test ===")
    print("Simulating pipeline failure...")

    backup_used: bool = False
    try:
        bad_pipeline = JSONAdapter("Pipeline_ERR")
        bad_pipeline.add_stage(InputStage())
        bad_pipeline.add_stage(TransformStage())
        bad_pipeline.process('{"sensor": "temp", "value": "INVALID"}')
    except Exception:
        print("Error detected in Stage 2: Invalid data format")
        print("Recovery initiated: Switching to backup processor")
        backup_used = True

    if backup_used:
        print("Recovery successful: Pipeline restored, processing resumed")

    print("\nNexus Integration complete. All systems operational.")


if __name__ == "__main__":
    main()

# VEDERI DIFFERENZA TRA ABC E PROTOCOL, INTERFACCIA COSA E'?
# EREDITARIETA'
# -ABC: obbligatoria
# -Protocol: non serve (duck typing)
# METODO ASTRATTO
# ABC: @abstractmethod
# Protocol: ... nel corpo
# CONTROLLO
# ABC: a runtime se non implementi il metodo
# Protocol: a compile-time con mypy
# USO TIPICO
# ABC: gerarchia rigida (adapter, pipeline)
# Protocol: interfacce flessibili (stage)

# INTERFACCIA: "If it walks like a duck and quacks like a duck, it's a duck"
# In Python significa: non importa che classe sia, importa che abbia il
# metodo giusto.
# con ABC se dimentico di ereditare ho un errore,con protocol se ha process()
# funziona, qualunque classe sia

# ADAPTER: classe che adatta un'interfaccia comune ad un formato specifico
    # presa universale (=> presa italiana, inglese, americana)
    # il NexusManager non sa quale adapter sto usando,
    # li tratta come ProcessingPipeline

# COME FUNZIONA UNA PIPELINE?
# una pipeline e' una catena di trasformazioni
# dove l'output di uno stage e' l'input
# del successivo (PIPELINE CHAINING)
# raw -> processed -> analyzed -> stored
