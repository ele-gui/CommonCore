/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:53:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 14:13:33 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_hex_up(int n)
{
	ft_putnbr_base(n, "0123456789ABCDEF");
	return (ft_len_int(n));
}

int	ft_print_hex_low(int n)
{
	ft_putnbr_base(n, "0123456789abcdef");
	return (ft_len_int(n));
}

int	main(void)
{
	printf("\nUP lunghezza: %d\n", ft_print_hex_up(10));
	printf("\nLOW lunghezza: %d\n", ft_print_hex_low(10));
	return (0);
}