# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/19 17:49:32 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c utils.c push_op.c swap_op.c rotate_op.c \
reverse_op.c parsing.c sorting.c norm.c sort_small.c push_b.c \
push_a.c

SRCS_BONUS = bonus/checker.c bonus/utils.c bonus/push_op.c bonus/swap_op.c \
bonus/rotate_op.c bonus/reverse_op.c bonus/parsing.c bonus/sorting.c \
bonus/norm.c bonus/sort_small.c bonus/push_b.c \
bonus/push_a.c bonus/get_next_line.c bonus/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFTPRINTF) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C ft_printf

re: fclean all bonus

.PHONY: all bonus clean fclean re
