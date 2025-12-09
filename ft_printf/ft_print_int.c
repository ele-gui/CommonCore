/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:41:20 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 10:57:26 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_int(int n)
{
	ft_putnbr_fd(n, 1);
	return(ft_len_int(n));
}

/* int	main(void)
{
	printf("\n\n%d\n", ft_print_int(-5));
	return (0);
} */