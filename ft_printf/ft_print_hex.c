/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:53:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/10 19:43:05 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_putnbr_n(unsigned long long nb, char *base)
{
	int	count;

	if (nb < 16)
	{
		write(1, &base[nb], 1);
		return (1);
	}
		
	else
	{
		count = ft_putnbr_n(nb / 16, base);
		count += ft_putnbr_n(nb % 16, base);
	}
	return (count);
}

int	ft_print_hex_up(int n)
{
	unsigned int	u_nb;
	
	u_nb = (unsigned int)n;
	return (ft_putnbr_n(u_nb, "0123456789ABCDEF"));
}

int	ft_print_hex_low(int n)
{
	unsigned int	u_nb;
	
	u_nb = (unsigned int)n;
	return (ft_putnbr_n(u_nb, "0123456789abcdef"));
}

// int main(void)
// {
//     int tests[] = {
//         0, 1, 10, 15, 16, 255, 256,
//         1024, 4095, 65535,
//         -1, -42,
//         INT_MAX, INT_MIN,
//         123456, 0xABCDEF, 0x123456
//     };
//     const int n_tests = sizeof(tests) / sizeof(tests[0]);

//     printf("===== TEST ft_print_hex_up / ft_print_hex_low =====\n\n");

//     for (int i = 0; i < n_tests; ++i)
//     {
//         int n = tests[i];
//         char expect_up[64];
//         char expect_low[64];
//         int exp_len_up;
//         int exp_len_low;
//         int ret_up;
//         int ret_low;

//         /* Calcola le stringhe e le lunghezze attese usando snprintf.
//            snprintf restituisce il numero di caratteri (senza '\0'). */
//         exp_len_up  = snprintf(expect_up, sizeof(expect_up), "%X", (unsigned int)n);
//         exp_len_low = snprintf(expect_low, sizeof(expect_low), "%x", (unsigned int)n);

//         printf("---- Test %2d: n = %d (0x%X unsigned view) ----\n", i + 1, n, (unsigned int)n);

//         /* stampa la stringa attesa (comportamento printf "vero") */
//         printf("expected (printf %%X): %s\n", expect_up);

//         /* stampa con la funzione da testare */
//         printf("ft_print_hex_up output: ");
//         ret_up = ft_print_hex_up(n);
//         printf("\n"); /* la funzione ft_print_hex_up non stampa newline */

//         /* mostra i risultati del confronto lunghezze */
//         printf(" expected_len: %d, ft_return: %d -> %s\n",
//             	exp_len_up, ret_up, (exp_len_up == ret_up) ? "OK" : "KO");

//         /* stessa cosa per lowercase */
//         printf("expected (printf %%x): %s\n", expect_low);
//         printf("ft_print_hex_low output: ");
//         ret_low = ft_print_hex_low(n);
//         printf("\n");
//         printf(" expected_len: %d, ft_return: %d -> %s\n\n",
//                exp_len_low, ret_low, (exp_len_low == ret_low) ? "OK" : "KO");
//     }

//     printf("===== TEST COMPLETATI =====\n");
//     return 0;
// }

