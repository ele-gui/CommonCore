/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/14 11:18:46 by elguiduc         ###   ########.fr       */
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

//scelgo tra ra e rra poi pb
int	move_cheapest(t_push_swap *ps, int index)
{
	int cost;
	int mosse;

	mosse = 0;
	cost = calculate_cost_min(ps, index);
	if (index < 0 || index >= ps->size_a)
		return (0);
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
	mosse += pb(ps);
	return (mosse);
}


int find_index_in_range(int *stack, int size, int start, int end)
{
    int i = 0;

    while (i < size)
    {
        if (stack[i] > start && stack[i] < end)
            return i; // primo elemento trovato
        i++;
    }
    return (-1); // nessun elemento nel chunk
}


int push_chunk_to_b(t_push_swap *ps, t_chunk chunk)
{
	int mosse;
    int start;
    int end;
    int i;

	mosse = 0;
	start = 0;
	end = chunk.size;
	while (ps->size_a > 0)
	{
		i = -1;
		while (ps->stack_a[i++] >= start && ps->stack_a[i++] < end)
			mosse += move_cheapest(ps, i);
		start = end;
        end += chunk.size;
		if (start >= ps->size_a)
            {
                while (ps->size_a > 0)
                    mosse += move_cheapest(ps, 0);
                break;
            }
	}
    return (mosse);
}

