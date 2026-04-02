import alchemy


def main():
    print("=== Alembic 4 ===")
    try:
        print("Accessing the alchemy module using 'import alchemy'")
        print(f"Testing create_air: {alchemy.create_air()}")

        print("Now show that not all functions can be reached")
        print("This will raise an exception!")
        print(alchemy.create_earth())
    except AttributeError:
        print(
            "AttributeError: module 'alchemy' has no attribute 'create_earth'."
            " Did you mean: 'create_air'?"
        )


if __name__ == "__main__":
    main()
