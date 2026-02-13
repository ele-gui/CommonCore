/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/13 14:34:33 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is_sorted(t_push_swap *ps)
// sort(t_push_swap *ps)

#include "push_swap.h"

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

int sort_general(t_push_swap *ps)
{
	t_chunk chunk;
	int mosse;
	int index;

	mosse = 0;
	chunk = chunk_division(ps);
	while (ps->size_a > 0)
		mosse +=push_chunk_to_b(ps, chunk);
	while (ps->size_b > 0)
	{
		index = find_index(ps->stack_a, ps->size_a, ps->stack_b[0]);
		mosse +=move_cheapest(ps, index);
		mosse += pa(ps);
	}
	return (mosse);
}

int sort(t_push_swap *ps)
{
	if (is_sorted(ps))
		return (0);
	if (ps->size_a == 2)
		return (sa(ps));
	else if (ps->size_a <= 20)
		return (sort_20(ps));
	else
		return (sort_general(ps));
}
