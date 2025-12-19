/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:38:30 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/19 14:13:04 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		temp[i] = c;
		n--;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb != 0 && size >= __SIZE_MAX__ / nmemb)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

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