/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:40:16 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/07 17:04:47 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa, sb, ss

#include "push_swap.h"

//swappa i primi 2 el in cima ad A
//se c'e' solo un el non fa nulla
void	sa(t_push_swap *ps)
{
	int temp;

	if (ps->size_a == 1)
		return ;
	//faccio lo swap con una var temp
	temp = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = temp;
}

void	sb(t_push_swap *ps)
{
	int temp;

	if (ps->size_b == 1)
		return ;
	//faccio lo swap con una var temp
	temp = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = temp;
}

void	ss(t_push_swap *ps)
{
	// int temp;

	// if (ps->size_a == 1)
	// 	return ;
	// //faccio lo swap con una var temp
	// temp = ps->stack_a[0];
	// ps->stack_a[0] = ps->stack_a[1];
	// ps->stack_a[1] = temp;

	// if (ps->size_b == 1)
	// 	return ;
	// //faccio lo swap con una var temp
	// temp = ps->stack_b[0];
	// ps->stack_b[0] = ps->stack_b[1];
	// ps->stack_b[1] = temp;

	sa(ps);
	sb(ps);
}