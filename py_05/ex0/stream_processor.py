from typing import Any, List, Dict, Union, Optional
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

    def validate(self, data: Any) -> bool: #da cambiare con type
        if not isinstance(data, list): #controlla che data sia una lista
            return False
        for item in data:
            if not isinstance(item, (int, float)): #controlla che tutti gli elementi siano float
                return False
        return True


    def process(self, data:Any) -> str:
        if not self.validate(data): #se il dato non e' valido errore
            raise ValueError("NumericProcessor expects a list of numbers")
        total: Union[int, float] = 0 #type hints
        for item in data:
            total += item
        count: int = len(data)
        avg: float = total / count if count > 0 else 0.0
        return f"Processed {count} numeric values, sum = {total}, average = {avg}"
    

    def format_output(self, result: str) -> str:
        return f"Output: {result}"
        




# class TextProcessor(DataProcessor):
    
    
    
# class LogProcessor(DataProcessor):


if __name__ == "__main__":
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
 
    numeric_proc: NumericProcessor = NumericProcessor()
    print("Initializing Numeric Processor...")
    print("Processing data: [1, 2, 3, 4, 5]")
    print("Validation: Numeric data verified")
    print(numeric_proc.format_output(numeric_proc.process([1, 2, 3, 4, 5])))
 
    print()
 
    # text_proc: TextProcessor = TextProcessor()
    # print("Initializing Text Processor...")
    # print('Processing data: "Hello Nexus World"')
    # print("Validation: Text data verified")
    # print(text_proc.format_output(text_proc.process("Hello Nexus World")))
 
    # print()
 
    # log_proc: LogProcessor = LogProcessor()
    # print("Initializing Log Processor...")
    # print('Processing data: "ERROR: Connection timeout"')
    # print("Validation: Log entry verified")
    # print(log_proc.format_output(log_proc.process("ERROR: Connection timeout")))
 
    # print()
    # print("=== Polymorphic Processing Demo ===")
    # print("Processing multiple data types through same interface...")
 
    processors: List[DataProcessor] = [
        NumericProcessor(),
        # TextProcessor(),
        # LogProcessor(),
    ]
    items: List[Any] = [
        [1, 2, 3],
        "Hello World",
        "INFO: System ready",
    ]
 
    index: int = 1
    for processor, item in zip(processors, items):
        try:
            result: str = processor.process(item)
            print(f"Result {index}: {result}")
        except ValueError as exc:
            print(f"Result {index}: Error - {exc}")
        index += 1
 
    print()
    print("Foundation systems online. Nexus ready for advanced streams.")
 