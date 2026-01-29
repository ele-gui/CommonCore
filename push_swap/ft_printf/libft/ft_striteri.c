/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:19:00 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:17 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//applica 
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	test(unsigned int i, char *str)
// {
// 	printf("index = %d and %s\n", i, str);
// }

// int	main(void)
// {
// 	char	str[] = "0";

// 	ft_striteri(str, test);
// 	return (0);
// }