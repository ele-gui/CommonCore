from abc import ABC, abstractmethod
from ex0.Creature import Creature, Flameling, Aquabub, Pyrodon, Torragon


class CreatureFactory(ABC):

    @abstractmethod
    def create_base(self) -> Creature:
        pass

    @abstractmethod
    def create_evolved(self) -> Creature:
        pass


class FlameFactory(CreatureFactory):

    def create_base(self) -> Flameling:  # Flameling
        return Flameling()

    def create_evolved(self) -> Pyrodon:  # Pyrodon
        return Pyrodon()


class AquaFactory(CreatureFactory):

    def create_base(self) -> Aquabub:  # Aquabub
        return Aquabub()

    def create_evolved(self) -> Torragon:  # Torragon
        return Torragon()
