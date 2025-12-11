/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:36 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/11 15:24:04 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	size_t	count;
	int	i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c') //oppute tutti gli altri casi
			{
				// va_arg(args, int);// la devo usare solo se il char dopo il primo % e' valido
				ft_print_char(va_arg(args, int));
				i++;
			}
		}
		i++;
	}
	va_end(args);
}