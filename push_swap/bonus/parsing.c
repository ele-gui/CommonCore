/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 16:41:23 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	parse_input(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

	if (argc < 2)
		return (1);
	i = 0;
	while (argv[i])
	{
		if (num_control(argv[i]))
			return (1);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
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



char **handle_split(int argc, char **argv)
{
    char **split;
    int i;
	int	j;

    // Caso "uno stringa da splittare"
    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        return (split);
    }

    // Caso più argomenti separati
    split = malloc(sizeof(char *) * argc); // argc - 1 + 1 per NULL
    if (!split)
        return (NULL);

    i = 1;
    while (i < argc)
    {
        split[i - 1] = ft_strdup(argv[i]); // copia dinamica
        if (!split[i - 1])
        {
            // se malloc fallisce, liberiamo tutto quello che abbiamo già allocato
            j = 0;
			while (j < i - 1)
			{
				free(split[j]);
				j++;
			}
            free(split);
            return (NULL);
        }
        i++;
    }
    split[i - 1] = NULL; // terminatore

    return split;
}
