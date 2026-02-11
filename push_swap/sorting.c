/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/11 15:33:07 by elguiduc         ###   ########.fr       */
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

//divisione in chunk
void	chunk_division(t_push_swap *ps)
{
	int	chunk_count;
	int	chunk_size;
	int	top;
	int	start;
	int	end;
	
	if (ps->size_a <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	chunk_size = ps->size_a / chunk_count;
	start = 0;
	end = chunk_size - 1;
	while (ps->size_a > 0)
	{
		top = ps->stack_a[0];
		if (top >= start && top <= end)
		{
			pb(ps);
			if (top < start + chunk_size / 2)
				rb(ps);
			start++;
			end++;
		}
		else	
			ra(ps);
	}
}
