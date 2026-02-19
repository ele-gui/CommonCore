/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/19 14:00:41 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//divisione in chunk
t_chunk	chunk_division(t_push_swap *ps)
{
	t_chunk	chunk;

	if (ps->size_a <= 20)
		chunk.count = 1;
	else if (ps->size_a <= 100)
		chunk.count = 5;
	else if (ps->size_a <= 500)
		chunk.count = 12;
	chunk.size = ps->original_size / chunk.count;
	return (chunk);
}

int	push_to_b(t_push_swap *ps, t_chunk chunk)
{
	int	mosse;
	int	start;
	
	mosse = 0;
	start = 0;
	while (ps->size_a > 0)
	{
		if (ps->stack_a[0] <= start)
		{
			mosse += pb(ps);
			if (ps->size_b > 1)
				mosse += rb(ps);
			start++;
		}
		else if (ps->stack_a[0] <= start + chunk.size)
		{
			mosse += pb(ps);
			start++;
		}
		else
			mosse += ra(ps);
	}
	
	return (mosse);
}
