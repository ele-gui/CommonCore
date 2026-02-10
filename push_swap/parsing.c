/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/10 11:12:42 by elguiduc         ###   ########.fr       */
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
		{
			ft_printf("---ERRORE: solo il segno---\n");
			return (1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("---ERRORE: carattere non numerico---\n");
				return (1);
			}
			j++;
		}
		if (sign_count > 1)
		{
			ft_printf("---ERRORE: piu' di un segno---\n");
			return (1);
		}
		i++;
	}
	ft_printf("NUM CONTROL PASSED\n");
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
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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
	{
		ft_printf("---ERRORE: MENO DI 2 ELEMENTI---\n");
		return (1);
	}
	ft_printf("ARGUMENT COUNT CONTROL PASSED\n");
	if (num_control(argv))
	{
		ft_printf("---ERRORE: NON TUTTI INT---\n");
		return (1);
	}
	ft_printf("NUM CONTROL PASSED\n");
	if (check_limits(argv))
	{
		ft_printf("---ERRORE: OVERFLOW/UNDERFLOW---\n");
		return (1);
	}
	ft_printf("LIMITS CONTROL PASSED\n");
	if (doppioni(argv))
	{
		ft_printf("---ERRORE: DOPPIONI---\n");
		return (1);
	}
	ft_printf("DUPLICATE CONTROL PASSED\n");
	ft_printf("INPUT PARSED\n");
	return (0);
}
