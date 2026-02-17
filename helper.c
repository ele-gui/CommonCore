/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:45:54 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/17 10:02:09 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//funzioni helper

#include "push_swap.h"

//controllo se lo stack e' ordinato
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

//cerco index massimo
int	find_max_index(t_push_swap *ps)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = ps->stack_b[0];
	max_index = 0;
	while (i < ps->size_b)
	{
		if (ps->stack_b[i] > max)
		{
			max = ps->stack_b[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}



int final_rotation(t_push_swap *ps)
{
    int mosse;
    int min_pos;
    int i;
    
    mosse = 0;
    min_pos = 0;
    i = 0;
    // Trova la posizione del minimo
    while (i < ps->size_a)
    {
        if (ps->stack_a[i] < ps->stack_a[min_pos])
            min_pos = i;
        i++;
    }
    // Porta il minimo in cima con la rotazione più breve
    if (min_pos <= ps->size_a / 2)
    {
        while (min_pos > 0)
        {
            mosse += ra(ps);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < ps->size_a)
        {
            mosse += rra(ps);
            min_pos++;
        }
    }
    return (mosse);
}

//trova la pasizione del minimo in stack_a
int	find_min_position_a(t_push_swap *ps)
{
	int	i;
	int	min_pos;

	i = 0;
	min_pos = 0;
	while(i < ps->size_a)
	{
		if (ps->stack_a[i] < ps->stack_a[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

//trova la posizione del massimo in stack_a
int	find_max_position_a(t_push_swap *ps)
{

	int	i;
	int	max_pos;

	i = 0;
	max_pos = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] > ps->stack_a[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}