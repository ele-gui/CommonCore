import math


def create_position(x, y, z):
    return tuple((x, y, z))


def calculate_dist(pos1, pos2):
    x1, y1, z1 = pos1
    x2, y2, z2 = pos2
    dist = math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2)
    return float(dist)


def parse_coordinates(coord):
    try:
        parsed = coord.split(',')
        return tuple(int(p) for p in parsed)
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        print(f"Error details - Type: ValueError, Args: {e.args}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")

    origin = create_position(0, 0, 0)
    position1 = create_position(10, 20, 5)
    print(f"Position created: {position1}")
    dist1 = calculate_dist(origin, position1)
    print(f"Position between {origin} and {position1}: {dist1:.2f}\n")

    not_parsed = "3,4,0"
    print(f'Parsing coordinates: "{not_parsed}"')
    parsed = parse_coordinates(not_parsed)
    print(f"Parsed position: {parsed}")
    dist2 = calculate_dist(origin, parsed)
    print(f"Position between {origin} and {parsed}: {dist2}\n")

    invalid_str = "abc,def,ghi"
    print(f'Parsing invalid coordinates: "{invalid_str}"')
    parse_coordinates(invalid_str)

    print("\nUnpacking demonstration:")
    x, y, z = parsed
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates X={x}, Y={y}, Z={z}")
