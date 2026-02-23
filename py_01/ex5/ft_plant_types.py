class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age
        

#classe figlia. esedita da plant e aggiunge caratteristiche proprie dei fiori
class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age) #prende name, height, age da Plant
        self.color = color #aggiunga qulcosa di suo
        
    def bloom(self):
        print(f"{self.name} is blooming beautifully!")
        

class Tree(Plant):
    def __init__(self, name, height, age,trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
    
    def produce_shade(self):
        print(f"{self.name} provides 78 square meters of shade")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


def ft_plant_types():
    print("=== Garden Plant Types ===")
    print()
    p1 = Flower("Rose", 25, 30, "red")
    p2 = Flower("Tulip", 15, 20, "yellow")

    print(f"{p1.name} (Flower): {p1.height}cm, {p1.age} days, {p1.color} color")
    p1.bloom()
    print()
    print(f"{p2.name} (Flower): {p2.height}cm, {p2.age} days, {p2.color} color")
    p2.bloom()
    print()

    p3 = Tree("Oak", 500, 1825, 50)
    p4 = Tree("Maple", 475, 9125, 30)

    print(f"{p3.name} (Tree): {p1.height}cm, {p1.age} days, {p3.trunk_diameter}cm diameter")
    p3.produce_shade()
    print()
    print(f"{p4.name} (Tree): {p2.height}cm, {p2.age} days, {p4.trunk_diameter}cm diameter")
    p4.produce_shade()
    print()

    p5 = Vegetable("Tomato", 80, 90, "summer", "C")
    print(f"{p5.name} (Vegetable): {p5.height}cm, {p5.age} days, {p5.harvest_season} harvest")
    print(f"{p5.name} is rich in vitamin {p5.nutritional_value}")

if __name__ == "__main__":
    ft_plant_types()