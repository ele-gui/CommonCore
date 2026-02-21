/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 16:42:03 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void free_split(char **split)
{
    int i;

	i = 0;
    if (!split) 
		return ;
    while (split[i])
    {
        free(split[i]);  // ok solo se malloc/ft_strdup
        i++;
    }
    free(split);  // ok solo se malloc
}

// int	main(int argc, char **argv)
// {
// 	t_push_swap	ps;
// 	int			mosse;
// 	char		**new_argv;
// 	int			size;

// 	new_argv = handle_split(argc, argv);
	
// 	if (argc < 2 || !new_argv[0])
// 	{
// 		free_split(new_argv);
// 		return (0);
// 	}
// 	if (parse_input(argc, new_argv))
// 	{
// 		free_split(new_argv);
// 		return (write(2, "Error\n", 6), 1);
// 	}
// 	size = 0;
// 	while (new_argv[size])
// 		size++;
// 	if (memory_alloc(size, &ps))
// 	{
// 		free_split(new_argv);
// 		return (write(2, "Error\n", 6), 1);
// 	}
// 	argv_to_stack(size, new_argv, &ps);

// 	ps.original_size = ps.size_a;
// 	normalize_stack(&ps);
// 	mosse = sort(&ps);
// 	(void)mosse;
// 	free(ps.stack_a);
// 	free(ps.stack_b);
// 	free_split(new_argv);
// 	return (0);
// }


int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		**new_argv;
	int			size;
	int			mosse;

	mosse = 0;

	new_argv = handle_split(argc, argv);
	if (!new_argv)
		return (1);

	size = 0;
	while (new_argv[size])
		size++;
		
	if (size == 0)
	{
		free_split(new_argv);
		return (0);
	}
	
			
	if (parse_input(size, new_argv))
	{
		free_split(new_argv);
		return (write(2, "Error\n", 6), 1);
	}

	

	if (memory_alloc(size, &ps))
	{
		free_split(new_argv);
		return (write(2, "Error\n", 6), 1);
	}

	argv_to_stack(size, new_argv, &ps);
	ps.original_size = ps.size_a;
	normalize_stack(&ps);
	mosse = sort(&ps);

	free(ps.stack_a);
	free(ps.stack_b);
	free_split(new_argv);
	return (0);
}