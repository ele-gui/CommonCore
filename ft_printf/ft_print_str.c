/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:21 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/11 20:46:37 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if(!str)
		str = "(null)";
	while (*str)
	{
		ft_print_char(*str++);
		len++;
	}
	return (len);
}
