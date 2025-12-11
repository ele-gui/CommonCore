/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:21:07 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/11 14:39:01 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_ptr( void *ptr)
{
	long	len;
	
	ft_putstr_fd("0x", 1);
	len = ft_print_hex_low((long)ptr);
	return ((int)len);
}

int	main(void)
{
	void	*ptr = "";
	int	ret_up;
	
	printf("funzione vera:          %p\n", ptr);
	/* stampa con la funzione da testare */
    printf("ft_print_hex_up output: ");
	fflush(stdout);               /* fondamentale se ft_print_* usa write(2) */
    ret_up = ft_print_ptr(ptr);
    printf("\n"); /* la funzione ft_print_hex_up non stampa newline */
}