from typing import Any, List, Union
from abc import ABC, abstractmethod


class DataProcessor(ABC):

    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if not isinstance(data, list):
            return False
        for item in data:
            if not isinstance(item, (int, float)):
                return False
        return True

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("NumericProcessor expects a list of numbers")
        total: Union[int, float] = sum(data)
        count: int = len(data)
        avg: float = total / count if count > 0 else 0.0

        return f"Processed {count} numeric values, sum={total}, avg={avg}"

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if not isinstance(data, str):
            return False
        return True

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("TextProcessor expects a str")
        total: int = 0
        words: int = 1
        for char in data:
            total += 1
            if char == ' ':
                words += 1
        return f"Processed text: {total} characters, {words} words"

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


class LogProcessor(DataProcessor):

    LEVELS: List[str] = ["INFO", "WARNING", "ERROR", "CRITICAL"]  # SONO TROPPI

    def validate(self, data: Any) -> bool:
        if not isinstance(data, str):
            return False

        for level in self.LEVELS:
            if data.startswith(level):
                return True
        return False

    def process(self, data: Any) -> str:
        if not self.validate(data):
            raise ValueError("LogProcessor expects a str")
        detected_level: str = "UNKNOWN"
        for level in self.LEVELS:
            if data.startswith(level):
                detected_level = level
                break
        message: str = data[len(detected_level) + 2:]
        if detected_level in ("ERROR", "CRITICAL"):
            tag: str = "[ALERT]"
        else:
            tag: str = "[INFO]"
        return f"{tag} {detected_level} level detected: {message}"

    def format_output(self, result: str) -> str:
        return f"Output: {result}"


def main() -> None:
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")

    numeric_proc: NumericProcessor = NumericProcessor()
    numeric_list = [1, 2, 3, 4, 5]
    print("\nInitializing Numeric Processor...")
    print(f"Processing data: {numeric_list}")
    try:
        result = numeric_proc.process(numeric_list)
        print("Validation: Numeric data verified")
        print(numeric_proc.format_output(result))
    except ValueError as e:
        print(f"Validation: Numeric entry invalid - {e}")

    text_proc: TextProcessor = TextProcessor()
    string = "Hello Nexus World"
    print("\nInitializing Text Processor...")
    print(f'Processing data: "{string}"')
    try:
        result = text_proc.process(string)
        print("Validation: Text data verified")
        print(text_proc.format_output(result))
    except ValueError as e:
        print(f"Validation: Text entry invalid - {e}")

    log_proc: LogProcessor = LogProcessor()
    string = "ERROR: Connection timeout"
    print("\nInitializing Log Processor...")
    print(f'Processing data: "{string}"')
    try:
        result = log_proc.process(string)
        print("Validation: Log entry verified")
        print(log_proc.format_output(result))
    except ValueError as e:
        print(f"Validation: Log entry invalid - {e}")

    print("\n=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")

    processors: List[DataProcessor] = [
        NumericProcessor(),
        TextProcessor(),
        LogProcessor(),
    ]
    items: List[Any] = [
        [1, 2, 3],
        "Hello World!",
        "INFO: System ready",  # se scambio due righe da errore, GIUSTO
    ]

    index: int = 1
    for processor, item in zip(processors, items):
        try:
            result: str = processor.process(item)
            print(f"Result {index}: {result}")
        except ValueError as e:
            print(f"Result {index}: Error - {e}")
        index += 1

    print("\nFoundation systems online. Nexus ready for advanced streams.")


if __name__ == "__main__":
    main()
