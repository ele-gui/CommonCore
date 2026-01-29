/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:43:23 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/29 17:20:01 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Adds the node ’new’ at the beginning of the list*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// void	ft_print_list(t_list *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		printf("Nodo %d: %s\n", i, (char *)lst->content);
// 		lst = lst->next;
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head, *n1, *n2, *n3;

// 	//creazione dei nodi
// 	head = NULL;
// 	n1 = ft_lstnew("Primo");
// 	n2 = ft_lstnew("Secondo");
// 	n3 = ft_lstnew("Terzo");

// 	//aggiungo in testa
// 	ft_lstadd_front(&head, n1);
// 	ft_lstadd_front(&head, n2);
// 	ft_lstadd_front(&head, n3);

// 	printf("Contenuto della lista:\n");
//     ft_print_list(head); //stampa: terzo secondo primo

// 	// Libero la lista
//     t_list *tmp;
//     while (head)
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }
//     return (0);
// }