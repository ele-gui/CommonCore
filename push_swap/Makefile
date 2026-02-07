# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:13:43 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/07 15:08:04 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME =	push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

PRINTF_DIR = ft_printf
FT_PRINTF = ft_printf/libftprintf.a

SRCS = main.c push_op.c print_stack.c #reverse_op.c rotate_op.c swap_op.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C  $(PRINTF_DIR)
	cp $(FT_PRINTF) $(NAME)
	$(AR) $(NAME) $(OBJS)

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




# NAME =	push_swap.a

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# AR = ar rcs

# RM = rm -f

# LIBFT_DIR = libft
# LIBFT = ft_printf/libft/libft.a

# PRINTF_DIR = ft_printf
# FT_PRINTF = ft_printf/libftprintf.a

# SRCS = push_op.c main.c #reverse_op.c rotate_op.c swap_op.c

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	make -C $(LIBFT_DIR) $(PRINTF_DIR)
# 	cp $(LIBFT) $(FT_PRINTF) $(NAME)
# 	$(AR) $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RM) $(OBJS)
# 	make -C $(LIBFT_DIR) $(PRINTF_DIR) clean

# fclean: clean
# 	$(RM) $(NAME)
# 	make -C $(LIBFT_DIR) $(PRINTF_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re