from typing import Protocol

# 1. Define the Protocol
class Quacker(Protocol):
    def quack(self) -> str:
        ...

# 2. Implement classes with matching methods
class Duck:
    def quack(self) -> str:
        return "Quack!"

class Person:
    def quack(self) -> str:
        return "I'm quacking!"

# 3. Use the Protocol in type hints
def make_it_quack(q: Quacker) -> None:
    print(q.quack())

make_it_quack(Duck())   # Valid
make_it_quack(Person()) # Valid
