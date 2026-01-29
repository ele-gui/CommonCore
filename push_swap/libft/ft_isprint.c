/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:12:44 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:53 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	a;

// 	a = '\n';
// 	printf("Mia: %d\n", ft_isprint(a));
// 	printf("Vera: %d\n", isprint(a));
// 	return (0);
// }
