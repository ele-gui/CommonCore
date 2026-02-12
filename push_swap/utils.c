/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:39:22 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/12 14:36:05 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	int	max;

	max = a;
	if (b > a)
		max = b;
	return (max);
}
int	min(t_push_swap *ps)
{
	int minimo;
	int	i;

	i = 0;
	minimo = ps->stack_a[0];
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] < minimo)
		{
			minimo = ps->stack_a[i];
			// ra(ps);
		}
		i++;
	}
	return (minimo);
}

// asci to int. serve in argv_to_stack e check_limits
long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

//colego ps->stack_a a argv
void	argv_to_stack(int argc, char **argv, t_push_swap *ps)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ps->stack_a[i - 1] = ft_atol(argv[i]);
		i++;
	}
}

// alloco la memoria per stack_a NON FUNZIONA
int	memory_alloc(int argc, t_push_swap *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->size_b = 0;
	ps->size_a = argc - 1;
	if (ps->size_a <= 0)
	{
		ft_printf("---ERRORE: no arguments---\n");
		return (1);
	}
	ps->stack_a = malloc(sizeof(int) * ps->size_a);
	ps->stack_b = malloc(sizeof(int) * ps->size_a);

	if (!ps->stack_a)
	{
		ft_printf("---ERRORE MALLOC---\n");
		return (1);
	}
	return (0);
}
