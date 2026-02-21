/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 17:00:43 by elguiduc         ###   ########.fr       */
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
		chunk.count = 12;
	chunk.size = ps->original_size / chunk.count;
	return (chunk);
}

void	push_to_b(t_push_swap *ps, t_chunk chunk)
{
	int	start;

	start = 0;
	while (ps->size_a > 0)
	{
		if (ps->stack_a[0] <= start)
		{
			pb(ps);
			if (ps->size_b > 1)
				rb(ps);
			start++;
		}
		else if (ps->stack_a[0] <= start + chunk.size)
		{
			pb(ps);
			start++;
		}
		else
			ra(ps);
	}
}
