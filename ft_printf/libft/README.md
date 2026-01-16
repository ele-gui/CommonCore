*This project has been created as part of the 42 curriculum by
elguiduc.*

# libft

## Description

libft is a small C library that reimplements a selection of standard
libc functions and several commonly useful utility functions. The
purpose of this project is to deepen your understanding of low-level C
functions (memory and string manipulation, character tests and linked-list utilities) by implementing them from scratch.
The library is intended as a personal toolbox for future school
projects.

### Key goals:

-   Reimplement selected libc-like functions with the ft\_ prefix.
-   Provide additional utility functions (string management, itoa,
    split, etc.).
-   Implement a simple singly linked list API.
-   Respect the 42 Norm and project rules.

(For a short list of implemented functions, see *Library overview*
below.)

## Instructions

### Requirements

-   Compiler: cc (the Makefile uses cc).
-   Compile flags: -Wall -Wextra -Werror.
-   All sources must be at the repository root.
-   No global variables; helper functions should be static when
    appropriate.
-   Use ar to create the static library.

### Build

    # build the mandatory library
    make

    # build the library including bonus functions
    make bonus

    # remove object files
    make clean

    # remove object files and libraries (full clean)
    make fclean

    # full rebuild
    make re

## Usage

After make, the static library libft.a will be created at the repository
root.\
To link it into a program:

    cc your_program.c ./libft.a -o your_program

If you used make bonus (and your Makefile is implemented to append bonus
objects), libft.a will include both mandatory and bonus functions.

## Library overview (short)

### Part 1 --- libc-like functions

`ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`,
`ft_strlcpy`,\
`ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`,
`ft_strncmp`,\
`ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`,
`ft_strdup`, etc.

### Part 2 --- Additional utilities

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`,\
`ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`,\
`ft_putendl_fd`, `ft_putnbr_fd`

### Part 3 --- Linked list

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`,\
`ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`,
`ft_lstmap`

## File structure

    .
    ├── Makefile
    ├── libft.h
    ├── ft_*.c          # all function sources (mandatory)
    ├── ft_*_bonus.c    # bonus sources (if any)
    └── README.md

## Makefile behaviour notes

-   `make` builds the mandatory part and creates `libft.a`.
-   `make bonus` appends the bonus object files to the library (or
    otherwise produces the bonus artifact).
-   `make clean` removes `.o` files.
-   `make fclean` removes `.o` files and `libft.a` (and marker files
    like `.bonus` if your Makefile creates them).
-   `make re` performs `fclean` followed by `make`.

## How AI was used

AI was used only to generate tests for the functions and to write this README

## Resources

-   C standard library man pages (`man 3 <function>`).
-   The 42 subject PDF for Libft.
-   `nm`, `readelf`, `ar` man pages for static library inspection.


Compile linking to libft.a to verify behavior.
