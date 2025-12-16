/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:38:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/16 11:32:40 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	size_t	count;
	void *buf;
	ssize_t	len;
	
	buf = malloc(count + 1);
	len = read(fd, buf, count);
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