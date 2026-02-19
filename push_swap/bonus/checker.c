/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:56:33 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/19 18:46:45 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//devo togliere le mosse e le operazioni non devono stampare
int	compare_amd_move(t_push_swap *ps, char *op)
{
	if (ft_strncmp("sa", op, 2) == 0 && ft_strlen(op) == 2)
		sa(ps);
	else if (ft_strncmp("sb", op, 2) == 0 && ft_strlen(op) == 2)
		sb(ps);
	else if (ft_strncmp("ra", op, 2) == 0 && ft_strlen(op) == 2)
		ra(ps);
	else if (ft_strncmp("rb", op, 2) == 0 && ft_strlen(op) == 2)
		rb(ps);
	else if (ft_strncmp("rr", op, 2) == 0 && ft_strlen(op) == 2)
		rr(ps);
	else if (ft_strncmp("rra", op, 3) == 0 && ft_strlen(op) == 3)
		rra(ps);
	else if (ft_strncmp("rrb", op, 3) == 0 && ft_strlen(op) == 3)
		rrb(ps);
	else if (ft_strncmp("rrr", op, 3) == 0 && ft_strlen(op) == 3)
		rrr(ps);
	else if (ft_strncmp("pa", op, 2) == 0 && ft_strlen(op) == 2)
		pa(ps);
	else if (ft_strncmp("pb", op, 2) == 0 && ft_strlen(op) == 2)
		pb(ps);
	else
		return (1);
	return (0);
}


int	read_move(t_push_swap *ps)
{
	char	*line;
	size_t	len;

	line = get_next_line(0);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n' && len > 0)
			line[len - 1] = '\0';
		if (ft_strlen(line) > 0) 
        {
            if (compare_amd_move(ps, line))
            {
                free(line);
                return (1);
            }
        }
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

static void	check_result(t_push_swap *ps)
{
	if (is_sorted(ps) && ps->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(ps->stack_a);
	free(ps->stack_b);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		**new_argv;
	int			size;

	if (argc < 2 || !(new_argv = handle_split(argc, argv)) || !new_argv[0])
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
	if (read_move(&ps))
	{
		write(2, "Error\n", 6);
		return (free(ps.stack_a), free(ps.stack_b), 1);
	}
	check_result(&ps);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_push_swap	ps;
// 	char		**new_argv;
// 	int			size;

// 	new_argv = handle_split(argc, argv);
// 	if (argc < 2 || !new_argv[0])
// 		return (0);
// 	if (parse_input(argc, new_argv))
// 		return (write(2, "Error\n", 6), 1);
// 	size = 0;
// 	while (new_argv[size])
// 		size++;
// 	if (memory_alloc(size, &ps))
// 		return (write(2, "Error\n", 6), 1);
// 	argv_to_stack(size, new_argv, &ps);
// 	ps.original_size = ps.size_a;
// 	normalize_stack(&ps);
// 	if (read_move(&ps))
// 		return (write(2, "Error\n", 6), free(ps.stack_a), free(ps.stack_b), 1);
// 	if (is_sorted(&ps) && ps.size_b == 0)
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// 	free(ps.stack_a);
// 	free(ps.stack_b);
// 	return (0);
// }
