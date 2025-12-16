/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:21:07 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/16 09:57:03 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	len += ft_print_str("0x");
	len += ft_putnbr_n(n, "0123456789abcdef");
	return (len);
}

/* ===== FUNZIONE DI TEST ===== */

// void	test_ptr(char *desc, void *ptr)
// {
// 	int	ret_ft;
// 	int	ret_printf;

// 	printf("\n==============================\n");
// 	printf("TEST: %s\n", desc);

// 	printf("\nft_print_ptr : ");
// 	fflush(stdout);
// 	ret_ft = ft_print_ptr(ptr);
// 	printf("\n| return = %d\n", ret_ft);

// 	printf("printf(\"%%p\")  : ");
// 	fflush(stdout);
// 	ret_printf = printf("%p", ptr);
// 	printf("\n| return = %d\n", ret_printf);
// }

/* ===== MAIN ===== */

// int	main(void)
// {
// 	int		a = 42;
// 	char	c = 'x';
// 	char	str[] = "hello";
// 	int		*heap_int;
// 	void	*null_ptr = NULL;

// 	heap_int = malloc(sizeof(int));
// 	*heap_int = 99;

// 	printf("===== CONFRONTO ft_print_ptr VS printf =====\n");

// 	/* NULL */
// 	test_ptr("NULL pointer", null_ptr);

// 	/* Stack */
// 	test_ptr("address of int (stack)", &a);
// 	test_ptr("address of char (stack)", &c);
// 	test_ptr("address of string (stack)", str);

// 	/* Heap */
// 	test_ptr("address of malloc int", heap_int);

// 	/* Cast espliciti */
// 	test_ptr("cast (void *)0", (void *)0);
// 	test_ptr("cast (void *)1", (void *)1);
// 	test_ptr("cast (void *)-1", (void *)-1);

// 	/* Funzioni */
// 	test_ptr("address of main", &main);
// 	test_ptr("address of test_ptr", &test_ptr);

// 	free(heap_int);
// 	heap_int = NULL; /* buona pratica */

// 	printf("\n===== FINE TEST =====\n");
// 	return (0);
// }