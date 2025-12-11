/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:41:20 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/11 15:15:12 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	char	a;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		a = n + '0';
		write(fd, &a, 1);
	}
}

//%d numero in base 10, NON decimale, %i hanno lo stesso output
int	ft_print_dec_int(int n)
{
	ft_putnbr_fd(n, 1);
	return(ft_len_int(n));
}
//%u
int	ft_print_uint(unsigned int n)
{
	ft_putnbr_uint_fd(n, 1);
	return (ft_len_uint(n));
}


int main(void)
{
    int d_tests[] = {0, 1, -1, 42, -42, INT_MAX, INT_MIN};
    unsigned int u_tests[] = {0, 1, 42, UINT_MAX};
    size_t i;
    size_t d_count = sizeof(d_tests) / sizeof(d_tests[0]);
    size_t u_count = sizeof(u_tests) / sizeof(u_tests[0]);

    printf("======== TEST %%d / %%i (signed int) ========\n\n");

    for (i = 0; i < d_count; i++)
    {
        int n = d_tests[i];
        int ret_std;
        int ret_my;

        printf("Test %zu:\n", i + 1);

        /* stampa la riga con printf e salva la lunghezza ritornata (lunghezza dell'intera riga) */
        ret_std = printf(" printf:           |%d|", n);
        printf(" (len = %d)\n", (int)ft_len_int(n));

        /* ora la riga della tua funzione; sincronizziamo stdout prima della write */
        printf(" ft_print_dec_int: |");
        fflush(stdout);               /* fondamentale se ft_print_* usa write(2) */
        ret_my = ft_print_dec_int(n);
        printf("| (len = %d)\n\n", ret_my);
    }

    printf("======== TEST %%u (unsigned int) ========\n\n");

    for (i = 0; i < u_count; i++)
    {
        unsigned int n = u_tests[i];
        int ret_std;
        int ret_my;

        printf("Test %zu:\n", i + 1);

        /* riga completa di printf */
        ret_std = printf(" printf:          |%u|", n);
		printf(" (len = %d)\n", (int)ft_len_uint(n));

        /* riga della tua funzione */
        printf(" ft_print_uint:   |");
        fflush(stdout);
        ret_my = ft_print_uint(n);
        printf("| (len = %d)\n\n", ret_my);
    }

    return 0;
}