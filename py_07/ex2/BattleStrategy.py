from abc import ABC, abstractmethod
from ex1.Creature import Creature, Shiftling, Sproutling, Bloomelle, Morphagon


class InvalidStrategyError(Exception):
    pass


class BattleStrategy(ABC):

    # indicating that a Creature is suitable for the strategy
    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass

    @abstractmethod
    def act(self, creature: Creature) -> list[str]:
        pass


class NormalStrategy(BattleStrategy):

    # suitable for any Creature
    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> list[str]:
        return [creature.attack()]


class AggressiveStrategy(BattleStrategy):

    # suitable for Creature with transform capabilities
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, (Shiftling, Morphagon))

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.creature_name}' "
                f"for this aggressive strategy"
            )

        if isinstance(creature, (Shiftling, Morphagon)):
            return [creature.transform(), creature.attack(), creature.revert()]
        raise InvalidStrategyError(
                f"Invalid Creature '{creature.creature_name}' "
                f"for this aggressive strategy"
            )


class DefensiveStrategy(BattleStrategy):

    # suitable for Creature with healing capabilities
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, (Sproutling, Bloomelle))

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"DefensiveStrategy is not valid for "
                f"{creature.creature_name}: "
                f"it requires HealCapability."
            )
        if isinstance(creature, (Sproutling, Bloomelle)):
            return [creature.attack(), creature.heal()]
        raise InvalidStrategyError(
                f"DefensiveStrategy is not valid for "
                f"{creature.creature_name}: "
                f"it requires HealCapability."
            )
