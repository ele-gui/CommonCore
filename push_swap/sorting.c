/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/13 22:07:09 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is_sorted(t_push_swap *ps)
// sort(t_push_swap *ps)

#include "push_swap.h"

int	is_sorted(t_push_swap *ps)
{
	int i;
	
	if (ps->size_a <= 1)
		return (1);
	i = 0;
	while (i < ps->size_a - 1)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int find_max_index(int *stack, int size)
{
    int i = 0;
    int max = stack[0];
    int index = 0;

    for (i = 1; i < size; i++)
    {
        if (stack[i] > max)
        {
            max = stack[i];
            index = i;
        }
    }
    return index;
}

int move_to_top_b(t_push_swap *ps, int index)
{
    int mosse = 0;

    if (index < 0 || index >= ps->size_b)
        return 0;

    // Se l'elemento è nella metà superiore, ruota verso l'alto
    if (index <= ps->size_b / 2)
    {
        while (index-- > 0)
            mosse += rb(ps); // ruota B verso l'alto
    }
    // Altrimenti ruota verso il basso
    else
    {
        int rotations = ps->size_b - index;
        while (rotations-- > 0)
            mosse += rrb(ps); // ruota B verso il basso
    }
    return mosse;
}

int sort_general(t_push_swap *ps)
{
	t_chunk chunk;
	int mosse;
	int index;

	mosse = 0;
	chunk = chunk_division(ps);
	while (ps->size_a > 0)
		mosse +=push_chunk_to_b(ps, chunk);
	while (ps->size_b > 0)
	{
		index = find_max_index(ps->stack_b, ps->size_b);
		mosse += move_to_top_b(ps, index);
		mosse += pa(ps);
	}
	return (mosse);
}

int sort(t_push_swap *ps)
{
	while (!is_sorted(ps))
	{
		if (ps->size_a == 2)
			return (sa(ps));
		else if (ps->size_a <= 20)
			return (sort_20(ps));
		else
			return (sort_general(ps));
	}
	return (0);
}
