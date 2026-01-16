/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:31:20 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:38 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[] = "ciao";
// 	char	str2[] = "22";
// 	char	str3[] = "ciao";
// 	char	str4[] = "22";

// 	printf("\nBefore ft_memcpy() MIA: %s\n", str1);
// 	ft_memcpy(str1 + 1, str2, 2);
// 	printf("After ft_memcpy() MIA:  %s\n", str1);

// 	printf("\nBefore memcpy() VERA: %s\n", str3);
// 	memcpy(str3 + 1, str4, 2);
// 	printf("After memcpy() VERA:  %s\n", str3);
// 	return (0);
// }
