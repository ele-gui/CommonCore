/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/16 12:06:37 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//divisione in chunk
t_chunk	chunk_division(t_push_swap *ps)
{
	t_chunk	chunk;
	
	if (ps->size_a <= 20)
		chunk.count = 1;
	else if (ps->size_a <= 100)
		chunk.count = 5;
	else if (ps->size_a <= 500)
		chunk.count = 11;
	chunk.size = ps->original_size / chunk.count;
	return (chunk);
}


//calcolo il costo minore facendo ra/rra
static int	min_cost(t_push_swap *ps, int index)
{
	int	cost;
	
	if (index < ps->size_a / 2)
		cost = index;
	else
		cost = ps->size_a - index;	
	return (cost);
}

//cerco l'indice migliore da spostare, ovvero quello che impiega meno mosse per 
//essere in cima.
//questa funzione trova l'indice migliore da spostare e lo passa a move_cheapest, che
//sceglie se fare ra/rra a seconda del costo calcolato da min_cost
static int	find_best_index(t_push_swap *ps, int start, int end)
{
	int	i;
	int	best_index;
	int	best_cost;
	int	cost;

	best_index = -1;
	best_cost = INT_MAX; //da cambiare
	i = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] >= start && ps->stack_a[i] < end)
		{
			cost = min_cost(ps, i);
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

//a seconda dell'indice scelgo se fare ra/rra e porto l'elemento in cima
static int	cheapest_move(t_push_swap *ps, int index)
{
	int	cost;
	int	mosse;

	mosse = 0;
	cost = min_cost(ps, index);
	if (index < ps->size_a / 2)
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
	return (mosse);
}


//sposto gli elementi in b
int	push_to_b(t_push_swap *ps, t_chunk chunk)
{
	int	mosse;
	int	start;
	int	end;
	int	index;

	mosse = 0;
	start = 0;
	end = chunk.size;
	while (start < ps->original_size)
	{
		index = find_best_index(ps, start, end);
		while (index != -1)
		{
			mosse += cheapest_move(ps, index);
			mosse += pb(ps);
			if (ps->size_b > 0 && ps->stack_b[0] < start + (chunk.size / 2))
				mosse += rb(ps);
			index = find_best_index(ps, start, end);
		}
		start = end;
		end += chunk.size;
		if (end > ps->original_size)
			end = ps->original_size;
	}
	return (mosse);
}

// int	push_to_b(t_push_swap *ps, t_chunk chunk)
// {
// 	int	mosse;
// 	int	start;
// 	int	end;
// 	int	index;
// 	int	cost_a;
// 	int	cost_b;

// 	mosse = 0;
// 	start = 0;
// 	end = chunk.size;
// 	while (start < ps->original_size)
// 	{
// 		index = find_best_index(ps, start, end);
// 		while (index != -1)
// 		{
// 			cost_a = min_cost(ps, index);
// 			cost_b = 0;
// 			if (ps->size_b > 0 && ps->stack_b[0] < start + (chunk.size / 2))
// 				cost_b = 1; // vogliamo fare rb dopo il push

// 			// ruotiamo simultaneamente se possibile
// 			while (cost_a > 0 && cost_b > 0 && index < ps->size_a / 2)
// 			{
// 				mosse += rr(ps);
// 				cost_a--;
// 				cost_b--;
// 			}
// 			while (cost_a > 0)
// 			{
// 				mosse += ra(ps);
// 				cost_a--;
// 			}
// 			mosse += pb(ps);
// 			if (cost_b > 0)
// 				mosse += rb(ps);

// 			index = find_best_index(ps, start, end);
// 		}
// 		start = end;
// 		end += chunk.size;
// 		if (end > ps->original_size)
// 			end = ps->original_size;
// 	}
// 	return (mosse);
// }

