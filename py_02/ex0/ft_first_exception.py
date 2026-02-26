def error_temperature(temp_str):
    print(f"Testing temperature: {temp_str}")
    if temp_str <= 0:
        raise Exception(f"Error: {temp_str}°C is too cold for plants (min 0°C)\n")
    
    elif temp_str >= 40:
        raise Exception(f"Error: {temp_str}°C is too hot for plants (max 40°C)\n")
    
    else:
        raise Exception(f"Temperature {temp_str}°C is perfect for plants!\n")


def check_temperature():
    temperatures = [
        "25",
        "abc",
        "100",
        "-50"
    ]
    print("=== Garden Temperature Checker ===\n")
    for temperature in temperatures:
        try:
            temp_value = int(temperature)
            error_temperature(temp_value)
        except ValueError as e:
            print(f"Testing temperature: {temperature}")
            print(f"Error: '{temperature}' is not a valid number\n")
        except Exception as e:
            print(e)
    print("All tests completed - program didn't crash!")

if __name__ == "__main__":
    check_temperature()