/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:48:19 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/22 15:55:29 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

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
void	free_split(char **split);
void	sort(t_push_swap *ps);
int		is_sorted(t_push_swap *ps);
int		memory_alloc(int argc, t_push_swap *ps);
void	argv_to_stack(int argc, char **argv, t_push_swap *ps);
long	ft_atol(const char *nptr);
int		min(t_push_swap *ps);
void	mini_sort(t_push_swap *ps);
int		min_cost_b(t_push_swap *ps, int index);
void	push_to_a(t_push_swap *ps);
int		parse_input(int argc, char **argv);
char	**handle_split(int argc, char **argv);
void	normalize_stack(t_push_swap *ps);
void	push_to_b(t_push_swap *ps, t_chunk chunk);
t_chunk	chunk_division(t_push_swap *ps);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	sb(t_push_swap *ps);
void	sa(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	ra(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rrr(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rra(t_push_swap *ps);
void	pb(t_push_swap *ps);
void	pa(t_push_swap *ps);

#endif