/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:24:21 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:36 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (!s)
		return (NULL);
	new_str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

// static char	test(unsigned int i, char str)
// {
// 	printf("my inner function: index = %d and %c\n", i, str);
// 	return (str);
// }

// int	main(void)
// {
// 	char	str[] = "sono una sirena";
// 	char	*new;

// 	new = ft_strmapi(str, test);
// 	printf("%s\n", new);
// 	return (0);
// }