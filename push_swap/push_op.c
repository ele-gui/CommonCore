/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:28 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/12 15:59:29 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//prende il primo el di B e lo mette in cima ad A.
// se B e' vuoto non fa niente
int	pa(t_push_swap *ps)
{
	int	i;

	if (ps->size_b == 0)
		return (0);
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
	return (1);
}

//prende il primo el di A e lo mette in cima a B
int	pb(t_push_swap *ps)
{
	int	i;

	if (ps->size_a == 0)
		return (0);
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
	ps->size_a--;
	ps->size_b++;
	return (1);
}
