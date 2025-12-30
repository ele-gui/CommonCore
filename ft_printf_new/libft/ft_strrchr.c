/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:30:55 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:48 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		to_find;
	const char	*ptr;

	to_find = (char)c;
	ptr = s;
	while (*s)
		s++;
	if (to_find == '\0')
		return ((char *)s);
	while (s >= ptr)
	{
		if (*s == to_find)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[20] = "ciao";
// 	char	str2[20] = "ciao";
// 	int		n;

// 	n = 'z';
// 	printf("MIA: stringa 1: %s, n: %d, 
// risultato: %s\n", str1, n, ft_strrchr(str1, n));
// 	printf("VER: stringa 1: %s, n: %d, 
// risultato: %s\n", str1, n, strrchr(str2, n));
// 	return (0);
// }