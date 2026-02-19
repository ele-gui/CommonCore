/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:26:10 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:46 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		temp[i] = c;
		n--;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str1[50] = "dimmi una frase carina";
// 	char	str2[50] = "dimmi una frase carina";

// 	printf("Before memset(): %s\n", str1);
// 	ft_memset(str1 + 1, '.', 2*sizeof(char));
// 	printf("After memset() MIA:   %s\n", str1);

// 	memset(str2 + 1, '.', 2*sizeof(char));
// 	printf("After memset() VERA:  %s\n", str2);
// 	return (0);
// }
