/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:07 by elguiduc          #+#    #+#             */
/*   Updated: 2026/02/09 13:52:31 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gestisco gli errori dell'input
//parse_input(int argc, char **argv, t_push_swap *ps)

#include "push_swap.h"

//controllo se tutti gli argomenti sono numeri
// int	num_control(char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			ft_printf("%d\n", argv[i][j]); // non funziona 1 = 49. devo usare split?
// 			if (argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == ' ')
// 				j++;
// 			ft_printf("%d\n", argv[i][j]);
			
// 			if (!ft_isdigit(argv[i][j]))
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	num_control(char **argv)
{
	char	**split;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (1);
	
}



int	doppioni(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] != argv[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	parse_input(int argc, char **argv)
{

	//controllo se ci sono abbastanza argomenti
	if (argc < 2)
	{
		ft_printf("---ERRORE: MENO DI 2 ELEMENTI---\n");
		return (1);
	}
	if (!num_control(argv))
	{
		ft_printf("---ERRORE: NON TUTTI INT---\n");
		return (1);
	}

	if (!doppioni(argv))
	{
		ft_printf("---ERRORE: DOPPIONI---\n");
		return (1);
	}
	
	ft_printf("INPUT PARSED\n");
	return (0);
}


