/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:20:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:50 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	a;

// 	a = '9';
// 	printf("Mia: %d\n", ft_isdigit(a));
// 	printf("Vera: %d\n", isdigit(a));
// 	return (0);
// }
