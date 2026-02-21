/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 22:11:59 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	num_control(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	parse_input(int size, char **argv)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (i < size)
	{
		if (num_control(argv[i]))
			return (1);
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		j = 0;
		while (j < i)
		{
			if (ft_atol(argv[j]) == num)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**handle_split(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') || argv[i][0] == '\0')
			return (NULL);
	}
	split = malloc(sizeof(char *) * argc);
	if (!split)
		return (NULL);
	i = 0;
	while (i < argc)
		split[i++] = NULL;
	i = 0;
	while (++i < argc)
	{
		split[i - 1] = ft_strdup(argv[i]);
		if (!split[i - 1])
			return (free_split(split), NULL);
	}
	return (split);
}
