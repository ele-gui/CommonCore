/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:44:26 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/12 14:46:13 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_push_swap *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1])
	{
		if (ps->stack_a[1] < ps->stack_a[2])
		{
			if (ps->stack_a[0] < ps->stack_a[2])
				sa(ps);
			else
				ra(ps);
		}
		else
		{
			sa(ps);
			rra(ps);
		}
	}
	else
	{
		if (ps->stack_a[1] > ps->stack_a[2])
		{
			rra(ps);
			if (ps->stack_a[0] < ps->stack_a[2])
				sa(ps);		
				
		}
	}
}

void	sort_5(t_push_swap *ps)
{
	int	minimo;

	minimo = min(ps);
	while (ps->size_a > 3)
	{
		if (ps->stack_a[0] == minimo)
		{
			pb(ps);
			minimo = min(ps);
		}
		else
			ra(ps);
	}
	sort_3(ps);
	if (ps->stack_b[0] < ps->stack_b[1])
		rb(ps);
	pa(ps);
	pa(ps);
}
