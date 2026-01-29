/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:36 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/19 13:12:33 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//il main si trova in test.c
int	ft_print_call(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'X')
		len += ft_print_hex_up(va_arg(args, int));
	else if (format == 'x')
		len += ft_print_hex_low(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len += ft_print_dec_int(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_call(args, str[i + 1]);
			i++;
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
