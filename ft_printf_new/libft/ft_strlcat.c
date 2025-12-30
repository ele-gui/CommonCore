/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:48:15 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:23 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = 0;
	len_src = ft_strlen(src);
	while (len_dst < size && dst[len_dst] != '\0')
		len_dst++;
	if (len_dst == size)
		return (size + len_src);
	i = 0;
	while (src[i] != '\0' && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

// int	main(void)
// {
// 	char	str1[] = "ciao";
// 	char	str2[] = " mondW";
// 	char	str3[] = "ciao";
// 	//char	str4[] = " mondW";
// 	size_t	n = 20;

// 	printf("\nBefore ft_strlcat() MIA: %s\n", str1);
// 	printf("Lunghezza di src MIA: %zu\n", 
// 	ft_strlcat(str1, str2, n));
// 	printf("After ft_strlcat() MIA:  %s\n", str1);

// 	printf("\nBefore strlcat() VERA: %s\n", str3);
// 	// printf("Lunghezza di src VERA: %ld\n", 
// 	// strlcat(str3, str4, n));
// 	printf("After strlcat() VERA:  %s\n", str3);
// 	return (0);
// }