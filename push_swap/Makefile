# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/12 22:16:26 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

#AR = ar rcs

RM = rm -f

PRINTF_DIR = ft_printf
FT_PRINTF = ft_printf/libftprintf.a

SRCS = main.c utils.c push_op.c print_stack.c swap_op.c rotate_op.c reverse_op.c parsing.c sorting.c norm.c \
sort_small.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C  $(PRINTF_DIR)
	cp $(FT_PRINTF) $(NAME)
	$(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re