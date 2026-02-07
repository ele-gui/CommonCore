/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:36:51 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/07 16:45:52 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "ft_printf/ft_printf.h"

typedef struct s_push_swap
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
}	t_push_swap;

void	print_stack(t_push_swap *ps);
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);


#endif