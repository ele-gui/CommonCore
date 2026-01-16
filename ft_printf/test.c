#include "ft_printf.h"
#include "libft/libft.h"
# include <stdio.h>

int main(void)
{
	int	res_mio;
	int	res_vero;

	printf("=====Test c=====\n");
	res_mio = ft_printf("Test c: %c\n", 'A');
	res_vero = printf("Real c: %c\n", 'A');
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test s=====\n");
	res_mio = ft_printf("Test s: %s\n", "Hello 42");
	res_vero = printf("Real s: %s\n", "Hello 42");
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test d/i=====\n");
	res_mio = ft_printf("Test d/i: %d %i\n", -1234, -1234);
	res_vero = printf("Real d/i: %d %i\n", -1234, -1234);
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test u=====\n");
	res_mio = ft_printf("Test u: %u\n", 4294967295u);
	res_vero = printf("Real u: %u\n", 4294967295u);
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test x/X=====\n");
	res_mio = ft_printf("Test x/X: %x %X\n", 255, 255);
	res_vero = printf("Real x/X: %x %X\n", 255, 255);
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test p=====\n");
	int a = 42;
	res_mio = ft_printf("Test p: %p\n", &a);
	res_vero = printf("Real p: %p\n", &a);
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test %%=====\n");
	res_mio = ft_printf("Test %%: %%\n");
	res_vero = printf("Real %%: %%\n");
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n\n", res_vero);

	printf("=====Test stringa NULL=====\n");
	char *null_str = NULL;
	res_mio = ft_printf("Test NULL: %s\n", null_str);
	res_vero = printf("Real NULL: %s\n", null_str);
	printf("Return ft_printf: %d\n", res_mio);
	printf("Return printf:    %d\n", res_vero);

	printf("=====Test mix=====\n");
	//char *str_mix = "%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%";
	res_mio  = ft_printf("Test mix: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0  , 0, 42, 0);
    res_vero = printf("Real mix: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0  , 0, 42, 0);
    printf("Return ft_printf: %d\n", res_mio);
    printf("Return printf:    %d\n", res_vero);

    return (0);
}
