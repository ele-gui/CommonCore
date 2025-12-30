/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:53:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/16 10:01:40 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr_n(unsigned long nb, char *base)
{
	int	count;

	if (nb < 16)
	{
		write(1, &base[nb], 1);
		return (1);
	}
	else
	{
		count = ft_putnbr_n(nb / 16, base);
		count += ft_putnbr_n(nb % 16, base);
	}
	return (count);
}

int	ft_print_hex_up(int n)
{
	unsigned long	nb;

	nb = (unsigned int)n;
	if (nb == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_n(nb, "0123456789ABCDEF"));
}

int	ft_print_hex_low(int n)
{
	unsigned long	nb;

	nb = (unsigned int)n;
	if (nb == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_n(nb, "0123456789abcdef"));
}
