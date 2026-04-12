from abc import ABC, abstractmethod
from ex1.Creature import Creature
from ex1.Capability import TransformCapability, HealCapability
from typing import cast


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
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.creature_name}' "
                f"for this aggressive strategy"
            )
        # comunicare all'IDE il tipo di una variabile quando tu sai qualcosa 
        # che il type checker non riesce a dedurre da solo.
        t = cast(TransformCapability, creature)
        return [t.transform(), creature.attack(), t.revert()]


class DefensiveStrategy(BattleStrategy):

    # suitable for Creature with healing capabilities
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"DefensiveStrategy is not valid for "
                f"{creature.creature_name}: "
                f"it requires HealCapability."
            )

        h = cast(HealCapability, creature)
        return [creature.attack(), h.heal()]
