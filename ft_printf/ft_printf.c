/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:36 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/16 09:56:05 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

// int main(void)
// {
//     int r_ft, r_std;

//     printf("Test c:\n");
//     r_ft  = ft_printf("Test c: %c\n", 'A');
//     r_std = printf("Real c: %c\n\n", 'A');

//     printf("Test s:\n");
//     r_ft  = ft_printf("Test s: %s\n", "Hello 42");
//     r_std = printf("Real s: %s\n\n", "Hello 42");

//     printf("Test d/i:\n");
//     r_ft  = ft_printf("Test d/i: %d %i\n", -1234, -1234);
//     r_std = printf("Real d/i: %d %i\n\n", -1234, -1234);

//     printf("Test u:\n");
//     r_ft  = ft_printf("Test u: %u\n", 4294967295u);
//     r_std = printf("Real u: %u\n\n", 4294967295u);

//     printf("Test x/X:\n");
//     r_ft  = ft_printf("Test x/X: %x %X\n", 255, 255);
//     r_std = printf("Real x/X: %x %X\n\n", 255, 255);

//     printf("Test p:\n");
//     int a = 42;
//     r_ft  = ft_printf("Test p: %p\n", &a);
//     r_std = printf("Real p: %p\n\n", &a);

//     printf("Test %%:\n");
//     r_ft  = ft_printf("Test %%: %%\n");
//     r_std = printf("Real %%: %%\n\n");

//     printf("Test stringa NULL:\n");
//     char *null_str = NULL;
//     r_ft  = ft_printf("Test NULL: %s\n", null_str);
//     r_std = printf("Real NULL: %s\n\n", null_str);

//     printf("Return ft_printf: %d\n", r_ft);
//     printf("Return printf:    %d\n", r_std);

//     return 0;
// }