/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:08:45 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 16:21:47 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//conat le sottostringhe separate da c
static int	ft_count_sub(char const *s, char c)
{
	int	count_sub;
	int	i;

	i = 0;
	count_sub = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count_sub++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count_sub);
}

//conta la lunghezza della sottostringa
static int	ft_next_word(char const *s, char c, int *pos)
{
	int	len;

	while (s[*pos] && s[*pos] == c)
		(*pos)++;
	len = 0;
	while (s[*pos + len] && s[*pos + len] != c)
		len++;
	return (len);
}

static void	ft_free_split(char **str, int col)
{
	int	j;

	if (!str)
		return ;
	j = 0;
	while (j < col)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

//copia la sottostringa in dest (splitted)
static void	ft_fill_word(char *dst, char const *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
}

char	**handle_split(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	split = malloc(sizeof(char *) * argc);
	if (!split)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		split[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	split[i - 1] = NULL;
	return (split);
}

// int	main(void)
// {
// 	int		index;
// 	char	**split;

// 	split = ft_split("sono una sirena", ' ');
// 	if (!split)
// 		return (1);
// 	index = 0;
// 	while (split[index])
// 	{
// 		printf("%s\n", split[index]);
// 		index++;
// 	}
// 	ft_free_split(split, index);
// 	return (0);
// }