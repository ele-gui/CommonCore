def water_plants(plant_list):
    print("Opening watering system")

    valid_list =  [
        "tomato",
        "lettuce",
        "carrots"
    ]

    for plant in plant_list:
        if plant not in valid_list:
            raise ValueError(f"Cannot water {plant} - invalid plant!")
        print(f"Watering {plant}")


def test_watering_system():
    print("=== Garden Watering System ===\n")
    plant_list = [
        "tomato",
        "lettuce",
        "carrots"
    ]

    print("Testing normal watering...")
    try:
        water_plants(plant_list)
    except ValueError as e:
        print(f"Error: {e}")
    finally:
        print("Closing watering system (cleanup)")
        print("Watering completed successfully!\n")


    print("Testing with error...")
    error_list = [
        "tomato",
        "oak",
        "lettuce"
    ]


    try:
        water_plants(error_list)
    except ValueError as e:
        print(f"Error: {e}")
    finally:
        print("Closing watering system (cleanup)\n")


    print("Cleanup always happens, even with errors!")



if __name__ == "__main__":
    test_watering_system()
