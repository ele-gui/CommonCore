/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:15:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:55 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_str(char const *s)
{
	if (!s)
		return ;
}

static size_t	ft_min(size_t int1, size_t int2)
{
	size_t	min;

	min = int1;
	if (int2 < int1)
		min = int2;
	return (min);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	size_t	to_copy;
	char	*sub;

	ft_check_str(s);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		sub = (char *)malloc(1);
		ft_check_str(sub);
		sub[0] = '\0';
		return (sub);
	}
	to_copy = len_s - start;
	sub = (char *)malloc(ft_min(len, to_copy) + 1);
	ft_check_str(sub);
	i = 0;
	while (i < ft_min(len, to_copy))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char	string[] = "ciao";
// 	char	*sub_mio;
// 	unsigned int inizio = 0;
// 	size_t	lun = 42000;

// 	sub_mio = ft_substr(string, inizio, lun);
// 	printf("Stringa: %s\n", string);
// 	printf("Start: %d  Len: %zu\n", inizio, lun);
// 	printf("Sottostringa: %s\n", sub_mio);
// 	return (0);	
// }