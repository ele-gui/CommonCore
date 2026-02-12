/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/12 12:44:54 by elguiduc         ###   ########.fr       */
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

/* FUNCTIONS */
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

void	sort_3(t_push_swap *ps);
void	sort_5(t_push_swap *ps);
void	sa(t_push_swap *ps);
void	sb(t_push_swap *ps);
void	ss(t_push_swap *ps);
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);
void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rrr(t_push_swap *ps);

#endif