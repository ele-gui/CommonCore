# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 15:30:15 by elguiduc          #+#    #+#              #
#    Updated: 2026/02/12 10:14:55 by elguiduc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile per libft

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS = ft_isdigit.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_calloc.c ft_bzero.c ft_memset.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
