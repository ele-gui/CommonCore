/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:51 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:11 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strchr() function returns a pointer to the first 
occurrence of the character c in the string s.*/
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	to_find;

	i = 0;
	to_find = (char)c;
	while (s[i] != '\0' )
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	if (to_find == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[20] = "ciao";
// 	char	str2[20] = "ciao";
// 	int		n;

// 	n = 'z';
// 	printf("MIA: stringa 1: %s, n: %d, risultato: %s\n",
// str1, n, ft_strchr(str1, n));
// 	printf("VER: stringa 1: %s, n: %d, risultato: %s\n",
// str1, n, strchr(str2, n));
// 	return (0);
// }
