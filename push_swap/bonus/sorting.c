/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:50:24 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/22 15:49:15 by elguiduc         ###   ########.fr       */
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
static void	sort_general(t_push_swap *ps)
{
	t_chunk	chunk;

	chunk = chunk_division(ps);
	push_to_b(ps, chunk);
	push_to_a(ps);
}

//unisco tutti i metodi
void	sort(t_push_swap *ps)
{
	if (is_sorted(ps))
		return ;
	if (ps->size_a == 2)
		sa(ps);
	else if (ps->size_a <= 20)
		mini_sort(ps);
	else
		sort_general(ps);
}
