/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:38:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/19 14:38:28 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	count;
	void *buf;
	ssize_t	len;
	
	
	len = read(fd, buf, len);
	if (len > BUFFER_SIZE)
		len = BUFFER_SIZE;
	buf = ft_calloc(len + 1, sizeof(char *));
	ft_memcpy(buf, BOHHHHH, len);
	if (!buf )
		return (NULL);
	return (buf);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("file_da_leggere", O_RDONLY);
	str = get_next_line(fd);
	return (0);
}