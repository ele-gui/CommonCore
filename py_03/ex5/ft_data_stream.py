from typing import Generator
import time


def fibonacci_stream() -> Generator[int, None, None]:
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


def primes_stream() -> Generator[int, None, None]:
    def is_prime(n):
        if n <= 1:
            return False
        for i in range(2, int(n / 2) + 1):
            if n % i == 0:
                return False
        return True

    num = 2
    while True:
        if is_prime(num):
            yield num
        num += 1


class Player:
    def __init__(self, name, level):
        self.name = name
        self.level = level


def game_data_stream(players: list[Player]) -> Generator[str, None, None]:
    actions = [
        "killed a monster",
        "found treasure",
        "leveled up",
        "fell on the ground",
        "got drunk",
        "went swimming"
    ]
    i = 0
    for i in range(1000):
        player = players[(i) % len(players)]  # cicla i players
        action = actions[(i) % len(actions)]

        yield f"Event {i + 1}: Player {player.name} " \
            f"(level {player.level}) {action}"


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    print("Processing 1000 game events...")
    players = [
        Player("alice", 5),
        Player("bob", 12),
        Player("charlie", 8),
        Player("dina", 20),
        Player("ellie", 13)
    ]

    start = time.time()  # to calculate processing time
    total = 0
    interesting_events = [0, 0, 0]
    gen = game_data_stream(players)
    first_1000 = [next(gen) for _ in range(1000)]
    gen_str = ""
    for n in first_1000:
        gen_str = f"{n}\n"
        print(gen_str, end="")
        total += 1
        if ("killed a monster" in n):
            interesting_events[0] += 1
        elif ("found treasure" in n):
            interesting_events[1] += 1
        elif ("leveled up" in n):
            interesting_events[2] += 1

    high_level_players = 0
    for player in players:
        if player.level >= 10:
            high_level_players += 1

    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {total}")
    print(f"High-level players (10+): {high_level_players}")  # OK
    print(f"Treasure events: {interesting_events[1]}")  # OK
    print(f"Level-up events: {interesting_events[2]}")  # OK

    end = time.time()
    processing_time = end - start
    print("\nMemory usage: Constant (streaming)")
    print(f"Processing time: {processing_time:.3f} seconds")

    print("\n=== Generator Demonstration ===")
    fib = fibonacci_stream()
    first_10_fib = [next(fib) for _ in range(10)]
    fib_str = ""
    for n in first_10_fib:
        fib_str += f"{n}, "
    print(f"Fibonacci sequence (first 10): {fib_str[:-2]}")

    prime_gen = primes_stream()
    first_5_primes = [next(prime_gen) for _ in range(5)]
    prime_str = ""
    for n in first_5_primes:
        prime_str += f"{n}, "
    print(f"Prime numbers (first 5): {prime_str[:-2]}")
