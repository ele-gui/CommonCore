/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/15 10:50:52 by elguiduc         ###   ########.fr       */
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
		chunk.count = 11;
	chunk.size = ps->original_size / chunk.count;
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

//scelgo tra ra e rra poi pb
int	move_cheapest(t_push_swap *ps, int index)
{
	int cost;
	int mosse;

	mosse = 0;
	if (index < 0 || index >= ps->size_a || ps->size_a == 0)
		return (0);
	cost = calculate_cost_min(ps, index);
	if (index <= ps->size_a / 2)
	{
		while (cost > 0)
		{
			mosse += ra(ps);
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
	// mosse += pb(ps);
	return (mosse);
}

int find_closest_in_chunk(t_push_swap *ps, int start, int end)
{
	int i;
	int best_index;
	int best_cost;
	int cost;

	best_index = -1;
	best_cost = 2147483647;
	i = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] >= start && ps->stack_a[i] < end)
		{
			cost = calculate_cost_min(ps, i);
			if (cost < best_cost)
			{
				best_cost = cost;
				best_index = i;
			}
		}
		i++;
	}
	return (best_index);
}


int push_chunk_to_b(t_push_swap *ps, t_chunk chunk)
{
	int mosse;
    int start;
    int end;
    int index;

	mosse = 0;
	start = 0;
	end = chunk.size;
	while (start < ps->original_size)
	{
		index = find_closest_in_chunk(ps, start, end);
		while (index != -1)
		{
			mosse += move_cheapest(ps, index);
			mosse += pb(ps);
			if (ps->stack_b[0] < start + (chunk.size / 2))
				mosse += rb(ps);
			else if (ps->stack_b[0] > start + (chunk.size * 3 / 4))
				mosse += rb(ps);
			index = find_closest_in_chunk(ps, start, end);
		}
		start = end;
		end += chunk.size;
	}
    return (mosse);
}


