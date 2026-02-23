/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:56:33 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/23 15:20:05 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	cleanup(t_push_swap *ps, char **new_argv, int is_err, int free_s)
{
	if (is_err)
		write(2, "Error\n", 6);
	if (free_s)
	{
		free(ps->stack_a);
		free(ps->stack_b);
	}
	free_split(new_argv);
	return (is_err);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		**new_argv;
	int			size;

	if (argc < 2)
		return (0);
	new_argv = handle_split(argc, argv);
	if (!new_argv || !new_argv[0])
	{
		if (!new_argv)
			write(2, "Error\n", 6);
		return (free_split(new_argv), 0);
	}
	size = 0;
	while (new_argv[size])
		size++;
	if (parse_input(size, new_argv))
		return (cleanup(&ps, new_argv, 1, 0));
	if (init_stacks(&ps, new_argv))
		return (cleanup(&ps, new_argv, 1, 0));
	if (read_move(&ps))
		return (cleanup(&ps, new_argv, 1, 1));
	check_result(&ps);
	return (cleanup(&ps, new_argv, 0, 1));
}
