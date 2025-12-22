/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:38:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/22 19:00:43 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	count;
	char buf[1024];
	ssize_t	len;
	static char *boh;
	int	i;

	i = 0;
	//legge fino a \n, read return 0 con EOF
	while (count = read(fd, &buf[i], 1) > 0 && i <= BUFFER_SIZE)
	{
		if (buf[i] == '\n' || i == BUFFER_SIZE)
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}
	
	boh = ft_calloc(count + 1, sizeof(char *));
	ft_memcpy(boh, buf, len);
	if (!boh )
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