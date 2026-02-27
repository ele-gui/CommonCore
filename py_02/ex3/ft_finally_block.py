def water_plants(plant_list):
    print("Opening watering system")

    for plant in plant_list:
        if plant in plant_list:
            print(f"Watering {plant}")
        else:
            print("Error: Cannot water None - invalid plant!")




def test_watering_system():
    print("Testing normal watering...")
    water_plants()



def ft_finally_block():
    print("=== Garden Watering System ===")
    plant_list = [
        "tomato",
        "lettuce",
        "carrots"
    ]



if __name__ == "__main__":
    ft_finally_block()