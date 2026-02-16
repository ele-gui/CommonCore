/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/15 10:19:39 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap ps;
	int	mosse;
	char **new_argv;

	if (memory_alloc(argc, &ps))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	new_argv = handle_split(argc, argv);
	if (parse_input(argc, new_argv))
	{
		write(2, "Error\n", 6);
		free(ps.stack_a);
		return (1);
	}
	
	argv_to_stack(argc, new_argv, &ps);
	ps.original_size = ps.size_a;
	normalize_stack(&ps);
	mosse = sort(&ps);
	// (void)mosse;
	ft_printf("mosse: %d\n", mosse);
	free(ps.stack_a);
	free(ps.stack_b);
	return (0);
}
