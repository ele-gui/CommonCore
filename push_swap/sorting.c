/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/11 11:44:51 by elguiduc         ###   ########.fr       */
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

