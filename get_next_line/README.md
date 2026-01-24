*This project has been created as part of the 42 curriculum by
elguiduc.*

# get_next_line

## Description

The aim of this project is to build a function that lets you read from a file descriptor one line at a time. The return value is the line that was read, if there is nothing left to read or an error occours, the return value should be NULL.

### Key goals

- Learn how to use static variables.

## Instructions

### Requirements

-   Compiler: cc.
-   Compile flags: -Wall -Wextra -Werror.
-   All sources must be at the repository root.
-   No global variables; helper functions should be static when
    appropriate.
-   Using lseek() is forbidden.
	Using the libtool command is forbidden.

## Functions overview (short)

### get_next_line_utils

`ft_memmove`, `ft_strchr`, `ft_strlen`, `ft_strjoin`, `ft_strdup`.

### get_next_line_

`read_to_string`, `extract_line`, `clean_string`, `get_next_line`.

## Bonus part

The function should handle multiple file descriptor at the same time. For example, if you are reading from file descriptors 3, 4, and 5, you should be able
to read from a different file descriptor with each call, without losing track of the
reading state of each file descriptor or returning a line from a different one.
The get_next_line() function must use only one static variable.

## File structure

    .
    ├── get_next_line.h
    ├── get_next_line.c
	├── get_next_line_utils.c
	├── get_next_line_bonus.h
    ├── get_next_line_bonus.c
	├── get_next_line_utils_bonus.c
    └── README.md

## How AI was used

AI was used only to generate tests for the functions.

## Resources

-   The 42 subject PDF for gwt_next_line.