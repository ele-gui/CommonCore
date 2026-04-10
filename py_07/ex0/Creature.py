from abc import ABC, abstractmethod


class Colors:
    red = "\033[31m"
    cyan = "\033[36m"
    blue = "\033[34m"
    green = "\033[32m"
    magenta = "\033[35m"
    grey = "\033[90m"
    drago = "\033[38;2;112;56;248m"
    dark_grey = "\033[38;2;50;50;50m"

    tournament_emphasis = "\033[38;2;110;90;200m"
    tournament = "\033[38;2;170;150;255m"
    battle = "\033[38;2;150;90;220m"
    reset = "\033[0m"

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
        super().__init__("Pyrodon", f"{Colors.red}Fire{Colors.reset}/{Colors.cyan}Flying{Colors.reset}")

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
