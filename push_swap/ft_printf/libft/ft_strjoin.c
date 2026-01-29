/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:38:22 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:20 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	char	s1[] = "42";
// 	char	s2[] = "000";
// 	char	*new_string;

// 	new_string = ft_strjoin(s1, s2);
// 	printf("%s + %s = %s\n", s1, s2, new_string);
// 	return (0);
// }