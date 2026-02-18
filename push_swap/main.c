/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/18 16:56:47 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	int			mosse;
	char		**new_argv;
	int			size;

	new_argv = handle_split(argc, argv);
	if (argc < 2 || !new_argv[0])
		return (0);
	if (parse_input(argc, new_argv))
		return (write(2, "Error\n", 6), 1);
	size = 0;
	while (new_argv[size])
		size++;
	if (memory_alloc(size, &ps))
		return (write(2, "Error\n", 6), 1);
	argv_to_stack(size, new_argv, &ps);
	ps.original_size = ps.size_a;
	normalize_stack(&ps);
	mosse = sort(&ps);
	(void)mosse;
	free(ps.stack_a);
	free(ps.stack_b);
	return (0);
}
