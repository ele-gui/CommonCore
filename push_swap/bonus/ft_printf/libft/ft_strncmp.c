/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:02:03 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:40 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "5";
// 	char	s2[] = "a65";
// 	int		num;

// 	num = 2;
// 	printf("MIA:  %d\n", ft_strncmp(s1, s2, num));
// 	printf("VERA: %d\n", strncmp(s1, s2, num));

// 	return (0);
// }