/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/16 11:28:58 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gestisco gli errori dell'input
//parse_input(int argc, char **argv, t_push_swap *ps)

#include "push_swap.h"

//controllo se tutti gli argomenti sono numeri
// static int	num_control(char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	sign_count;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		sign_count = 0;
// 		if (argv[i][0] == '-' || argv[i][0] == '+')
// 		{
// 			sign_count++;
// 			j = 1;
// 		}
// 		if (argv[i][j] == '\0')
// 			return (1);
// 		while (argv[i][j])
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 				return (1);
// 			j++;
// 		}
// 		if (sign_count > 1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static int num_control(char *str)
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


// //controllo se c'e' overflow/underflow
// static int	check_limits(char **argv)
// {
// 	int		i;
// 	long	num;

// 	i = 0; // 1 -> 0
// 	while (argv[i])
// 	{
// 		num = ft_atol(argv[i]);
// 		if (num > INT_MAX || num < INT_MIN)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// //controllo se ci sono duplicati
// static int	doppioni(char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		j = i + 1;
// 		while (argv[j])
// 		{
// 			if (ft_atol(argv[i]) == ft_atol(argv[j]))
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	parse_input(int argc, char **argv)
// {
// 	int	i;
// 	int	num;
// 	int	j;

// 	if (argc < 2)
// 		return (0);
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (num_control(argv[i]))
// 			return (1);
// 		num = ft_atol(argv[i]);
// 		if (num > INT_MAX || num < INT_MIN)
// 			return (1);

// 		j = 0;
// 		while (i < j)
// 		{
// 			if (ft_atol(argv[j]) == ft_atol(argv[i]))
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int parse_input(int argc, char **argv)
{
    int i, j;
    long num;

    if (argc < 2)
        return (1);

    i = 0;
    while (argv[i])
    {
        // controllo formato numerico valido
        if (num_control(argv[i]))
            return 1;

        // controllo overflow/underflow
        num = ft_atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            return 1;

        // controllo duplicati (solo elementi precedenti)
        j = 0;
        while (j < i)
        {
            if (ft_atol(argv[j]) == num)
                return 1;
            j++;
        }

        i++;
    }

    return 0;
}


char	**handle_split(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (&argv[1]);
}
