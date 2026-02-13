# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/13 14:25:19 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

PRINTF_DIR = ft_printf
FT_PRINTF = ft_printf/libftprintf.a

SRCS = main.c utils.c push_op.c print_stack.c swap_op.c rotate_op.c reverse_op.c parsing.c sorting.c norm.c \
sort_small.c cost_chunk.c

OBJS = $(SRCS:.c=.o)

all: push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR) all
	$(AR) $(NAME) $(OBJS)

push_swap: $(OBJS) $(NAME) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o push_swap $(OBJS) $(FT_PRINTF)

clean:
	$(RM) $(OBJS) push_swap
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re