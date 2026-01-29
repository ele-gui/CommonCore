/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:16:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:43 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	a;

// 	a = 'S';
// 	printf("Mia: %d\n", ft_isalpha(a));
// 	printf("Vera: %d\n", isalpha(a));
// 	return (0);
// }
