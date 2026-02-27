class GardenError:
    pass



class PlantError(GardenError):
    pass



class WaterError(GardenError):
    pass





def ft_custom_errors():
    print("=== Custom Garden Errors Demo ===")

    try:
        print("Testing WaterError...")
        water_level = int(input())
    except water_level < 0 as e:
        raise WaterError("Caught WaterError: Not enough water in the tank!")
    
    try:
        print("Testing PlantError...")
        plant_status = input()
    except plant_status != "healthy" as e:
        raise PlantError(f"Caught PlantError: The plant is {plant_status}!")



if __name__ == "__main__":

    try:
        ft_custom_errors()
    except WaterError as e:
        print(e)
    except PlantError as e:
        print(e)





