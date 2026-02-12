/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:44:26 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/12 17:16:45 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_push_swap *ps)
{
	int	mosse;

	mosse = 0;
	if (ps->stack_a[0] > ps->stack_a[1])
	{
		if (ps->stack_a[1] < ps->stack_a[2])
		{
			if (ps->stack_a[0] < ps->stack_a[2])
			{
				sa(ps);
				mosse++;
			}
			else
			{
				ra(ps);
				mosse++;
			}
		}
		else
		{
			sa(ps);
			mosse++;
			rra(ps);
			mosse++;
		}
	}
	else
	{
		if (ps->stack_a[1] > ps->stack_a[2])
		{
			rra(ps);
			mosse++;
			if (ps->stack_a[0] < ps->stack_a[2])
			{
				sa(ps);		
				mosse++;
			}
		}
	}
	return (mosse);
}

int	sort_5(t_push_swap *ps)
{
	int	minimo;
	int	mosse;	
	minimo = min(ps);
	mosse = 0;
	while (ps->size_a > 3)
	{
		if (ps->stack_a[0] == minimo)
		{
			pb(ps);
			mosse++;
			minimo = min(ps);
		}
		else
		{
			if (minimo <= ps->size_a / 2)
			{
				rra(ps);
				mosse++;
			}
			else
			{
				ra(ps);
				mosse++;
			}
		}
	}
	sort_3(ps);
	if (ps->stack_b[0] < ps->stack_b[1])
		rb(ps);
	pa(ps);
	pa(ps);
	mosse += 2;
	return (mosse);
}

int	mini_sort(t_push_swap *ps)
{
	int	minimo;
	int	mosse;

	mosse = 0;
	minimo = min(ps);
	while (ps->size_a > 5)
	{
		if (ps->stack_a[0] == minimo)
		{
			pb(ps);
			mosse++;
			minimo = min(ps);
		}
		else
		{
			if (minimo <= ps->size_a / 2)
			{
				ra(ps);
				mosse++;
			}
			else
			{
				rra(ps);
				mosse++;
			}
		}
	}

	ft_printf("dopo pb\n");
	print_stack(ps);

	sort_5(ps);
	
	ft_printf("dopo sort_5\n");
	print_stack(ps);
	while (ps->size_b != 0)
	{
		pa(ps);
		ft_printf("dopo pa\n");
		print_stack(ps);
		mosse++;
	}
	return (mosse);
}
