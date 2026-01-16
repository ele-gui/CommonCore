/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:21:42 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:40 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	primo;
	int	secondo;

	primo = ft_isalpha(c);
	secondo = ft_isdigit(c);
	if (primo || secondo)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	a;

// 	a = '9';
// 	printf("Mia: %d\n", ft_isalnum(a));
// 	printf("Vera: %d\n", isalnum(a));
// 	return (0);
// }
