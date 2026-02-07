/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/07 17:54:19 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack_a[10] = {2, 1, 3, 6, 5, 8};
	int stack_b[10] = {};
	t_push_swap ps;

	ps.stack_a = stack_a;
	ps.stack_b = stack_b;
	ps.size_a = 6;
	ps.size_b = 0;
	ft_printf("INIZIO:\n");
	print_stack(&ps);
	
	sa(&ps);
	ft_printf("----------------\nExec sa:\n");
	print_stack(&ps);
	
	pb(&ps);
	pb(&ps);
	pb(&ps);
	ft_printf("----------------\nExec pb pb pb:\n");
	print_stack(&ps);
	
	// ra(&ps);
	// rb(&ps);
	rr(&ps);
	ft_printf("----------------\nExec ra rb = rr:\n");
	print_stack(&ps);

	rra(&ps);
	rrb(&ps);
	ft_printf("----------------\nExec rra rrb = rrr:\n");
	print_stack(&ps);

	sa(&ps);
	ft_printf("----------------\nExec sa:\n");
	print_stack(&ps);
	
	pa(&ps);
	pa(&ps);
	pa(&ps);
	ft_printf("----------------\nExec pa pa pa:\n");
	print_stack(&ps);

	return (0);
}