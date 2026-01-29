/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:27:22 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/29 17:21:26 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = node;
	}
	*lst = NULL;
}


// void	del(void	*content)
// {
// 	free(content);
// }

// int main(void)
// {
//     // Creo 2 nodi
//     t_list *n1 = ft_lstnew(malloc(5));
//     t_list *n2 = ft_lstnew(malloc(5));
//     n1->next = n2;

//     t_list *head = n1;

//     // Li pulisco tutti
//     ft_lstclear(&head, del);

//     if (head == NULL)
//         printf("Lista pulita correttamente!\n");
//     else
//         printf("Errore: la lista non è NULL.\n");

//     return 0;
// }