/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 21:57:13 by elguiduc         ###   ########.fr       */
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
        free(split[i]);
        i++;
    }
    free(split);
}

int main(int argc, char **argv)
{
    t_push_swap ps;
    char        **new_argv;
    int         size;

    if (argc < 2)
        return (0);
    new_argv = handle_split(argc, argv);
    if (!new_argv)
        return (write(2, "Error\n", 6), 1);
    if (!new_argv[0])
        return (free_split(new_argv), 0);
    size = 0;
    while (new_argv[size])
        size++;
    if (parse_input(size, new_argv))
        return (free_split(new_argv), write(2, "Error\n", 6), 1);
    if (size < 2)
        return (free_split(new_argv), 0);
    if (memory_alloc(size, &ps))
        return (free_split(new_argv), write(2, "Error\n", 6), 1);
    argv_to_stack(size, new_argv, &ps);
    ps.original_size = ps.size_a;
    normalize_stack(&ps);
    sort(&ps);
    free(ps.stack_a);
    free(ps.stack_b);
    free_split(new_argv);
    return (0);
}
