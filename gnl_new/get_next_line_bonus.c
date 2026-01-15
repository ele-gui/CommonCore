/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:47:06 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/14 12:18:27 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//legge la riga
static char	*read_to_string(int fd, char *string)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(string, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = string;
		string = ft_strjoin(string, buffer);
		free(temp);
		if (!string)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (string[0] == '\0')
		return (free(string), NULL);
	return (string);
}

//copia la riga fino a \n dentro str
static char	*extract_line(char *string)
{
	char	*str;
	char	*ptr;
	ssize_t	len;

	if (!string)
		return (NULL);
	ptr = ft_strchr(string, '\n');
	if (!ptr)
		len = ft_strlen(string);
	else
		len = ptr - string + 1;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	//ft_memcpy(str, string, len);
	ft_memmove(str, string, len);
	str[len] = '\0';
	return (str);
}

//pulisce lo string rimuovendo la riga appena letta
static char	*clean_string(char *string)
{
	char	*string_new;
	char	*ptr;
	int		len;

	if (!string)
		return (NULL);
	ptr = ft_strchr(string, '\n');
	if (!ptr)
		return (free(string), NULL);
	len = ft_strlen(ptr + 1);
	if (len == 0)
		return (free(string), NULL);
	string_new = malloc(len + 1);
	if (!string_new)
		return (NULL);
	ft_memmove(string_new, ptr + 1, len);
	string_new[len] = '\0';
	free(string);
	return (string_new);
}

char	*get_next_line(int fd)
{
	static char	*string[1024];
	char		*extracted;
	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string[fd])
	{
		string[fd] = ft_strdup("");
		if (!string[fd])
			return (NULL);
	}
	string[fd] = read_to_string(fd, string[fd]);
	if (!string[fd])
		return (NULL);
	extracted = extract_line(string[fd]);
	string[fd] = clean_string(string[fd]);
	return (extracted);
}