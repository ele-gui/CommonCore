/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:44:26 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/19 14:00:11 by elguiduc         ###   ########.fr       */
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

int	sort_3(t_push_swap *ps)
{
	int	mosse;

	mosse = 0;
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
		mosse += sa(ps);
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		mosse += sa(ps);
		mosse += rra(ps);
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		mosse += ra(ps);
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{
		mosse += sa(ps);
		mosse += ra(ps);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		mosse += rra(ps);
	return (mosse);
}

int	sort_5(t_push_swap *ps)
{
	int	minimo;
	int	mosse;
	int	pos;

	minimo = min(ps);
	mosse = 0;
	while (ps->size_a > 3)
	{
		pos = find_pos_a(ps, minimo);
		if (ps->stack_a[0] == minimo)
		{
			mosse += pb(ps);
			minimo = min(ps);
		}
		else if (pos < ps->size_a / 2)
			mosse += ra(ps);
		else
			mosse += rra(ps);
	}
	mosse += sort_3(ps);
	if (ps->stack_b[0] < ps->stack_b[1] && ps->size_b == 2)
		mosse += rb(ps);
	mosse += pa(ps);
	mosse += pa(ps);
	return (mosse);
}

int	sort_20(t_push_swap *ps)
{
	int	mosse;
	int	pos;
	int	minimo;

	minimo = 0;
	mosse = 0;
	while (ps->size_a > 5)
	{
		pos = find_pos_a(ps, minimo);
		if (ps->stack_a[0] == minimo)
		{
			mosse += pb(ps);
			minimo++;
		}
		else if (pos <= ps->size_a / 2)
			mosse += ra(ps);
		else
			mosse += rra(ps);
	}
	mosse += sort_5(ps);
	while (ps->size_b > 0)
		mosse += pa(ps);
	return (mosse);
}

int	mini_sort(t_push_swap *ps)
{
	int	mosse;

	mosse = 0;
	if (ps->size_a == 2)
	{
		if (ps->stack_a[0] > ps->stack_a[1])
			mosse += sa(ps);
	}
	else if (ps->size_a == 3)
		mosse += sort_3(ps);
	else if (ps->size_a <= 5)
		mosse += sort_5(ps);
	else
		mosse += sort_20(ps);
	return (mosse);
}
