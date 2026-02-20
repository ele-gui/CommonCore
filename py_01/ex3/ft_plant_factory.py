class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def    creation(self):
        return (f"Created: {self.name} ({self.height}cm, {self.age} days)")


def ft_plant_factory():
    print("=== Plant Factory Output ===")
    p1 = Plant("Rose", 25, 30)
    p2 = Plant("Oak", 200, 365)
    p3 = Plant("Cactus", 5, 90)
    p4 = Plant("Sunflower", 80, 45)
    p5 = Plant("Fern", 15, 120)

    plants = [p1, p2, p3, p4, p5]
    for i in range(5):
        print(plants[i].creation())
    print()
    print(f"Total plants created: {i + 1}")


if __name__ == "__main__":
    ft_plant_factory()
