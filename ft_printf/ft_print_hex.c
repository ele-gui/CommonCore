/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:53:45 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/15 10:21:15 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr_n(unsigned long nb, char *base)
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
	unsigned long nb;
	
	nb = (unsigned int)n;
	if (nb == 0)
        return write(1, "0", 1);
	return (ft_putnbr_n(nb, "0123456789ABCDEF"));
}

int	ft_print_hex_low(int n)
{
	unsigned long nb;
	
	nb = (unsigned int)n;
	if (nb== 0)
        return write(1, "0", 1);
	return (ft_putnbr_n(nb, "0123456789abcdef"));
}


// void	test_hex(unsigned long long n)
// {
// 	int	ret_ft;
// 	int	ret_printf;

// 	printf("\n==============================\n");
// 	printf("VALORE DECIMALE: %llu\n", n);

// 	/* ----- HEX UPPERCASE ----- */
// 	printf("\n[ HEX UPPERCASE ]\n");

// 	printf("ft_print_hex_up  : ");
// 	ret_ft = ft_print_hex_up(n);
// 	printf(" | return = %d\n", ret_ft);

// 	printf("printf(\"%%X\")     : ");
// 	ret_printf = printf("%X", (unsigned int)n);
// 	printf(" | return = %d\n", ret_printf);

// 	/* ----- HEX LOWERCASE ----- */
// 	printf("\n[ HEX LOWERCASE ]\n");

// 	printf("ft_print_hex_low : ");
// 	ret_ft = ft_print_hex_low(n);
// 	printf(" | return = %d\n", ret_ft);

// 	printf("printf(\"%%x\")     : ");
// 	ret_printf = printf("%x", (unsigned int)n);
// 	printf(" | return = %d\n", ret_printf);

// 	printf("\n");
// }

// /* ===== MAIN ===== */

// int	main(void)
// {
// 	printf("===== CONFRONTO ft_print_hex VS printf =====\n");

// 	/* Casi base */
// 	test_hex(0);
// 	test_hex(1);
// 	test_hex(2);
// 	test_hex(9);
// 	test_hex(10);
// 	test_hex(15);

// 	/* Cambio cifra */
// 	test_hex(16);
// 	test_hex(17);
// 	test_hex(31);
// 	test_hex(32);

// 	/* Valori comuni */
// 	test_hex(42);
// 	test_hex(100);
// 	test_hex(255);
// 	test_hex(256);
// 	test_hex(4096);
// 	test_hex(48879);

// 	/* Limiti unsigned int */
// 	test_hex(UINT_MAX);
// 	test_hex(UINT_MAX - 1);

// 	/* Valori grandi (cast a unsigned int per printf) */
// 	test_hex(4294967295ULL);
// 	test_hex(4294967294ULL);

// 	printf("\n===== FINE TEST =====\n");
// 	return (0);
// }