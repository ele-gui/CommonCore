/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 21:25:09 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_strchr(const char *s, int c)
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

int parse_input(int size, char **argv)
{
    int     i;
    int     j;
    long    num;

    i = 0;
    while (i < size)
    {
        // Controllo se è un numero valido
        if (num_control(argv[i]))
            return (1);
        num = ft_atol(argv[i]);
        // Controllo overflow
        if (num > 2147483647 || num < -2147483648)
            return (1);
        // Controllo duplicati (confronto il numero corrente con i precedenti)
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

    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        return (split); // Se argv[1] è "", split[0] sarà NULL. Corretto.
    }
    // Caso argc > 2: verifichiamo che non ci siano stringhe vuote o con spazi
    for (i = 1; i < argc; i++)
    {
        if (ft_strchr(argv[i], ' ') || argv[i][0] == '\0')
            return (NULL);
    }
    split = malloc(sizeof(char *) * argc); // Spazio per argc-1 stringhe + NULL
    if (!split)
        return (NULL);
    for (i = 1; i < argc; i++)
    {
        split[i - 1] = ft_strdup(argv[i]);
        if (!split[i - 1])
        {
            // Uso una funzione esterna free_split per pulire se ft_strdup fallisce
            free_split(split);
            return (NULL);
        }
    }
    split[argc - 1] = NULL;
    return (split);
}