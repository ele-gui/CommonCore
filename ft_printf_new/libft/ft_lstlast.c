/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:22:52 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:20 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

// int main(void)
// {
//     t_list	*head;
//     t_list	*n1;
//     t_list	*n2;
//     t_list	*n3;
//     t_list	*tmp;
// 	t_list	*next;
// 	t_list	*last;

// 	head = NULL;
//     n1 = ft_lstnew("Primo");
//     n2 = ft_lstnew("Secondo");
//     n3 = ft_lstnew("Terzo");
//     head = n1;
//     n1->next = n2;
//     n2->next = n3;
//     last = ft_lstlast(head);
// 	if (last)
// 		printf("Ultimo nodo: %s\n", (char *)last->content);
//     tmp = head;
//     while (tmp)
//     {
//         next = tmp->next;
//         free(tmp);
//         tmp = next;
//     }
//     return (0);
// }