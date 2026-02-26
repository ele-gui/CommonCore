class Plant:
    def __init__(self, name, height, age) -> None:
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> str:
        return (f"{self.name}: {self.height}cm, {self.age} days old")


def ft_garden_data() -> None:
    print("=== Garden Plant Registry ===")
    p1 = Plant("Rose", 25, 30)
    p2 = Plant("Sunflower", 80, 45)
    p3 = Plant("Cactus", 15, 120)

    plants = [p1, p2, p3]
    for i in range(0, 3):
        print(plants[i].get_info())


if __name__ == "__main__":
    ft_garden_data()
