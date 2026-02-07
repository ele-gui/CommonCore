/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:28 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/07 15:13:59 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa, pb



// e dentro la funzione accedi ai dati con:
// ps->stack_a
// ps->stack_b
// ps->size_a
// ps->size_b

//prende il primo el di B e lo mette in cima ad A.
// se B e' vuoto non fa niente
void	pa(t_push_swap *ps)
{
	int	i;

	if (ps->size_b == 0)
		return ;

	//devo far scorrere gli indici di A
	i = ps->size_a;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	//riempio stack_a[0] con il primo elemento di B
	ps->stack_a[0] = ps->stack_b[0];
	//devo far scorrere gli indici di B, sovrascrivendo il primo el con il secondo
	i = 0;
	while (i < ps->size_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	//aggiorno le dimensioni
	ps->size_a++;
	ps->size_b--;
}

//prende il primo el di A e lo mette in cima a B
void	pb(t_push_swap *ps)
{
	int i;

	if (ps->size_a == 0)
		return ;
	i = ps->size_b;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	i = 0;
	while (i < ps->size_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->size_a--;
	ps->size_b++;
}
