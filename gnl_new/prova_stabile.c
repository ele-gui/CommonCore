/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova_stabile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:38:25 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/30 19:16:28 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cambiate un po' di cose ma il succo e' lo stesso
#include "get_next_line.h"
//legge la riga
char	*read_to_string(int fd, char *string)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;
	//BUFFER_size e' il numero di byte che leggo alla volta dal fd con read()
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1); //per \0
	if (!buffer)
		return (NULL);
	if (!string && !(string = ft_strdup(""))) //alloca memoria per una stringa vuota, se fallisce freea
		return (free(buffer), NULL); //devo freeare perche' malloc e' andato bene, altrimenti sarebbe uscito prima
	while (!ft_strchr(string, '\n')) //finche' non trova un \n
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		temp = string; //temp mi serve per i memory leak. ft_strjoin alloca memoria per 
		string = ft_strjoin(string, buffer); //la nuova stringa. se non usassi temp
		free(temp); //non avrei modo di liberare la memoria allocata precedentemente => leak
		if (!string)
			return (free(buffer), NULL); //se ft_strjoin e' andata male
	}
	free(buffer);
	if (string[0] == '\0') //non posso mettere questo controllo prima perche' ritorna subito NULL senza nemmeno provare a leggere
		return (free(string), NULL);
	return (string);
}

//copia la riga fino a \n dentro str
char	*extract_line(char *string)
{
	char	*str;
	char	*ptr;
	ssize_t	len;

	if (!string)
		return (NULL);
	ptr = ft_strchr(string, '\n');
	if (!ptr)
	{
		len = 0;
		while (string[len])
			len++;
	}
	else
		len = ptr - string + 1; //rimane solo la riga fino a \n
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, string, len);
	str[len] = '\0';
	return (str);
}

//pulisce lo string rimuovendo la riga appena letta
char	*clean_string(char *string)
{
	char	*string_new;
	char	*ptr;
	int		len;

	if(!string)
		return (NULL);
	ptr = ft_strchr(string, '\n');
	if (!ptr)
		return (free(string), NULL);
	len = 0;
	while (ptr[1 + len]) //salta \n
		len++;
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
	static char	*string;
	char		*extracted;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_to_string(fd, string);
	if (!string)
		return (NULL);
	extracted = extract_line(string);
	string = clean_string(string);
	return (extracted);
}