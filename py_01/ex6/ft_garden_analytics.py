class GardenManager:
    def __init__(self) -> None:
        self.gardens = []

    def validate_height(height) -> None:
        if height < 0:
            print("Invalid height")
        else:
            print("Height validation test: True")

    def add_garden(self, garden) -> None:
        self.gardens = [*self.gardens, garden]

    @classmethod
    def create_garden_network(cls) -> 'GardenManager':
        manager = cls()
        alice = Garden("Alice")
        bob = Garden("Bob")

        plants = [
            Plant("Oak Tree", 100),
            FloweringPlant("Rose", 25, "red"),
            PrizeFlower("Sunflower", 50, "yellow", 10)
        ]

        for plant in plants:
            alice.add_plant(plant)

        manager.add_garden(alice)
        manager.add_garden(bob)
        return manager

    class GardenStats:
        def __init__(self, garden) -> None:
            self.garden = garden

        def count_plants(self) -> int:
            count = 0
            for plant in self.garden.plants:
                count += 1
            return count

        def total_growth(self) -> int:
            total = 0
            for plant in self.garden.plants:
                total += plant.last_growth
            return total

        def count_by_type(self) -> int:
            counts = {"regular": 0, "flowering": 0, "prize flowers": 0}
            for plant in self.garden.plants:
                if type(plant) is PrizeFlower:
                    counts["prize flowers"] += 1
                elif type(plant) is FloweringPlant:
                    counts["flowering"] += 1
                else:
                    counts["regular"] += 1
            return counts


class Garden:
    def __init__(self, owner) -> None:
        self.owner = owner
        self. plants = []

    def add_plant(self, plant) -> None:
        self.plants = [*self.plants, plant]
        self.stats = GardenManager.GardenStats(self)
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_plants(self) -> None:
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            old_height = plant.height
            plant.grow()
            growth = plant.height - old_height
            plant.last_growth = plant.height - old_height
            print(f"{plant.name} grew {growth}cm")
        print()

    def report(self) -> None:
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            info = f"- {plant.name}: {plant.height}cm"
            if type(plant) is FloweringPlant:
                info += f", {plant.color} flowers (blooming)"
            if type(plant) is PrizeFlower:
                info += f", {plant.color} flowers (blooming), "
                info += f"Prize points {plant.prize}"
            print(info)
        print()

    def calculate_score(self) -> int:
        score = 0
        for plant in self.plants:
            score += plant.height
            if type(plant) is PrizeFlower:
                score += plant.prize
        return score


class Plant:
    def __init__(self, name, height) -> None:
        self.name = name
        self.height = height

    def grow(self) -> None:
        self.height += 1

    def get_info(self) -> None:
        print(f"{self.name}: {self.height}cm")


class FloweringPlant(Plant):
    def __init__(self, name, height, color) -> None:
        super().__init__(name, height)
        self.color = color


class PrizeFlower(FloweringPlant):
    def __init__(self, name, height, color, prize) -> None:
        super().__init__(name, height, color)
        self.prize = prize


def ft_garden_analytics() -> None:
    print("=== Garden Management System Demo ===\n")
    manager = GardenManager.create_garden_network()
    alice = manager.gardens[0]
    bob = manager.gardens[1]

    print()
    alice.grow_plants()
    # bob.grow_plants()
    alice.report()

    stats = GardenManager.GardenStats(alice)
    print(
        f"Plants added: {stats.count_plants()}, "
        f"Total growth: {stats.total_growth()}cm"
    )

    counts = stats.count_by_type()
    print(
        f"Plant types: {counts['regular']} regular, {counts['flowering']} "
        f"flowering, {counts['prize flowers']} prize flowers\n"
    )

    GardenManager.validate_height(alice.plants[0].height)
    print(
        f"Garden scores - {alice.owner}: {alice.calculate_score()}, "
        f"{bob.owner}: {bob.calculate_score()}"
    )

    count = 0
    for garden in manager.gardens:
        count += 1
    print(f"Total gardens managed: {count}")


if __name__ == "__main__":
    ft_garden_analytics()
