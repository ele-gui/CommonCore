/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:28 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/04 09:59:15 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa, pb

void	pa(t_push_swap *ps)
{
	int	i;

	if (ps->size_b == 0)
		return ;
	i = ps->size_a;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	i = 0;
	while (i < ps->size_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->size_a++;
	ps->size_b--;
}

void	pb(t_push_swap *ps)
{
	int	i;

	if (ps->size_a == 0)
		return ;
	i = ps->size_b;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	i = 0;
	while (i < ps->size_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->size_b++;
	ps->size_a--;
}