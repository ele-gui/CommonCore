/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:24:55 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/09 14:04:31 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//scrive il numero ma non controlla il meno
static void	ft_putnbr_n(long int nb, char *base, int len)
{
	if (nb < len)
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_n(nb / len, base, len);
		ft_putnbr_n(nb % len, base, len);
	}
}
//controlla che sia una base accettabile
//senza doppioni e senza "+" e "-"
static int	controllo_doppioni(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) < 2)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		len;

	if (!controllo_doppioni(base))
		return ;
	len = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_putnbr_n(nb, base, len);
}

// int	main()
// {
// 	char	*base = "0123456789ABCDEF";
// 	int		numero = 17;	
// 	int		len;

// 	len = ft_strlen(base);
// 	printf("lunghezza base: %d\n", len);
// 	ft_putnbr_base(numero, base);
// 	write(1, "\n", 1);
// 	return (0);
// }