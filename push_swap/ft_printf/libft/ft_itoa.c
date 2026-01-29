/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:32:07 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:56 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_abs_val(long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	ft_len_int(long n)
{
	int	i;

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

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		i;
	int		len;

	nb = n;
	len = ft_len_int(nb);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = len - 1;
	if (nb == 0)
		res[0] = '0';
	nb = ft_abs_val(nb);
	while (nb > 0)
	{
		res[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

// int	main(void)
// {
// 	// int	n;
// 	// char 	*res;

// 	// n = 123;
// 	// res = ft_itoa(n);
// 	printf("%s\n", ft_itoa(-123));
// 	return (0);
// }