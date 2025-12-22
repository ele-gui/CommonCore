/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:21:07 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/22 10:24:19 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		return (write (1, "(nil)", 5));
	len += ft_print_str("0x");
	len += ft_putnbr_n(n, "0123456789abcdef");
	return (len);
}
