class Plant:
    def __init__(self, name, height, age) -> None:
        self.name = name
        self.height = height
        self.age = age
        

#class figlia. eredita da plant e aggiunge caratteristiche proprie dei fiori
class Flower(Plant):
    def __init__(self, name, height, age, color) -> None:
        super().__init__(name, height, age) #prende name, height, age da Plant
        self.color = color #aggiunga qulcosa di suo
        
    def bloom(self) -> None:
        print(f"{self.name} is blooming beautifully!")
        

class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
    
    def produce_shade(self) -> None:
        crown_diameter = self.height / 100 * 2
        radius = crown_diameter / 2
        area = int(3.14 * radius ** 2)
        print(f"{self.name} provides {area} square meters of shade")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


def ft_plant_types() -> None:
    print("=== Garden Plant Types ===")
    print()
    plants = [
        Flower("Rose", 25, 30, "red"),
        Flower("Tulip", 15, 20, "yellow"),
        Tree("Oak", 500, 1825, 50),
        Tree("Maple", 475, 9125, 30),
        Vegetable("Tomato", 80, 90, "summer", "C"),
        Vegetable("Carrot", 20, 15, "spring", "A")
    ]
    for plant in plants:
        if type(plant) == Flower:
            print(f"{plant.name} (Flower): {plant.height}cm, {plant.age} days, {plant.color} color")
            plant.bloom()
        elif type(plant) == Tree:
            print(f"{plant.name} (Tree): {plant.height}cm, {plant.age} days, {plant.trunk_diameter}cm diameter")
            plant.produce_shade()
        else:
            print(f"{plant.name} (Vegetable): {plant.height}cm, {plant.age} days, {plant.harvest_season} harvest")
            print(f"{plant.name} is rich in vitamin {plant.nutritional_value}")
        print()


if __name__ == "__main__":
    ft_plant_types()