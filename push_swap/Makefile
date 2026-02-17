# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/17 09:55:44 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c utils.c push_op.c swap_op.c rotate_op.c \
reverse_op.c parsing.c sorting.c norm.c sort_small.c\
helper.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
