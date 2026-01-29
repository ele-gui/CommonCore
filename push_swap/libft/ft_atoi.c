/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:45:15 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:31 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// asci to int
int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

// int	main(void)
// {
// 	char *stringa = "4 2";
// 	int	numero_mio;
// 	int	numero_vero;
// 	numero_mio = ft_atoi(stringa);
// 	numero_vero = atoi(stringa);
// 	printf("MIA:  %d\n", numero_mio);
// 	printf("VERA: %d\n", numero_vero);
// 	return (0);
// }
