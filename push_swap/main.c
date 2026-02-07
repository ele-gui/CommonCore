/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/07 15:12:52 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack_a[10] = {10, 20, 30};
	int stack_b[10] = {5, 7};
	t_push_swap ps;

	ps.stack_a = stack_a;
	ps.stack_b = stack_b;
	ps.size_a = 3;
	ps.size_b = 2;
	ft_printf("Prima:\n");
	print_stack(&ps);
	pb(&ps);
	ft_printf("\nDopo:\n");
	print_stack(&ps);
	
	return (0);
}