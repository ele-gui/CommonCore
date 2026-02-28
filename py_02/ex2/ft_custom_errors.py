class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def plant_error():
    plant_status = input("Enter plant status: ")
    if plant_status != "healthy":
        raise PlantError(f"Caught PlantError: The tomato plant is {plant_status}!\n")


def water_error():
    water_level = int(input("Enter water level: "))
    if water_level < 0:
        raise WaterError("Caught WaterError: Not enough water in the tank!\n")


def ft_custom_errors():
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        plant_error()
    except PlantError as e:
        print(e)

    print("Testing WaterError...")
    try:
        water_error()
    except WaterError as e:
        print(e)
    
    print("Testing catching all garden errors...")
    for func in [plant_error, water_error]:
        try:
            func()
        except (PlantError, WaterError) as e:
            print(e)
    
    print("All custom error types work correctly!")


if __name__ == "__main__":

    try:
        ft_custom_errors()
    except (WaterError, PlantError) as e:
        print(e)
