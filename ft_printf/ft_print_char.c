/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:41:01 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/11 20:21:32 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

//mi deve stampare anche %
int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int ft_print_percent()
{
	ft_putchar_fd('%', 1);
	return (1);
}