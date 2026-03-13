class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def plant_error() -> None:
    plant_status = input("Enter plant status: ")
    if plant_status != "healthy":
        raise PlantError(f"The tomato plant is {plant_status}!")
    else:
        print(f"The tomato plant is {plant_status}!")


def water_error() -> None:
    water_level = int(input("Enter water level: "))
    if water_level < 0:
        raise WaterError("Not enough water in the tank!")
    else:
        print(f"Water level {water_level} is perfect!")


def ft_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        plant_error()
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print("\nTesting WaterError...")
    try:
        water_error()
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print("\nTesting catching all garden errors...")
    for func in [plant_error, water_error]:
        try:
            func()
        except (PlantError) as e:
            print(f"Caught PlantError: {e}")
        except (WaterError) as e:
            print(f"Caught WaterError: {e}")

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    try:
        ft_custom_errors()
    except (WaterError, PlantError) as e:
        print(e)
