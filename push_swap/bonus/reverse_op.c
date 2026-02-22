/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:53 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 16:57:53 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rra, rrb, rrr

#include "checker.h"

//hift down all elements of stack a by 1.
//The last element becomes the first one.
void	rra(t_push_swap *ps)
{
	int	i;
	int	temp;

	if (ps->size_a == 1)
		return ;
	temp = ps->stack_a[ps->size_a - 1];
	i = ps->size_a - 1;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
}

void	rrb(t_push_swap *ps)
{
	int	i;
	int	temp;

	if (ps->size_b == 1)
		return ;
	temp = ps->stack_b[ps->size_b - 1];
	i = ps->size_b - 1;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
}

void	rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
}
