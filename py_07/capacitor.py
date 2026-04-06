from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex0.CreatureFactory import CreatureFactory


def test_factory(factory: CreatureFactory) -> None:
    print("Testing factory")

    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())

    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())
    print()


def test_healing(factory: HealingCreatureFactory):
    print("Testing Creature with healing capability")
    print(" base:")
    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())
    print(base_creature.heal())
    # print(base_creature.heal("Flameling"))

    print(" evolved:")
    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())
    print(evolved_creature.heal())
    print()


def test_transform(factory: TransformCreatureFactory) -> None:
    print("Testing Creature with transform capability")
    print(" base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    print(" evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


def main() -> None:
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    # test_factory(healing_factory)
    # test_factory(transform_factory)
    test_healing(healing_factory)
    test_transform(transform_factory)


if __name__ == "__main__":
    main()
