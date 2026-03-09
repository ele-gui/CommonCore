from typing import Generator


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



def game_data_stream() -> Generator[str, None, None]:
    for i in range(1, 1001):
        yield f"Event {i}: Player action at timestamp {i * 0.5:.2f}s"


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    print("Processing 1000 game events...")
    # for event in game_data_stream():
    #     print(event)

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