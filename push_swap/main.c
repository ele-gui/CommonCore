/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/10 10:58:55 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





int	main(int argc, char **argv)
{
	t_push_swap ps;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	ps.size_a = 0;
	ps.size_b = 0;
	
	//alloco memoria
	ps.size_a = argc - 1;
	if (ps.size_a <= 0)
	{
		ft_printf("---ERRORE: no arguments---\n");
		return (1);
	}
	ps.stack_a = malloc(sizeof(int) * ps.size_a);
	if (!ps.stack_a)
	{
		ft_printf("---ERRORE MALLOC---\n");
		return (1);
	}
	ft_printf("no malloc error\n");
	argv_to_stack(argc, argv, &ps);
	ft_printf("no conversion error\n");	

	ft_printf("inizio parsing\n");
	if (parse_input(argc, argv))
	{
		ft_printf("---ERRORE NEL PARSING---\n");
		free(ps.stack_a);
		return (1);
	}
	ft_printf("no parsing error\n");
		
	print_stack(&ps);
	// if (is_sorted(&ps))
	// 	return (0);
	// sort(&ps);
	free(ps.stack_a);
	free(ps.stack_b);
	return (0);
}


// int	main(void)
// {
// 	int stack_a[10] = {2, 1, 3, 6, 5, 8};
// 	int stack_b[10] = {};
// 	t_push_swap ps;

// 	ps.stack_a = stack_a;
// 	ps.stack_b = stack_b;
// 	ps.size_a = 6;
// 	ps.size_b = 0;
// 	ft_printf("INIZIO:\n");
// 	print_stack(&ps);
	
// 	sa(&ps);
// 	ft_printf("----------------\nExec sa:\n");
// 	print_stack(&ps);
	
// 	pb(&ps);
// 	pb(&ps);
// 	pb(&ps);
// 	ft_printf("----------------\nExec pb pb pb:\n");
// 	print_stack(&ps);
	
// 	// ra(&ps);
// 	// rb(&ps);
// 	rr(&ps);
// 	ft_printf("----------------\nExec ra rb = rr:\n");
// 	print_stack(&ps);

// 	rra(&ps);
// 	rrb(&ps);
// 	rrr(&ps);
// 	ft_printf("----------------\nExec rra rrb = rrr:\n");
// 	print_stack(&ps);

// 	sa(&ps);
// 	ft_printf("----------------\nExec sa:\n");
// 	print_stack(&ps);
	
// 	pa(&ps);
// 	pa(&ps);
// 	pa(&ps);
// 	ft_printf("----------------\nExec pa pa pa:\n");
// 	print_stack(&ps);

// 	return (0);
// }