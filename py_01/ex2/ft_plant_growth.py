class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def grow(self):
        self.height += 1

    def age_one_day(self):
        self.age += 1
        self.grow()

    def get_info(self):
        return (f"{self.name}: {self.height}cm, {self.age} days old")



def ft_plant_growth():
    plants = [
        Plant("Rose", 25, 30),
        Plant("Sunflower", 80, 45),
        Plant("Cactus", 15, 120)
    ]
    for plant in plants:
        print("=== Day 1 ===")
        print(plant.get_info())
        height_before = plant.height
        for day in range(6):
            plant.age_one_day()
        print("=== Day 7 ===")
        print(plant.get_info())
        growth = plant.height - height_before
        print(f"Growth this week: +{growth}cm")
        print()

"""def ft_plant_growth():
	print("=== Day 1 ===")
	p1 = Plant("Rose", 25, 30)
	print(p1.get_info())
	height_before = p1.height

	print("=== Day 7 ===")
	for day in range(0, 6):
		p1.age_one_day()
	print(p1.get_info())
	height_after = p1.height

	growth = height_after - height_before
	print(f"Growth this week: +{growth}cm")"""

if __name__ == "__main__":
	ft_plant_growth()
