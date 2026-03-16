if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")

    alice = {
        "first_kill",
        "level_10",
        "treasure_hunter",
        "speed_demon"
    }

    bob = {
        "first_kill",
        "level_10",
        "boss_slayer",
        "collector"
    }

    charlie = {
        "level_10",
        "treasure_hunter",
        "boss_slayer",
        "speed_demon",
        "perfectionist",
    }
    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}")

    print("\n=== Achievement Analytics ===")
    unique = set.union(alice, bob, charlie)
    print(f"All unique achievements: {unique}")
    print(f"Total unique achievements: {len(unique)}")

    print(f"\nCommon to all players: {set.intersection(alice, bob, charlie)}")
    only_alice = alice.difference(bob, charlie)
    only_bob = bob.difference(alice, charlie)
    only_charlie = charlie.difference(alice, bob)
    rare = set.union(only_alice, only_bob, only_charlie)
    print(f"Rare achievements (1 player): {rare}")

    print(f"\nAlice vs Bob common: {alice.intersection(bob)}")
    print(f"Alice unique: {alice.difference(bob)}")
    print(f"Bob unique: {bob.difference(alice)}")
