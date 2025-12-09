/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:30:13 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:34 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//cancella n byte di memoria partendo da dove sta puntando s
void	ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	char	str1[] = "dimmi una frase carina";
// 	char	str2[] = "dimmi una frase carina";

// 	printf("\nBefore ft_bzero() MIA: %s\n", str1);
// 	ft_bzero(str1 + 2, 2*sizeof(char));
// 	printf("After ft_bzero() MIA:  %s", str1);
// 	printf("\nBefore bzero() VERA: %s\n", str2);
// 	bzero(str2 + 2, 2*sizeof(char));
// 	printf("After bzero() VERA:  %s\n", str2);
// 	return (0);
// }
