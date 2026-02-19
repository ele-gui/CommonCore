/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/18 16:51:45 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is_sorted(t_push_swap *ps)
// sort(t_push_swap *ps)

#include "push_swap.h"

//cerco index massimo
static int	find_max_index(t_push_swap *ps)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = ps->stack_b[0];
	max_index = 0;
	while (i < ps->size_b)
	{
		if (ps->stack_b[i] > max)
		{
			max = ps->stack_b[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

// calcolo costo minore facendo rb/rrb
int	min_cost_b(t_push_swap *ps, int index)
{
	int	cost;

	if (index < ps->size_b / 2)
		cost = index;
	else
		cost = ps->size_b - index;
	return (cost);
}

// a seconda dell'indice decido de fare rb/rrb
static int	cheapest_move_b(t_push_swap *ps, int index)
{
	int	cost;
	int	mosse;

	mosse = 0;
	cost = min_cost_b(ps, index);
	if (index < ps->size_b / 2)
	{
		while (cost > 0)
		{
			mosse += rb(ps);
			cost--;
		}
	}
	else
	{
		while (cost > 0)
		{
			mosse += rrb(ps);
			cost--;
		}
	}
	return (mosse);
}

int	push_to_a(t_push_swap *ps)
{
	int	mosse;
	int	index;

	mosse = 0;
	while (ps->size_b > 0)
	{
		index = find_max_index(ps);
		if (index == 0)
			mosse += pa(ps);
		else
			mosse += cheapest_move_b(ps, index);
	}
	return (mosse);
}
