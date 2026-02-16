/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/16 10:36:05 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gestisco gli errori dell'input
//parse_input(int argc, char **argv, t_push_swap *ps)

#include "push_swap.h"

//controllo se tutti gli argomenti sono numeri
static int	num_control(char **argv)
{
	int	i;
	int	j;
	int	sign_count;

	i = 1;
	while (argv[i])
	{
		j = 0;
		sign_count = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			sign_count++;
			j = 1;
		}
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		if (sign_count > 1)
			return (1);
		i++;
	}
	return (0);
}

//controllo se c'e' overflow/underflow
static int	check_limits(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

//controllo se ci sono duplicati
static int	doppioni(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j])) //atoi->atol
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_input(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (num_control(argv))
		return (1);
	if (check_limits(argv))
		return (1);
	if (doppioni(argv))
		return (1);
	return (0);
}

char	**handle_split(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (&argv[1]);
}
