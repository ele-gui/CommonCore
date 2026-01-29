/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:08:22 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:27 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//La lista è una catena di nodi. Ogni nodo ha un puntatore al nodo successivo
/*Allocates memory (using malloc(3)) and returns
a new node. The ’content’ member variable is
initialized with the given parameter ’content’.
The variable ’next’ is initialized to NULL.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int main(void)
// {
//     char    *str = "";
//     t_list  *node;

//     node = ft_lstnew(str);
//     if (!node)
//     {
//         printf("Errore: ft_lstnew ha restituito NULL\n");
//         return (1);
//     }
//     printf("Contenuto del nodo: %s\n", (char *)node->content);
//     if (node->next == NULL)
//         printf("next è NULL: OK\n");
//     else
//         printf("next NON è NULL: ERRORE\n");
//     free(node);
//     return 0;
// }