def check_temperature(temp_str) -> int:
    try:
        temp_value = int(temp_str)
    except ValueError:
        raise ValueError(f"Error: '{temp_str}' is not a valid number")

    if temp_value < 0:
        raise ValueError(
            f"Error: "
            f"{temp_str}°C is too cold for plants (min 0°C)"
        )

    if temp_value > 40:
        raise ValueError(
            f"Error: "
            f"{temp_str}°C is too hot for plants (max 40°C)"
        )

    return temp_value


def test_temperature_input() -> None:
    temperatures = [
        "25",
        "abc",
        "100",
        "-50"
    ]
    print("=== Garden Temperature Checker ===")

    for temp_str in temperatures:
        print(f"\nTesting temperature: {temp_str}")
        try:
            res = check_temperature(temp_str)
            print(f"Temperature {res}°C is perfect for plants!")
        except ValueError as e:
            print(e)

    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
