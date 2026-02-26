def check_temperature(temp_str) -> int:
    try:
        temp_value = int(temp_str)
    except ValueError:
        raise ValueError(f"Error: '{temp_str}' is not a valid number\n")
    
    if temp_value < 0:
        raise ValueError(f"Error: {temp_str}°C is too cold for plants (min 0°C)\n")
    
    if temp_value > 40:
        raise ValueError(f"Error: {temp_str}°C is too hot for plants (max 40°C)\n")
    
    return temp_value


def test_temperature():
    temperatures = [
        "25",
        "abc",
        "100",
        "-50"
    ]
    print("=== Garden Temperature Checker ===\n")

    for temp_str in temperatures:
        print(f"Testing temperature: {temp_str}")
        try:
            res = check_temperature(temp_str)
            print(f"Temperature {res}°C is perfect for plants!\n")
        except ValueError as e:
            print(e)

    print("All tests completed - program didn't crash!")

if __name__ == "__main__":
    test_temperature()