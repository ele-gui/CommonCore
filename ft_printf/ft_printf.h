/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:13:47 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 14:03:25 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
long	ft_len_int(long n);
unsigned long	ft_len_uint(unsigned long n);
void	ft_putnbr_uint_fd(unsigned int n, int fd);
int	ft_print_hex_up(int n);
int	ft_print_hex_low(int n);
void	ft_putnbr_base(int nbr, char *base);

#endif