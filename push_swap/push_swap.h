/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/14 14:51:20 by elguiduc         ###   ########.fr       */
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
}	t_push_swap;

typedef struct s_chunk
{
	int	count;
	int	size;
}	t_chunk;

/* FUNCTIONS */
int move_to_top_b_and_push_a(t_push_swap *ps)
;
int	calculate_cost_and_move(t_push_swap *ps, int index)
;
int push_chunk_to_b(t_push_swap *ps, t_chunk chunk)
;
int push_chunk_to_b_new(t_push_swap *ps, t_chunk chunk)
;
int find_index_in_range(int *stack, int size, int start, int end)
;
char	**handle_split(int argc, char **argv)
;
int	mini_sort(t_push_swap *ps)
;
int	sort_20(t_push_swap *ps)
;
int	is_sorted(t_push_swap *ps)
;
int sort_general(t_push_swap *ps)
;
int sort(t_push_swap *ps)
;
int	move_cheapest(t_push_swap *ps, int index)
;
int	calculate_cost_min(t_push_swap *ps, int index)
;
t_chunk	chunk_division(t_push_swap *ps)
;
int	*copy_array(int *arr, int size);
void	sort_array(int *arr, int size);
int	find_index(int *sorted, int size, int value);
void	normalize_stack(t_push_swap *ps);
int	is_sorted(t_push_swap *ps);
int	memory_alloc(int argc, t_push_swap *ps);
long	ft_atol(const char *nptr);
void	argv_to_stack(int argc, char **argv, t_push_swap *ps);
int		parse_input(int argc, char **argv);
void	print_stack(t_push_swap *ps);
int	max(int a, int b);
int	min(t_push_swap *ps);
int		main(int argc, char **argv);

int	sort_3(t_push_swap *ps);
int	sort_5(t_push_swap *ps);
int	mini_sort(t_push_swap *ps);
int	sa(t_push_swap *ps);
int	sb(t_push_swap *ps);
int	ss(t_push_swap *ps);
int	pa(t_push_swap *ps);
int	pb(t_push_swap *ps);
int	ra(t_push_swap *ps);
int	rb(t_push_swap *ps);
int	rr(t_push_swap *ps);
int	rra(t_push_swap *ps);
int	rrb(t_push_swap *ps);
int	rrr(t_push_swap *ps);

#endif