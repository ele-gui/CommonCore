class Plant:
    def __init__(self, name, height, age) -> None:
        self.name = name
        self.height = height
        self.age = age

    def    get_info(self) -> str:
        return (f"Created: {self.name} ({self.height}cm, {self.age} days)")


def ft_plant_factory():
    print("=== Plant Factory Output ===")

    plants = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 120),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
    ]

    for i in range(5):
        print(plants[i].get_info())
    print()
    print(f"Total plants created: {i + 1}")


if __name__ == "__main__":
    ft_plant_factory()
