/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:50:24 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/17 10:13:15 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



//unisco tutti i metodi
int sort(t_push_swap *ps)
{
    int mosse;

    mosse = 0;
    if (is_sorted(ps))
        return (0);
    if (ps->size_a == 2)
        return (sa(ps));
    if (ps->size_a <= 3)
        return (sort_3(ps));

    mosse += push_all_to_b(ps);
    mosse += push_to_a(ps);
    mosse += final_rotation(ps);
    return (mosse);
}
