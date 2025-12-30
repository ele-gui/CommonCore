/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:43:00 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:51 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_str1(char const *s)
{
	if (!s)
		return ;
}

static void	ft_check_str2(char const *s, char const *set)
{
	if (!s || !set)
		return ;
}

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
// deve toglier solo all'inizio e alla fine, non all'interno
// => non puo' rimuovere "i" da ciao
// => fa questo: "ciaoc" - "c" + "iao"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		inizio;
	int		fine;
	int		k;

	ft_check_str2(s1, set);
	inizio = 0;
	fine = ft_strlen(s1);
	while (s1[inizio] && ft_inset(s1[inizio], set))
		inizio++;
	while (fine > inizio && ft_inset(s1[fine - 1], set))
		fine--;
	trimmed = (char *)malloc(fine - inizio + 1);
	ft_check_str1(trimmed);
	k = 0;
	while (inizio < fine)
	{
		trimmed[k] = s1[inizio];
		inizio++;
		k++;
	}
	trimmed[k] = '\0';
	return (trimmed);
}

// int	main(void)
// {
// 	char	str[] = "cciaoc";
// 	char	set[] = "i";
// 	char	*trim;

// 	trim = ft_strtrim(str, set);
// 	printf("%s - %s --> %s\n", str, set, trim);
// 	return (0);
// }