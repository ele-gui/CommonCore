import sys


def parse_input(str) -> dict:
    inventory = {}
    for char in str:
        name = ""
        quantity = ""
        found = False

        for c in char:
            if c == ":":
                found = True
            elif not found:
                name += c
            else:
                quantity += c

        # inventory.update({name: int(quantity)}) #non posso isare int()
        inventory.update({name: int(quantity)})  # senza int non funziona

    return inventory


def find_max(d) -> tuple:
    max_key = ""
    max_value = -1
    for key, value in d.items():
        if max_value == -1 or value > max_value:
            max_value = value
            max_key = key
    return max_key, max_value


def find_min(d) -> tuple:
    min_key = ""
    min_value = -1
    for key, value in d.items():
        if min_value == -1 or value < min_value:
            min_value = value
            min_key = key
    return min_key, min_value


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = parse_input(sys.argv[1:])

    total = 0
    for value in inventory.values():
        total += value
    print(f"Total items in inventory: {total}")
    print(f"Unique item types: {len(inventory)}")

    print("\n=== Current Inventory ===")
    for key, value in inventory.items():
        percent = (value * 100) / total
        print(f"{key}: {value} units ({percent:.1f}%)")

    print("\n=== Inventory Statistics ===")
    most_name, most_value = find_max(inventory)
    least_name, least_value = find_min(inventory)

    print(f"Most abundant: {most_name} ({most_value} units)")
    print(f"Least abundant: {least_name} ({least_value} units)")

    print("\n=== Item Categories ===")
    moderate = dict()
    scarce = dict()

    for key, value in inventory.items():
        if value >= 5:
            moderate.update({key: value})
        else:
            scarce.update({key: value})

    print(f"Moderate: {moderate}")
    print(f"Scarce: {scarce}")

    print("\n=== Management Suggestions ===")
    restock = ""
    first = True
    for key, value in inventory.items():
        if value <= 1:
            if not first:
                restock += ", "
            restock += key
            first = False
    print(f"Restock needed: {restock}")

    print("\n=== Dictionary Properties Demo ===")
    key_list = ""
    value_list = ""
    first = True
    for key, value in inventory.items():
        if not first:
            key_list += ", "
            value_list += ", "
        key_list += key
        value_list += str(value)
        first = False

    print(f"Dictionary keys: {key_list}")
    print(f"Dictionary values: {value_list}")

    print(
        "Sample lookup - 'sword' in inventory:",
        inventory.get("sword") is not None
    )
