*This project has been created as part of the 42 curriculum by
elguiduc.*

# ft_printf

## Description

This project is a recreation of the function `printf()` of the `<stdio.h>` library.
The purpose of this project is to learn how to use variadic functions in C
and handle the following convertions:
-	%c Prints a single character.
-	%s Prints a string (as defined by the common C convention).
-	%p The void * pointer argument has to be printed in hexadecimal format.
-	%d Prints a decimal (base 10) number.
-	%i Prints an integer in base 10.
-	%u Prints an unsigned decimal (base 10) number.
-	%x Prints a number in hexadecimal (base 16) lowercase format.
-	%X Prints a number in hexadecimal (base 16) uppercase format.
-	%% Prints a percent sign.


### Key goals:

-   Recreate the function printf()
-   Handle the following conversions: cspdiuxX%


## Instructions

### Requirements

-   Compiler: cc (the Makefile uses cc).
-   Compile flags: -Wall -Wextra -Werror.
-   All sources must be at the repository root.
-   No global variables; helper functions should be static when
    appropriate.
-   Use ar to create the static library.
	Using the libtool command is forbidden

### Build

    # build the mandatory library
    make

    # remove object files
    make clean

    # remove object files and libraries (full clean)
    make fclean

    # full rebuild
    make re

## Makefile behaviour notes

-   `make` builds the mandatory part and creates `libftprintf.a`.
-   `make clean` removes `.o` files.
-   `make fclean` removes `.o` files and `libftprintf.a`.
-   `make re` performs `fclean` followed by `make`.

## Usage

After make, the static library libftprintf.a will be created at the repository
root.
To link it into a program:

    cc your_program.c ./libftprintf.a -o your_program


## Library overview (short)

### Print char and string

`ft_print_char`, `ft_print_percent`, `ft_print_str`.

### Print numbers (%i, %d, %u)

`ft_print_dec_int`, `ft_print_uint`.

### Print pointers

`ft_print_ptr`.

### Print hex (uppercase and lowercase)

`ft_print_hex_up`, `ft_print_hex_low`.

### Print function

`ft_print_call`, `ft_printf`.

## File structure

    .
    ├── Makefile
    ├── libftprintf.h
    ├── ft_*.c          # all function sources (mandatory)
    └── README.md

## How AI was used

AI was used only to generate tests for the functions.

## Resources

-   The 42 subject PDF for Libftprintf.