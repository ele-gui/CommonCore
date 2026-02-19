/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/19 17:54:55 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is_sorted(t_push_swap *ps)
// sort(t_push_swap *ps)

#include "checker.h"

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
static void	cheapest_move_b(t_push_swap *ps, int index)
{
	int	cost;

	cost = min_cost_b(ps, index);
	if (index < ps->size_b / 2)
	{
		while (cost > 0)
		{
			rb(ps);
			cost--;
		}
	}
	else
	{
		while (cost > 0)
		{
			rrb(ps);
			cost--;
		}
	}
}

void	push_to_a(t_push_swap *ps)
{
	int	index;

	while (ps->size_b > 0)
	{
		index = find_max_index(ps);
		cheapest_move_b(ps, index);
		pa(ps);
	}
}
