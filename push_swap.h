/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/17 09:50:33 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_push_swap
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		original_size;
}	t_push_swap;

// typedef struct s_chunk
// {
// 	int	count;
// 	int	size;
// }	t_chunk;

/* FUNCTIONS */
int find_insert_pos_a(t_push_swap *ps, int value)
;
int push_all_to_b(t_push_swap *ps)
;
int	sort(t_push_swap *ps)
;
int	push_all_but_3(t_push_swap *ps)
;
int	sort_3(t_push_swap *ps)
;
int	push_to_a(t_push_swap *ps)
;
int	is_sorted(t_push_swap *ps)
;
int	find_max_index(t_push_swap *ps)
;
int final_rotation(t_push_swap *ps)
;
int	find_min_position_a(t_push_swap *ps)
;
int	find_max_position_a(t_push_swap *ps)
;

//normalize stack
void	normalize_stack(t_push_swap *ps);

//utils
int		memory_alloc(int argc, t_push_swap *ps);
void	argv_to_stack(int argc, char **argv, t_push_swap *ps);
long	ft_atol(const char *nptr);
// int		min(t_push_swap *ps);
// int		max(int a, int b);


//parsing
int		parse_input(int argc, char **argv);
char	**handle_split(int argc, char **argv);

//mosse
int		sa(t_push_swap *ps);
int		sb(t_push_swap *ps);
int		ss(t_push_swap *ps);
int		pa(t_push_swap *ps);
int		pb(t_push_swap *ps);
int		ra(t_push_swap *ps);
int		rb(t_push_swap *ps);
int		rr(t_push_swap *ps);
int		rra(t_push_swap *ps);
int		rrb(t_push_swap *ps);
int		rrr(t_push_swap *ps);

#endif