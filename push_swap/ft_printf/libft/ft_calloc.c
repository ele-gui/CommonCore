/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:13:20 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:22:37 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb != 0 && size >= __SIZE_MAX__ / nmemb)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

// if (!mem) //return NULL se non riesce ad allocare la memoria
// 		return (NULL);
// 	ft_bzero(mem, nmemb * size); // deve azzerare la memoria
// 	return (mem);

// int main() 
// {  
// 	int n, i;
// 	int *ptr_mio, *ptr_vero;

// 	n = 5;
// 	ptr_mio = (int *)ft_calloc(n, sizeof(int));
// 	ptr_vero = (int *)calloc(n, sizeof(int));

// 	printf("MIO\n");
// 	if (ptr_mio == NULL)
// 		printf("errore nell'allocazione di memoria\n");
// 	printf("array elements dopo calloc: ");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%d ", ptr_mio[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(ptr_mio);

// 	printf("VERO\n");
// 	if (ptr_vero == NULL)
// 		printf("errore nell'allocazione di memoria\n");
// 	printf("array elements dopo calloc: ");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%d ", ptr_vero[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(ptr_vero);
// 	return (0);
// }
