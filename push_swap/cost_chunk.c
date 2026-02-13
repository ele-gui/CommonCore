/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/13 14:27:18 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//divisione in chunk
t_chunk	chunk_division(t_push_swap *ps)
{
	t_chunk chunk;

	if (ps->size_a <= 20)
		chunk.count = 1;
	else if (ps->size_a <= 100)
		chunk.count = 5;
	else if (ps->size_a <= 500)
		chunk.count = 12;
	chunk.size = ps->size_a / chunk.count;
	return (chunk);
}

int	calculate_cost_min(t_push_swap *ps, int index)
{
	int cost;

	if (index <= ps->size_a / 2)
		cost = index;
	else
		cost = ps->size_a - index;
	return (cost);
}

int	move_cheapest(t_push_swap *ps, int index)
{
	int cost;
	int mosse;

	mosse = 0;
	cost = calculate_cost_min(ps, index);
	if (index <= ps->size_a / 2)
	{
		while (cost > 0)
		{
			mosse +=ra(ps);
			cost--;
		}
	}
	else
	{
		while (cost > 0)
		{
			mosse += rra(ps);
			cost--;
		}
	}
	return (mosse);
}

int push_chunk_to_b(t_push_swap *ps, t_chunk chunk) 
{
	int	mosse;
	int	start;
	int	end;
	int	i;

	mosse = 0;
	start = 0;
	end = chunk.size;
	i = 0;
	while (i < chunk.count)
	{
		while (chunk.size > 0)
		{
			if (ps->stack_a[0] > start && ps->stack_a[0] < end)
				mosse += pb(ps);
			else
				mosse += move_cheapest(ps, find_index(ps->stack_a, start, end));
		}
		start += chunk.size;
		end = start + chunk.size;
		i++;
	}
	return (mosse);
}
