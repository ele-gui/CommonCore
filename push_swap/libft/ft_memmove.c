/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:56 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:41 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_str(void *dest, const void *src)
{
	if (!dest && !src)
		return ;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	ft_check_str(dest, src);
	if (s < d)
	{
		while (i < n)
		{
			d[n - 1 - i] = s[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

//ho sovrapposizione quando le aree di memoria di dest e src
//condividono almeno un byte. ovvero se almeno un byte di 
//src si trova già in dest.

// int	main(void)
// {
// 	char	str1[] = "ciao";
// 	//char	str2[] = "22";
// 	char	str3[] = "ciao";
// 	//char	str4[] = "22";

// 	printf("\nBefore ft_memmove() MIA: %s\n", str1);
// 	ft_memmove(str1 + 1, str1, 2);
// 	printf("After ft_memmove() MIA:  %s\n", str1);

// 	printf("\nBefore memmove() VERA: %s\n", str3);
// 	memmove(str3 + 1, str3, 2);
// 	printf("After memmove() VERA:  %s\n", str3);
// 	return (0);
// }
