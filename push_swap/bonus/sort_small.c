/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:44:26 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/22 15:49:12 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_pos_a(t_push_swap *ps, int value)
{
	int	i;

	i = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_3(t_push_swap *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
		sa(ps);
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		sa(ps);
		rra(ps);
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		ra(ps);
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{
		sa(ps);
		ra(ps);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		rra(ps);
}

static void	sort_5(t_push_swap *ps)
{
	int	minimo;
	int	pos;

	while (ps->size_a > 3)
	{
		minimo = min(ps);
		pos = find_pos_a(ps, minimo);
		if (ps->stack_a[0] == minimo)
			pb(ps);
		else if (pos <= ps->size_a / 2)
			ra(ps);
		else
			rra(ps);
	}
	sort_3(ps);
	if (ps->size_b == 2 && ps->stack_b[0] < ps->stack_b[1])
		sb(ps);
	while (ps->size_b > 0)
		pa(ps);
}

static void	sort_20(t_push_swap *ps)
{
	int	pos;
	int	minimo;

	minimo = 0;
	while (ps->size_a > 5)
	{
		pos = find_pos_a(ps, minimo);
		if (ps->stack_a[0] == minimo)
		{
			pb(ps);
			minimo++;
		}
		else if (pos <= ps->size_a / 2)
			ra(ps);
		else
			rra(ps);
	}
	sort_5(ps);
	while (ps->size_b > 0)
		pa(ps);
}

void	mini_sort(t_push_swap *ps)
{
	if (ps->size_a == 2)
	{
		if (ps->stack_a[0] > ps->stack_a[1])
			sa(ps);
	}
	else if (ps->size_a == 3)
		sort_3(ps);
	else if (ps->size_a <= 5)
		sort_5(ps);
	else
		sort_20(ps);
}
