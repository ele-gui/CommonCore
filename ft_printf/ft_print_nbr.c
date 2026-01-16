/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:41:20 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/14 10:36:57 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	char	a;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		a = n + '0';
		write(fd, &a, 1);
	}
}

//%d e %i hanno lo stesso output
int	ft_print_dec_int(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_len_int(n));
}

//%u
int	ft_print_uint(unsigned int n)
{
	ft_putnbr_uint_fd(n, 1);
	return (ft_len_uint(n));
}
