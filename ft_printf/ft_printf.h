/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:13:47 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/16 09:53:18 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <strings.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

long			ft_len_int(long n);
unsigned long	ft_len_uint(unsigned long n);
int				ft_print_char(char c);
int				ft_print_hex_up(int n);
int				ft_print_hex_low(int n);
int				ft_print_dec_int(int n);
int				ft_print_uint(unsigned int n);
int				ft_print_str(char *str);
int				ft_print_ptr(unsigned long n);
int				ft_print_percent(void);
int				ft_print_call(va_list args, const char format);
int				ft_printf(const char *str, ...);
int				ft_putnbr_n(unsigned long nb, char *base);

#endif