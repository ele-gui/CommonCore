*This project has been created as part of the 42 curriculum by elguiduc.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, producing the **shortest possible sequence of moves**.

The available operations are:

- `sa` / `sb` / `ss` — swap the first two elements of stack a / b / both
- `pa` / `pb` — push the top element from b to a, or from a to b
- `ra` / `rb` / `rr` — rotate stack a / b / both upward (first becomes last)
- `rra` / `rrb` / `rrr` — reverse rotate stack a / b / both (last becomes first)

The program takes a list of integers as arguments and prints the sequence of operations needed to sort stack `a` in ascending order.

---

## Instructions

### Compilation
```bash
make
```

This will produce the `push_swap` executable.

To also compile the **checker** bonus:
```bash
make bonus
```

### Execution
```bash
./push_swap 3 1 4 11 5 9 2 6
```

The program outputs the list of operations to stdout, one per line.

To verify correctness with the checker:
```bash
./push_swap 3 1 4 11 5 9 2 6 | ./checker 3 1 4 11 5 9 2 6
```

The checker will print `OK` if the sequence correctly sorts the stack, or `KO` otherwise.

### Cleanup
```bash
make clean    # remove object files
make fclean   # remove object files and executables
make re       # fclean + make
```

---

## Sorting Algorithm — Detailed Explanation

The algorithm selects a strategy based on the size of the input.

### `is_sorted`

Before doing anything, the program checks whether stack `a` is already sorted in ascending order. If it is, no operations are printed.

---

### `sort_2`

If there are exactly 2 elements and they are out of order, a single `sa` is enough.

---

### `sort_3`

Handles exactly 3 elements in stack `a`. All 6 permutations are covered by checking the relative order of the three values:

| Condition | Operations |
|---|---|
| `[b, a, c]` | `sa` |
| `[c, b, a]` | `sa` → `rra` |
| `[b, c, a]` | `ra` |
| `[a, c, b]` | `sa` → `ra` |
| `[c, a, b]` | `rra` |
| `[a, b, c]` | nothing |

---

### `sort_5`

Handles up to 5 elements. The strategy is:

1. Repeatedly find the **minimum** of stack `a` and push it to `b` using `pb`. To move the minimum to the top, use `ra` or `rra` depending on which side it is closer to (position vs. `size_a / 2`).
2. Once only 3 elements remain in `a`, call `sort_3`.
3. If stack `b` has 2 elements and they are in the wrong order, apply `rb` to put the smaller one on top.
4. Push both elements back to `a` with `pa`.

---

### `sort_20`

Handles up to 20 elements (used when `size_a > 5`). Uses normalized values (0-based ranks after coordinate compression):

1. Iteratively push elements with normalized value `0, 1, 2, ...` to `b` using `pb`, rotating `a` with `ra`/`rra` to bring each target to the top.
2. Once only 5 elements remain in `a`, call `sort_5`.
3. Push all remaining elements from `b` back to `a` with `pa`.

---

### `sort_general` — Chunk-based algorithm for large inputs

Used for inputs larger than 20 elements. It is composed of two phases: **push_to_b** and **push_to_a**.

#### Phase 1: `push_to_b` — Chunk division

The input is divided into **chunks** based on size:

| Input size | Number of chunks |
|---|---|
| ≤ 20 | 1 |
| ≤ 100 | 5 |
| ≤ 500 | 12 |

Each chunk represents a range of normalized values of size `original_size / chunk_count`.

The algorithm scans stack `a` continuously:

- If the top element's value is `≤ start` (i.e., it belongs to a "past" chunk boundary), push it to `b` and also do `rb` so it sinks to the bottom of `b`, keeping larger elements on top. Then increment `start`.
- If the top element's value is `≤ start + chunk.size` (i.e., it belongs to the current chunk), push it to `b` with `pb`. Then increment `start`.
- Otherwise, rotate `a` with `ra` to bring the next candidate to the top.

This approach fills `b` in a roughly descending order, chunked into sorted groups.

#### Phase 2: `push_to_a` — Greedy insertion

To bring everything back to `a` in sorted order:

1. Find the **index of the maximum** element in `b` using `find_max_index`.
2. If the maximum is already at the top (`index == 0`), push it to `a` with `pa`.
3. Otherwise, rotate `b` to bring the maximum to the top using the cheapest rotation:
   - If `index < size_b / 2`, use `rb` (forward rotation, `index` steps).
   - Otherwise, use `rrb` (reverse rotation, `size_b - index` steps).
4. Repeat until `b` is empty.

Since the maximum is always pushed first, `a` ends up sorted in ascending order from bottom to top.

---

## Bonus — `checker`

The bonus consists of implementing a **checker** program that:

1. Reads the same list of integers as `push_swap`.
2. Reads operations from **stdin**, one per line.
3. Applies each operation to the stacks.
4. At the end, checks whether stack `a` is sorted and stack `b` is empty.
5. Prints `OK` if both conditions are met, `KO` otherwise.

The checker uses the **same stack operations** (`sa`, `pa`, `ra`, `rra`, etc.) as `push_swap`, and it validates any instruction sequence — not just the one produced by `push_swap`.

Typical usage:
```bash
./push_swap 42 7 1 99 | ./checker 42 7 1 99
```

---

## Resources

### Documentation & References

- push_swap 42 subject 
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer) — useful to visually debug your move sequence
- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) — general background

### AI Usage

- **Algorithm design discussion**: exploring trade-offs between different sorting strategies (radix sort, chunk sort, greedy insertion) and understanding their complexity in terms of number of moves.
- **README writing**: polishing this documentation.
