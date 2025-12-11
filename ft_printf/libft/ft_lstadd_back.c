/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:42 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:02 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Adds the node ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// void ft_print_list(t_list *lst)
// {
//     int i = 0;
//     while (lst)
//     {
//         printf("Nodo %d: %s\n", i, (char *)lst->content);
//         lst = lst->next;
//         i++;
//     }
// }

// int	main(void)
// {
// 	t_list	*head, *n1, *n2, *n3;

// 	//creazione dei nodi
// 	head = NULL;
// 	n1 = ft_lstnew("Primo");
// 	n2 = ft_lstnew("Secondo");
// 	n3 = ft_lstnew("Terzo");

// 	//aggiungo in fondo
// 	ft_lstadd_back(&head, n1);
// 	ft_lstadd_back(&head, n2);
// 	ft_lstadd_back(&head, n3);

// 	printf("Contenuto della lista:\n");
//     ft_print_list(head); //stampa primo secondo terzo

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