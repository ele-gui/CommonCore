from ex0.CreatureFactory import CreatureFactory
from ex0.Creature import Colors
from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    NormalStrategy, AggressiveStrategy, DefensiveStrategy, InvalidStrategyError
)
from ex2.BattleStrategy import BattleStrategy
from typing import List, Tuple


def battle(opponents: List[Tuple[CreatureFactory, BattleStrategy]]) -> None:

    creatures = [
        (factory.create_base(), strategy) for factory, strategy in opponents
    ]

    print(f"{Colors.tournament}*** Tournament ***{Colors.reset}")
    print(f"{len(opponents)} opponents involved")

    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature_a, strategy_a = creatures[i]
            creature_b, strategy_b = creatures[j]

            print(f"{Colors.battle}\n* Battle *{Colors.reset}")
            print(creature_a.describe())
            print(f"{Colors.dark_grey} vs.{Colors.reset}")
            print(creature_b.describe())

            print(f"{Colors.dark_grey} now fight!{Colors.reset}")
            try:
                for action in strategy_a.act(creature_a):
                    print(action)
                for action in strategy_b.act(creature_b):
                    print(action)
            except InvalidStrategyError as e:
                print(f"Battle error, aborting tournament: {e}")
                return


def main() -> None:
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()

    # Tournament 0
    print(f"{Colors.tournament_emphasis}Tournament 0 (basic){Colors.reset}")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    battle([
        (flame_factory, normal),
        (healing_factory, defensive),
    ])

    # Tournament 1
    print(f"{Colors.tournament_emphasis}\nTournament 1 (error){Colors.reset}")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    battle([
        (flame_factory, aggressive),
        (healing_factory, defensive),
    ])

    # Tournament 2
    print(f"{Colors.tournament_emphasis}\nTournament 2 (multiple){Colors.reset}")
    print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    battle([
        (aqua_factory, normal),
        (healing_factory, defensive),
        (transform_factory, aggressive),
    ])


if __name__ == "__main__":
    main()
