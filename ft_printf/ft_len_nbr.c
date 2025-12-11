/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:51:56 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/10 20:16:16 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static long	ft_abs_val(long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

long	ft_len_int(long n)
{
	long	i;

	i = 0;
	if (n <= 0)
		i = 1;
	n = ft_abs_val(n);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned long	ft_len_uint(unsigned long n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}