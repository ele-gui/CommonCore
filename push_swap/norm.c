/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:44:37 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/18 16:55:59 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//copio array
static int	*copy_array(int *arr, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

//prendo un numero e conto quanti elementi sono piu' piccoli di lui
//poi gli assegno quell'indice
void	normalize_stack(t_push_swap *ps)
{
	int	*copy;
	int	i;
	int	j;
	int	count;

	copy = copy_array(ps->stack_a, ps->size_a);
	if (!copy)
		return ;
	i = 0;
	while (i < ps->size_a)
	{
		count = 0;
		j = 0;
		while (j < ps->size_a)
		{
			if (copy[j] < copy[i])
				count++;
			j++;
		}
		ps->stack_a[i] = count;
		i++;
	}
	free(copy);
}
