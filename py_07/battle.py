from ex0 import FlameFactory, AquaFactory
from ex0.CreatureFactory import CreatureFactory


def test_creature(factory: CreatureFactory) -> None:
    print("Testing factory")

    # factory = FlameFactory()
    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())

    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())
    print()


def creature_fight(factory_a: CreatureFactory, factory_b: CreatureFactory):
    print("Testing battle")
    creature_a = factory_a.create_base()
    creature_b = factory_b.create_base()
    print(creature_a.describe())
    print("vs.")
    print(creature_b.describe())
    print(creature_a.attack())
    print(creature_b.attack())


def main() -> None:

    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    test_creature(flame_factory)
    test_creature(aqua_factory)

    creature_fight(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()
