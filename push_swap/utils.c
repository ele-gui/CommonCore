/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:39:22 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/21 16:51:16 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!s || len + 1 == 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

//usato in sort_small
int	min(t_push_swap *ps)
{
	int	minimo;
	int	i;

	i = 0;
	minimo = ps->stack_a[0];
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] < minimo)
			minimo = ps->stack_a[i];
		i++;
	}
	return (minimo);
}

// asci to int. serve in argv_to_stack e check_limits
long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

//colego ps->stack_a a argv
void	argv_to_stack(int size, char **argv, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ps->stack_a[i] = ft_atol(argv[i]);
		i++;
	}
}

// alloco la memoria per stack_a NON FUNZIONA
int	memory_alloc(int size, t_push_swap *ps)
{
	ps->size_b = 0;
	ps->size_a = size;
	if (ps->size_a <= 0)
		return (1);
	ps->stack_a = malloc(sizeof(int) * ps->size_a);
	ps->stack_b = malloc(sizeof(int) * ps->size_a);
	if (!ps->stack_a || !ps->stack_b)
	{
		free(ps->stack_a);
		free(ps->stack_b);
		return (1);
	}
	return (0);
}
