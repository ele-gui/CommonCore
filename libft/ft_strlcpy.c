/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:03:47 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 11:17:34 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main(void)
// {
// 	char src[] = "Hello World!";
// 	char dest1[] = "ciao";
// 	char dest2[] = "ciao";
// 	size_t res_mio, res_vero;

// 	res_mio = ft_strlcpy(dest1, src, sizeof(dest1));
// 	printf("src:      \"%s\"\n", src);
// 	printf("dest1:    \"%s\"\n", dest1);
// 	printf("ritorno:  %zu (lunghezza di src)\n\n", res_mio);

// 	res_vero = ft_strlcpy(dest2, src, sizeof(dest2));
// 	printf("src:      \"%s\"\n", src);
// 	printf("dest1:    \"%s\"\n", dest2);
// 	printf("ritorno:  %zu (lunghezza di src)\n", res_vero);
// 	return (0);
// }