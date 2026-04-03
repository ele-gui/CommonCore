from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, creature_name: str, creature_type: str):
        self.creature_name = creature_name
        self.creature_type = creature_type

    @abstractmethod
    def attack():
        pass

    def describe(self, creature_name: str, creature_type: str):
        return f"{creature_name} is a {creature_type} Creature"


class Flameling(Creature):

    def describe(self, creature_name, creature_type):
        return super().describe(creature_name, creature_type)

    def attack():
        return f"Flameling uses Ember!"


class Pyrodon(Creature):

    def describe(self, creature_name, creature_type):
        return super().describe(creature_name, creature_type)

    def attack():
        return "Pyrodon uses Flamethrower!"


class Aquabub(Creature):

    def describe(self, creature_name, creature_type):
        return super().describe(creature_name, creature_type)

    def attack():
        return "Aquabub uses Water Gun!"


class Torragon(Creature):

    def describe(self, creature_name, creature_type):
        return super().describe(creature_name, creature_type)

    def attack():
        return "Torragon uses Hydro Pump!"