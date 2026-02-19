/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:50:24 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/19 14:00:08 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//controllo se lo stack e' ordinato
int	is_sorted(t_push_swap *ps)
{
	int	i;

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

//metodo per > 20 numeri
static int	sort_general(t_push_swap *ps)
{
	t_chunk	chunk;
	int		mosse;

	mosse = 0;
	chunk = chunk_division(ps);
	mosse += push_to_b(ps, chunk);
	mosse += push_to_a(ps);
	return (mosse);
}

//unisco tutti i metodi
int	sort(t_push_swap *ps)
{
	if (is_sorted(ps))
		return (0);
	if (ps->size_a == 2)
		return (sa(ps));
	else if (ps->size_a <= 20)
		return (mini_sort(ps));
	else
		return (sort_general(ps));
}
