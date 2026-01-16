/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:01:18 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:36 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
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

// int main ()
// {
// 	char buffer1[] = "Ciao";
// 	char buffer2[] = "ciao";
// 	int n_mio;
// 	int	n_vero;

// 	n_mio = ft_memcmp( buffer1, buffer2, ft_strlen(buffer1) - 5);
// 	n_vero = memcmp( buffer1, buffer2, ft_strlen(buffer1) - 5);
// 	//MIO
// 	printf("MIA\n");
// 	printf("%d\n", n_mio);
// 	if (n_mio > 0) 
// 		printf ("'%s' is greater than '%s'.\n", buffer1, buffer2);
// 	else if (n_mio < 0)
// 		printf ("'%s' is less than '%s'.\n", buffer1, buffer2);
// 	else
// 		printf ("'%s' is the same as '%s'.\n", buffer1, buffer2);

// 	//VERO
// 	printf("VERA\n");
// 	printf("%d\n", n_vero);
// 	if (n_vero > 0) 
// 		printf ("'%s' is greater than '%s'.\n", buffer1, buffer2);
// 	else if (n_vero < 0) 
// 		printf ("'%s' is less than '%s'.\n", buffer1, buffer2);
// 	else 
// 		printf ("'%s' is the same as '%s'.\n", buffer1, buffer2);
// 	return (0);
// }