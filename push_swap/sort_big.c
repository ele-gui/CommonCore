/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/16 12:06:55 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is_sorted(t_push_swap *ps)
// sort(t_push_swap *ps)

#include "push_swap.h"

//controllo se lo stack e' ordinato
int	is_sorted(t_push_swap *ps)
{
	int i;
	
	if (ps->size_a <= 1)
		return (1);
	i = 0;
	while (i < ps->size_a - 1)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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

//calcolo costo minore facendo rb/rrb
static int	min_cost_b(t_push_swap *ps, int index)
{
	int	cost;

	if (index < ps->size_b / 2)
		cost = index;
	else	
		cost = ps->size_b - index;
	return (cost);
}

//a seconda dell'indice decido de fare rb/rrb
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


//sposto gli elementi in a
int	push_to_a(t_push_swap *ps)
{
	int	mosse;
	int	index;
	
	mosse = 0;
	while (ps->size_b > 0)
	{
		index = find_max_index(ps);
		mosse += cheapest_move_b(ps, index);
		mosse += pa(ps);
	}
	return (mosse);
}


// int	push_to_a(t_push_swap *ps)
// {
// 	int	mosse;
// 	int	index_b;
// 	int	cost_a, cost_b;

// 	mosse = 0;

// 	while (ps->size_b > 0)
// 	{
// 		index_b = find_max_index(ps);
// 		cost_b = min_cost_b(ps, index_b);
// 		cost_a = 0; // opzionale: puoi ruotare anche a se vuoi anticipare la posizione

// 		// se vuoi ottimizzare con a: usa cost_a come min_cost(ps, pos_in_a)
// 		// esempio: portare a[0] già pronto, cost_a = 0

// 		// usa rrr se b nella metà inferiore
// 		while (cost_a > 0 && cost_b > 0 && index_b >= ps->size_b / 2)
// 		{
// 			mosse += rrr(ps);
// 			cost_a--;
// 			cost_b--;
// 		}

// 		// usa rr se b nella metà superiore
// 		while (cost_a > 0 && cost_b > 0 && index_b < ps->size_b / 2)
// 		{
// 			mosse += rr(ps);
// 			cost_a--;
// 			cost_b--;
// 		}

// 		while (cost_a > 0)
// 		{
// 			mosse += ra(ps);
// 			cost_a--;
// 		}

// 		while (cost_b > 0)
// 		{
// 			if (index_b < ps->size_b / 2)
// 				mosse += rb(ps);
// 			else
// 				mosse += rrb(ps);
// 			cost_b--;
// 		}

// 		mosse += pa(ps);
// 	}

// 	return (mosse);
// }

