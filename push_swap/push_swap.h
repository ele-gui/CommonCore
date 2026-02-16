/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/16 16:11:48 by elguiduc         ###   ########.fr       */
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

typedef struct s_chunk
{
	int	count;
	int	size;
}	t_chunk;

/* FUNCTIONS */
int	push_to_b(t_push_swap *ps, t_chunk chunk)
;
int	min_cost_b(t_push_swap *ps, int index)
;
int	sort(t_push_swap *ps)
;
int	is_sorted(t_push_swap *ps)
;
t_chunk	chunk_division(t_push_swap *ps)
;
int	push_to_a(t_push_swap *ps)
;
//push chunk to b
// int	push_to_b(t_push_swap *ps, t_chunk chunk);

//normalize stack
void	normalize_stack(t_push_swap *ps);

//mini sort < 20
int		mini_sort(t_push_swap *ps);

//utils
int		memory_alloc(int argc, t_push_swap *ps);
void	argv_to_stack(int argc, char **argv, t_push_swap *ps);
long	ft_atol(const char *nptr);
int		min(t_push_swap *ps);
int		max(int a, int b);

//print stack DA TOGLIERE
void	print_stack(t_push_swap *ps);

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