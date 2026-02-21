/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 17:06:11 by elguiduc         ###   ########.fr       */
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
void	push_to_b(t_push_swap *ps, t_chunk chunk);
void	push_to_a(t_push_swap *ps);
char	*ft_strdup(const char *s);
void	free_split(char **split);
int		min_cost_b(t_push_swap *ps, int index);
void	sort(t_push_swap *ps);
int		is_sorted(t_push_swap *ps);
t_chunk	chunk_division(t_push_swap *ps);
void	normalize_stack(t_push_swap *ps);
void		mini_sort(t_push_swap *ps);
int		memory_alloc(int argc, t_push_swap *ps);
void	argv_to_stack(int argc, char **argv, t_push_swap *ps);
long	ft_atol(const char *nptr);
int		min(t_push_swap *ps);
int		parse_input(int argc, char **argv);
char	**handle_split(int argc, char **argv);
void		sa(t_push_swap *ps);
void		sb(t_push_swap *ps);
void		ss(t_push_swap *ps);
void		pa(t_push_swap *ps);
void		pb(t_push_swap *ps);
void		ra(t_push_swap *ps);
void		rb(t_push_swap *ps);
void		rr(t_push_swap *ps);
void		rra(t_push_swap *ps);
void		rrb(t_push_swap *ps);
void		rrr(t_push_swap *ps);

#endif