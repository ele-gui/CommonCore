def value_error() -> int:
    return int("abc")


def division_error() -> float:
    return 10 / 0


def file_error() -> None:
    file = open("missing.txt")
    file.close()


def key_error() -> str:
    garden = {
            "Flower": "Rose",
            "Tree": "Oak"
        }
    return garden["missing_plant"]


def garden_operations() -> None:
    print("Testing ValueError...")
    try:
        value_error()
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    print("Testing ZeroDivisionError...")
    try:
        division_error()
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")

    print("Testing FileNotFoundError...")
    try:
        file_error()
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")

    print("Testing KeyError...")
    try:
        key_error()
    except KeyError as e:
        print(f"Caught KeyError: {e}\n")


def test_error_types() -> None:

    print("=== Garden Error Types Demo ===\n")

    garden_operations()

    print("Testing multiple errors together...")
    try:
        value_error()
        division_error()
        file_error()
        key_error()
    except (ValueError, ZeroDivisionError, FileNotFoundError, KeyError):
        print("Caught an error, but program continues!")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
