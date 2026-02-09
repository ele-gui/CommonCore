/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:57:13 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/09 09:28:37 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_push_swap *ps)
// {
// 	int i;

// 	ft_printf("Stack A: ");
// 	i = 0;
// 	while (i < ps->size_a)
// 	{
// 		ft_printf("%d ", ps->stack_a[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// 	ft_printf("Stack b: ");
// 	i = 0;
// 	while (i < ps->size_b)
// 	{
// 		ft_printf("%d ", ps->stack_b[i]);
// 		i++;
// 	}
// 	ft_printf("\n\n");
// }

static int	max(int a, int b)
{
	int	max;

	max = a;
	if (b > a)
		max = b;
	return (max);
}

void	print_stack(t_push_swap *ps)
{
	int	i;
	
	if (!ps)
		return ;
	i = 0;
	while (i < max(ps->size_a, ps->size_b))
	{
		if (i < ps->size_a)
			ft_printf("%d ", ps->stack_a[i]);
		else
			ft_printf("_ ");
		if (i < ps->size_b)
			ft_printf("%d ", ps->stack_b[i]);
		else
			ft_printf("_ ");
		i++;
		ft_printf("\n");
	}
	ft_printf("--------\na b\n");
	ft_printf("Size A: %d\nSize B: %d\n", ps->size_a, ps->size_b);
	ft_printf("\n\n");
}
