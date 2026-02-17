/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:42:02 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/13 09:12:18 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra, rb, rr

#include "push_swap.h"
//Shift up all elements of stack a by 1.
//The first element becomes the last one.
int	ra(t_push_swap *ps)
{
	int	i;
	int	temp;

	if (ps->size_a == 1)
		return (0);
	i = 0;
	temp = ps->stack_a[0];
	while (i < ps->size_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1]; //i + 1 non esiste
		i++;
	}
	ps->stack_a[ps->size_a - 1] = temp;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_push_swap *ps)
{
	int	i;
	int	temp;

	if (ps->size_b == 1)
		return (0);
	i = 0;
	temp = ps->stack_b[0];
	while (i < ps->size_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[ps->size_b - 1] = temp;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_push_swap *ps)
{
	ft_printf("rr\n");
	return (ra(ps) + rb(ps));
}
