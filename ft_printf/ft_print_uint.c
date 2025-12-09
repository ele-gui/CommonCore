/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:30:59 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 11:52:06 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_uint(unsigned int n)
{
	ft_putnbr_uint_fd(n, 1);
	return (ft_len_uint(n));
}

int	main(void)
{
	printf("\n\n%u\n", ft_print_uint(10));
	return (0);
}