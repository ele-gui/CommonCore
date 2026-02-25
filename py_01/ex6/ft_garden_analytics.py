class GardenManager:
    def __init__(self) -> None:
        self.gardens =[]

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
                total += 1
            return total
        

        def count_by_type(self) -> int:
            counts = {"regular": 0, "flowering": 0, "prize flowers": 0}
            for plant in self.garden.plants:
                if type(plant) == PrizeFlower:
                    counts["prize flowers"] += 1
                elif type(plant) == FloweringPlant:
                    counts["flowering"] += 1
                else:
                    counts["regular"] += 1
            return counts


    #DA RIGUARDARE
    @staticmethod #decoratore che indica che il metodo è un metodo statico, non di istanza
    def validate_height(height) -> None:
        if (height < 0):
            raise ValueError("Height cannot be negative")
        else:
            print("Height validation test: True")


    def add_garden(self, garden) -> None:
        self.gardens.append(garden)


    @classmethod #decoratore che indica che il metodo è un metodo di classe, non di istanza
    def create_garden_network(cls) -> 'GardenManager':
        manager = cls() #cls = GardenManager, cls e' ereditabile
        alice = Garden("Alice")
        bob = Garden("Bob")

        alice.add_plant(Plant("Oak Tree", 100, 5))
        alice.add_plant(FloweringPlant("Rose", 26, 3, "red"))
        alice.add_plant(PrizeFlower("Sunflower", 51, 2, "yellow", 10))

        bob.add_plant(Plant("Pine Tree", 80, 4))
        bob.add_plant(FloweringPlant("Tulip", 15, 2, "pink"))

        manager.add_garden(alice)
        manager.add_garden(bob)
        return manager

class Garden:
    def __init__(self, owner) -> None:
        self.owner = owner
        self.plants = []
    
    def add_plant(self, plant) -> None:
        self.plants.append(plant)
        self.stats = GardenManager.GardenStats(self)
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_plants(self) -> None:
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            old_height = plant.height
            plant.grow()
            growth = plant.height - old_height
            print(f"{plant.name} grew {growth}cm")

    def report(self) -> None:
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            info = f"- {plant.name}: {plant.height}cm"
            if type(plant) == FloweringPlant:
                info += f", {plant.color} flowers (blooming)"
            if type(plant) == PrizeFlower:
                info += f", {plant.color} flowers (blooming), Prize points: {plant.prize})"
            print(info)

    def calculate_score(self) -> int:
        score = 0
        for plant in self.plants:
            score += plant.height
            if type(plant) == PrizeFlower:
                score += plant.prize
        return score

class Plant:
    def __init__(self, name, height, age) -> None:
        self.name = name
        self.height = height
        self.age = age

    def grow(self) -> None:
        self.height += 1

    def get_info(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days")


class FloweringPlant(Plant):
    def __init__(self, name, height, age, color) -> None:
        super().__init__(name, height, age)
        self.color = color


class PrizeFlower(FloweringPlant):
    def __init__(self, name, height, age, color, prize) -> None:
        super().__init__(name, height, age, color)
        self.prize = prize



def ft_garden_analytics() -> None:
    print("=== Garden Management System Demo ===\n")
    manager = GardenManager.create_garden_network()

    alice = manager.gardens[0]
    bob = manager.gardens[1]
    # alice.add_plant(Plant("Oak Tree", 100, 5))
    # alice.add_plant(FloweringPlant("Rose", 26, 3, "red"))
    # alice.add_plant(PrizeFlower("Sunflower", 51, 2, "yellow", 10))
    print()
    alice.grow_plants()
    bob.grow_plants()
    print()
    alice.report()
    print()

    stats = GardenManager.GardenStats(alice)
    print(f"Plants added: {stats.count_plants()}, Total growth: {stats.total_growth()}cm")

    counts = stats.count_by_type()
    print(f"Plant types: {counts['regular']} regular, {counts['flowering']} flowering, {counts['prize flowers']} prize flowers\n")


    GardenManager.validate_height(alice.plants[0].height)
    print(f"Garden scores - {alice.owner}: {alice.calculate_score()}, {bob.owner}: {bob.calculate_score()}")

    count = 0
    for garden in manager.gardens:
        count += 1
    print(f"Total gardens managed: {count}")




if __name__ == "__main__":
    ft_garden_analytics()