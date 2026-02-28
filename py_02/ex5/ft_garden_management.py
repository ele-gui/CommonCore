class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class SunlightError(GardenError):
    pass


class GardenManager:
    def __init__(self):
        self.plants = []


    def add_plant(self, plant):
        if plant["name"] == "":
            raise PlantError("Error: Plant name cannot be empty!")
        else:
            self.plants = [*self.plants, plant]
            print(f"Added {plant['name']} successfully")


    def water_plants(self):
        print("\nWatering plants...")
        print("Opening watering system")
        try:
            for plant in self.plants:
                print(f"Watering {plant['name']} - success")
        finally:
            print("Closing watering system (cleanup)")


    def check_plant_health(self, plant) -> str:
        name = plant["name"]
        water_level = plant["water"]
        sunlight_hours = plant["sun"]
        
        if water_level > 10:
            raise WaterError(f"Error checking {name}: Water level {water_level} is too high (max 10)")
        elif water_level < 1:
            raise WaterError(f"Error checking {name}: Water level {water_level} is too low (min 1)")
        
        if sunlight_hours > 12:
            raise SunlightError(f"Error checking {name}: Sunlight hours {sunlight_hours} is too high (max 12)")
        elif sunlight_hours < 2:
            raise SunlightError(f"Error checking {name}: Sunlight hours {sunlight_hours} is too low (min 2)")
        
        return (f"{name} is healthy! (water: {water_level}, sun: {sunlight_hours})")




def test_garden_management():
    print("=== Garden Management System ===\n")

    garden = GardenManager()
    plants = [
        {"name": "tomato", "water": 5, "sun": 8},
        {"name": "lettuce", "water": 15, "sun": 4},
        {"name": "", "water": 5, "sun": 6}
    ]
    print("Adding plants to garden...")
    for plant in plants:
        try:
            garden.add_plant(plant)
        except PlantError as e:
            print(e)

    garden.water_plants()
        
    print("\nChecking plant health...")
    for plant in garden.plants:
        try:
            result = garden.check_plant_health(plant)
            print(result)
        except GardenError as e:
            print(e)


    print("\nTesting error recovery...")
    bad_list = {"name": "cactus", "water": 0, "sun": 20}

    try:
        raise GardenError("Not enough water in tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
        print("System recovered and continuing...")


    print("\nGarden management system test complete!")



if __name__ == "__main__":
    test_garden_management()