# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/01/29 14:43:11 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

LIBFT_DIR = libft
LIBFT = libft/libft.a

PRINTF_DIR = ft_printf
FT_PRINTF = ft_printf/libftprintf.a

SRCS = push_op.c reverse_op.c rotate_op.c swap_op.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) $(PRINTF_DIR)
	cp $(LIBFT) $(FT_PRINTF) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re