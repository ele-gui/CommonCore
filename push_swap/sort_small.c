/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:44:26 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/17 10:19:57 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //ordina 3 elementi
int	sort_3(t_push_swap *ps)
{
	int	mosse;

	mosse = 0;
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
		mosse += sa(ps);
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		mosse += sa(ps);
		mosse += rra(ps);
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		mosse += ra(ps);
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{
		mosse += sa(ps);
		mosse += ra(ps);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
		mosse += rra(ps);
	return (mosse);
}


// Trova dove inserire in B mantenendo B ordinato decrescente
static int find_insert_pos_b(t_push_swap *ps, int value)
{
    int i;
    int best_pos;
    int best_value;

    // B vuoto → posizione 0
    if (ps->size_b == 0)
        return (0);

    i = 0;
    best_pos = -1;
    best_value = -1;

    // Cerca il più grande valore in B che è ancora < value
    while (i < ps->size_b)
    {
        if (ps->stack_b[i] < value && ps->stack_b[i] > best_value)
        {
            best_value = ps->stack_b[i];
            best_pos = i;
        }
        i++;
    }

    // Se non trovato → value è il minimo di tutti
    // deve andare DOPO il massimo di B (in fondo)
    if (best_pos == -1)
    {
        // Trova il massimo in B
        i = 0;
        best_pos = 0;
        while (i < ps->size_b)
        {
            if (ps->stack_b[i] > ps->stack_b[best_pos])
                best_pos = i;
            i++;
        }
        // Va subito dopo il massimo
        best_pos = (best_pos + 1) % ps->size_b;
    }

    return (best_pos);
}

// Calcola costo totale per pushare stack_a[i] in B
static int calc_cost(t_push_swap *ps, int i)
{
    int cost_a;
    int cost_b;
    int target_b;

    // Costo per portare stack_a[i] in cima ad A
    if (i <= ps->size_a / 2)
        cost_a = i;
    else
        cost_a = ps->size_a - i;

    // Costo per posizionare in B
    target_b = find_insert_pos_b(ps, ps->stack_a[i]);
    if (target_b <= ps->size_b / 2)
        cost_b = target_b;
    else
        cost_b = ps->size_b - target_b;

    return (cost_a + cost_b);
}

// Trova l'elemento di A che costa meno pushare in B
static int find_cheapest(t_push_swap *ps)
{
    int i;
    int best_pos;
    int min_cost;
    int cost;

    i = 0;
    best_pos = 0;
    min_cost = INT_MAX;

    while (i < ps->size_a)
    {
        cost = calc_cost(ps, i);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_pos = i;
        }
        i++;
    }
    return (best_pos);
}

// Push tutto in B mantenendo B ordinato decrescente
int push_all_to_b(t_push_swap *ps)
{
    int mosse;
    int cheapest;
    int target_b;

    mosse = 0;

    while (ps->size_a > 3)
    {
        // Trova l'elemento più economico da pushare
        cheapest = find_cheapest(ps);

        // Porta in cima ad A
        if (cheapest <= ps->size_a / 2)
        {
            while (cheapest > 0)
            {
                mosse += ra(ps);
                cheapest--;
            }
        }
        else
        {
            while (cheapest < ps->size_a)
            {
                mosse += rra(ps);
                cheapest++;
            }
        }

        // Trova dove inserire in B
        target_b = find_insert_pos_b(ps, ps->stack_a[0]);

        // Posiziona B
        if (target_b <= ps->size_b / 2)
        {
            while (target_b > 0)
            {
                mosse += rb(ps);
                target_b--;
            }
        }
        else
        {
            while (target_b < ps->size_b)
            {
                mosse += rrb(ps);
                target_b++;
            }
        }

        mosse += pb(ps);
    }

    mosse += sort_3(ps);
    return (mosse);
}

// Push da B ad A - B è già ordinato decrescente
// quindi il massimo è sempre vicino alla cima!
int push_to_a(t_push_swap *ps)
{
    int mosse;
    int max_index;

    mosse = 0;
    while (ps->size_b > 0)
    {
        // Porta il massimo di B in cima
        max_index = find_max_index(ps);

        if (max_index <= ps->size_b / 2)
        {
            while (max_index > 0)
            {
                mosse += rb(ps);
                max_index--;
            }
        }
        else
        {
            while (max_index < ps->size_b)
            {
                mosse += rrb(ps);
                max_index++;
            }
        }

        // Trova dove inserire in A (stack circolare ordinato)
        int target = find_insert_pos_a(ps, ps->stack_b[0]);

        if (target <= ps->size_a / 2)
        {
            while (target > 0)
            {
                mosse += ra(ps);
                target--;
            }
        }
        else
        {
            while (target < ps->size_a)
            {
                mosse += rra(ps);
                target++;
            }
        }

        mosse += pa(ps);
    }
    return (mosse);
}

// Trova dove inserire value in A (A è ordinato circolarmente crescente)
int find_insert_pos_a(t_push_swap *ps, int value)
{
    int i;
    int min_pos;
    int next;

    // Cerca il posto giusto: vogliamo che stack_a[pos-1] < value < stack_a[pos]
    i = 0;
    while (i < ps->size_a)
    {
        next = (i + 1) % ps->size_a;
        // Caso normale: value si inserisce tra i e next
        if (ps->stack_a[i] < value && value < ps->stack_a[next])
            return (next);
        // Caso wrap-around: siamo al massimo, value va dopo
        if (ps->stack_a[i] > ps->stack_a[next])
        {
            // value è maggiore del massimo OPPURE minore del minimo
            if (value > ps->stack_a[i] || value < ps->stack_a[next])
                return (next);
        }
        i++;
    }

    // Fallback: trova il minimo
    min_pos = find_min_position_a(ps);
    return (min_pos);
}



// //cerco i 3 elementi migliori di stack_a, sono i 3 piu' grandi
// void	find_best_3(t_push_swap *ps, int *keep)
// {
// 	int	i;
// 	int	max1;
// 	int	max2;
// 	int	max3;
	
// 	i = 0;
// 	max1 = -1;
// 	max2 = -1;
// 	max3= -1;
// 	while (i < ps->size_a)
// 	{
// 		if (ps->stack_a[i] > max1)
// 		{
// 			max3 = max2;
// 			max2 = max1;
// 			max1 = ps->stack_a[i];
// 		}
// 		else if (ps->stack_a[i] > max2)
// 		{
// 			max3 = max2;
// 			max2 = ps->stack_a[i];
// 		}
// 		else if (ps->stack_a[i] > max3)
// 			max3 = ps->stack_a[i];
// 		i++;
// 	}
// 	keep[0] = max1;
// 	keep[1] = max2;
// 	keep[2] = max3;	
// }


// //pusho tutto in b tranne tre elementi
// int push_all_but_3(t_push_swap *ps)
// {
//     int mosse;
//     int keep[3];
//     int rotations;
    
//     mosse = 0;
//     rotations = 0;
//     find_best_3(ps, keep);
    
//     while (ps->size_a > 3)
//     {
//         if (ps->stack_a[0] == keep[0] || 
//             ps->stack_a[0] == keep[1] || 
//             ps->stack_a[0] == keep[2])
//         {
//             mosse += ra(ps);
//             rotations++;
            
//             // ANTI LOOP: se ho ruotato tutto lo stack senza trovare niente
//             // significa che i 3 da tenere non sono ancora allineati
//             if (rotations >= ps->size_a)
//                 rotations = 0;
//         }
//         else
//         {
//             mosse += pb(ps);
//             rotations = 0;  // Reset contatore
            
//             if (ps->size_b >= 2 && ps->stack_b[0] < ps->stack_b[1])
//                 mosse += rb(ps);
//         }
//     }
    
//     mosse += sort_3(ps);
    
//     return (mosse);
// }


// int	find_insert_position(t_push_swap *ps, int value)
// {
// 	int	i;
// 	int	target_pos;
// 	int	target_value;
	
// 	i = 0;
// 	target_pos = -1;
// 	target_value = ps->original_size;
// 	//cerco il piu' piccolo valore in a che e' maggiore di value
// 	while (i < ps->size_a)
// 	{
// 		if (ps->stack_a[i] > value && ps->stack_a[i] < target_value)
// 		{
// 			target_value = ps->stack_a[i];
// 			target_pos = i;
// 		}
// 		i++;
// 	}
// 	//se non ho trovatu nulla => value e' il massimo
// 	//inserisco dopo il minimo (all'inizio dello stack ordinato)
// 	if (target_pos == -1)
// 		target_pos = find_min_position_a(ps);
// 	return (target_pos);
// }


// //push to a
// int	push_to_a(t_push_swap *ps)
// {
// 	int	mosse;
// 	int	max_index;
// 	int	target_pos;
	
// 	mosse = 0;
// 	while (ps->size_b > 0)
// 	{
// 		//trovo max in b
// 		max_index = find_max_index(ps);
// 		//lo porto in cima
// 		if (max_index <= ps->size_b / 2)
// 		{
// 			while (max_index > 0)
// 			{
// 				mosse += rb(ps);
// 				max_index--;
// 			}
// 		}
// 		else
// 		{
// 			while (max_index < ps->size_b)
// 			{
// 				mosse += rrb(ps);
// 				max_index++;
// 			}
// 		}

// 		//trovo dove va in a
// 		target_pos = find_insert_position(ps, ps->stack_b[0]);

// 		//ruoto a
// 		if (target_pos <= ps->size_a / 2)
// 		{
// 			while (target_pos > 0)
// 			{
// 				mosse += ra(ps);
// 				target_pos--;
// 			}
// 		}
// 		else
// 		{
// 			while (target_pos < ps->size_a)
// 			{
// 				mosse += rra(ps);
// 				target_pos++;
// 			}
// 		}
// 		mosse += pa(ps);
// 	}
// 	return (mosse);
// }