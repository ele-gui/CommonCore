/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:19:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:33 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "ciao";
// 	char	*result;
// 	int		c_to_find;
// 	size_t	n;
// 	// Test case 1: 'a' in "ciao" nei primi 2 bytes
// 	printf("\nMIA test 1\n\n");
// 	c_to_find = 'a';
// 	n = 5;
// 	result = ft_memchr(str1, c_to_find, n);
// 	//MIA
// 	printf("cerco '%c' in \"%s\" nei primi %zu bytes.\n", c_to_find, str1, n);
// 	if (result != NULL)
// 		printf("trovato '%c' alla posizione %ld.\n", c_to_find, result - str1);
// 	else
// 		printf("'%c' non trovato.\n", c_to_find);
// 	printf("\n");
// 	//VERA
// 	printf("VERA test 1\n\n");
// 	result = memchr(str1, c_to_find, n);
// 	printf("cerco '%c' in \"%s\" nei primi %zu bytes.\n", c_to_find, str1, n);
// 	if (result != NULL)
// 		printf("trovato '%c' alla posizione %ld.\n", c_to_find, result - str1);
// 	else
// 		printf("'%c' non trovato.\n", c_to_find);
// 	return (0);
// }
