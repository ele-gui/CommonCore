/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:56:33 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/22 15:56:47 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_split(char **split)
{
	int	i;

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

//devo togliere le mosse e le operazioni non devono stampare
static int	compare_amd_move(t_push_swap *ps, char *op)
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

static int	read_move(t_push_swap *ps)
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

static int	init_stacks(t_push_swap *ps, char **new_argv)
{
	int	size;

	size = 0;
	while (new_argv[size])
		size++;
	if (memory_alloc(size, ps))
		return (1);
	argv_to_stack(size, new_argv, ps);
	ps->original_size = ps->size_a;
	normalize_stack(ps);
	return (0);
}

int main(int argc, char **argv)
{
    t_push_swap ps;
    char        **new_argv;
    int         size;

    if (argc < 2)
        return (0);
    new_argv = handle_split(argc, argv);
    if (!new_argv || !new_argv[0])
    {
        if (!new_argv) // Se handle_split ha fallito (es. errore malloc o stringa vuota)
            write(2, "Error\n", 6);
        return (free_split(new_argv), 0);
    }
    
    // Calcoliamo la vera dimensione di new_argv per la tua funzione
    size = 0;
    while (new_argv[size])
        size++;

    // Adesso passiamo 'size' e 'new_argv' alla tua parse_input originale
    if (parse_input(size, new_argv))
    {
        write(2, "Error\n", 6);
        free_split(new_argv);
        return (1);
    }

    if (init_stacks(&ps, new_argv)) // init_stacks userà lo stesso 'size' internamente
    {
        write(2, "Error\n", 6);
        free_split(new_argv);
        return (1);
    }

    if (read_move(&ps))
    {
        write(2, "Error\n", 6);
        free(ps.stack_a);
        free(ps.stack_b);
        free_split(new_argv);
        return (1);
    }
    check_result(&ps);
    free_split(new_argv);
    return (0);
}
