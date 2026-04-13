from abc import ABC, abstractmethod
from ex0.Colors import Colors


class Creature(ABC):
    def __init__(self, creature_name: str, creature_type: str):
        self.creature_name = creature_name
        self.creature_type = creature_type

    @abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self.creature_name} is a {self.creature_type} type Creature"


class Flameling(Creature):

    def __init__(self):
        super().__init__("Flameling", f"{Colors.red}Fire{Colors.reset}")

    def attack(self) -> str:
        return f"{self.creature_name} uses Ember!"


class Pyrodon(Creature):

    def __init__(self):
        super().__init__(
            "Pyrodon",
            f"{Colors.red}Fire{Colors.reset}"
            f"/{Colors.cyan}Flying{Colors.reset}"
        )

    def attack(self) -> str:
        return f"{self.creature_name} uses Flamethrower!"


class Aquabub(Creature):

    def __init__(self):
        super().__init__("Aquabub", f"{Colors.blue}Water{Colors.reset}")

    def attack(self) -> str:
        return f"{self.creature_name} uses Water Gun!"


class Torragon(Creature):

    def __init__(self):
        super().__init__("Torragon", f"{Colors.blue}Water{Colors.reset}")

    def attack(self) -> str:
        return f"{self.creature_name} uses Hydro Pump!"
