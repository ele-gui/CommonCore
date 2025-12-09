/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:21:09 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:43 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (len > i && *big != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (*little != '\0' && i + j < len && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[20] = "dimmi una frase";
// 	char	str2[20] = "u";
// 	int		n;

// 	n = 10;
// 	printf("MIA:\n stringa: %s\n da trovare: %s\n 
// risultato: %s\n", str1, str2, ft_strnstr(str1, str2, n));
// 	return (0);
// }
