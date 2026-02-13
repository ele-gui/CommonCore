/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:14:41 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/13 21:52:56 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//divisione in chunk
t_chunk	chunk_division(t_push_swap *ps)
{
	t_chunk chunk;

	if (ps->size_a <= 20)
		chunk.count = 1;
	else if (ps->size_a <= 100)
		chunk.count = 5;
	else if (ps->size_a <= 500)
		chunk.count = 12;
	chunk.size = ps->size_a / chunk.count;
	return (chunk);
}

int	calculate_cost_min(t_push_swap *ps, int index)
{
	int cost;

	if (index <= ps->size_a / 2)
		cost = index;
	else
		cost = ps->size_a - index;
	return (cost);
}

int	move_cheapest(t_push_swap *ps, int index)
{
	int cost;
	int mosse;

	mosse = 0;
	cost = calculate_cost_min(ps, index);
	if (index < 0 || index >= ps->size_a)
		return (0);
	if (index <= ps->size_a / 2)
	{
		while (cost > 0)
		{
			mosse +=ra(ps);
			cost--;
		}
	}
	else
	{
		while (cost > 0)
		{
			mosse += rra(ps);
			cost--;
		}
	}
	return (mosse);
}

int find_index_in_range(int *stack, int size, int start, int end)
{
    int i = 0;

    while (i < size)
    {
        if (stack[i] > start && stack[i] < end)
            return i; // primo elemento trovato
        i++;
    }
    return -1; // nessun elemento nel chunk
}

int push_chunk_to_b(t_push_swap *ps, t_chunk chunk)
{
    int mosse = 0;
    int start = 0;
    int end = chunk.size;
    int i, index;

    // finché ci sono elementi in stack A
    while (ps->size_a > 0)
    {
        // trova il primo elemento che rientra nel chunk
        index = -1;
        for (i = 0; i < ps->size_a; i++)
        {
            if (ps->stack_a[i] >= start && ps->stack_a[i] < end)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            mosse += move_cheapest(ps, index);
            mosse += pb(ps);
        }
        else
        {
            // nessun elemento in questo chunk, passa al prossimo
            start = end;
            end += chunk.size;

            if (start >= ps->size_a) // tutti i chunk completati
            {
                // prendi gli eventuali restanti elementi e spingili
                while (ps->size_a > 0)
                {
                    mosse += move_cheapest(ps, 0);
                    mosse += pb(ps);
                }
                break;
            }
        }
    }
    return mosse;
}


// int push_chunk_to_b(t_push_swap *ps, t_chunk chunk) 
// {
// 	int	mosse;
// 	int	start;
// 	int	end;
// 	int	index;

// 	mosse = 0;
// 	start = 0;
// 	end = chunk.size;
// 	while (ps->size_a > 0)
//     {
//         // Assicurati che end non superi il massimo valore normalizzato
//         if (end > ps->size_a)
//             end = ps->size_a;

//         index = find_index_in_range(ps->stack_a, ps->size_a, start, end);

//         if (index != -1)
//         {
//             mosse += move_cheapest(ps, index);
//             mosse += pb(ps);
//         }
//         else
//         {
//             // nessun elemento nel chunk, passa al prossimo
//             start = end;
//             end = start + chunk.size;

//             // se start ha superato il massimo valore normalizzato, esci
//             if (start >= ps->size_a)
//                 break;
//         }
//     }
// 	return (mosse);
// }

