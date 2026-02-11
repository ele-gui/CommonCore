/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:52 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/11 12:25:11 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap ps;

	if (memory_alloc(argc, &ps))
	{
		ft_printf("ERRORE MALLOC\n");
		return (1);
	}
	ft_printf("no malloc error\n");
	argv_to_stack(argc, argv, &ps);
	ft_printf("no conversion error\n");	

	ft_printf("inizio parsing\n");
	if (parse_input(argc, argv))
	{
		ft_printf("---ERRORE NEL PARSING---\n");
		free(ps.stack_a);
		return (1);
	}
	ft_printf("no parsing error\n");
		
	// DEBUG
	ft_printf("prima della normalizzazione:\n");
	print_stack(&ps);

	normalize_stack(&ps);

	ft_printf("dopo la normalizzazione:\n");
	print_stack(&ps);

	// sort(&ps);

	// sort(&ps);
	// if (is_sorted(&ps))
	// {
	// 	ft_printf("stack gia' ordinato\n");
	// 	free(ps.stack_a);
	// 	return (0);
	// }
	// else
	// 	ft_printf("stack non ordinato\n");
	free(ps.stack_a);
	free(ps.stack_b);
	return (0);
}

