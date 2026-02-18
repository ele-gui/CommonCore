/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:40:16 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/18 16:50:54 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swappa i primi 2 el in cima ad A
//se c'e' solo un el non fa nulla
int	sa(t_push_swap *ps)
{
	int	temp;
	int	mosse;

	mosse = 1;
	if (ps->size_a == 1)
		return (0);
	temp = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = temp;
	ft_printf("sa\n");
	return (mosse);
}

int	sb(t_push_swap *ps)
{
	int	temp;
	int	mosse;

	mosse = 1;
	if (ps->size_b == 1)
		return (0);
	temp = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = temp;
	ft_printf("sb\n");
	return (mosse);
}

int	ss(t_push_swap *ps)
{
	ft_printf("ss\n");
	return (sa(ps) + sb(ps));
}
