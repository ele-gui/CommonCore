/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:44:37 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/11 15:05:27 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *arr, int size)
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

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i- 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

//cerca value dentro un array gia' ordinato e restituisce l'indice di dove lo trova
int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

//crea una mappa con gli indici
void	normalize_stack(t_push_swap *ps)
{
	int	*sorted;
	int	i;

	sorted = copy_array(ps->stack_a, ps->size_a);
	if (!sorted)
		return ;
	sort_array(sorted, ps->size_a);
	i = 0;
	while (i < ps->size_a)
	{
		ps->stack_a[i] = find_index(sorted, ps->size_a, ps->stack_a[i]);
		i++;
	}
	free(sorted);	
}
