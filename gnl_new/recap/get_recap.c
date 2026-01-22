#include "get_recap.h"

//legge la riga
static char	*read_to_string(int fd, char *string)
{
	char 	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!string)      //faccio il controllo di fd in get_next_line(int fd)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(string, '\n'))	//legge fino a \n
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = string;
		string = ft_strjoin(string, buffer);
		free(buffer);
		if (!string)					//ft_strjoin usa malloc => deco fare il controllo per l'llocazione
			return (free(buffer), NULL);
	}
	free(buffer);
	if (string[0] == '\0')
		return (free(string), NULL); //devo freeare perche' faccio ft_strdup prima di richiamare questa funzione in get_next_line()
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
		len = ptr - string + 1;		//prendo fino a \n
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memmove(str, string, len);
	str[len] = '\0';
	return (str);
}

//pulisce string rimuovendo la riga appena letta
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
