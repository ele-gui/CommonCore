/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:43:32 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/29 17:27:30 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Counts the number of nodes in the list.

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
// int main(void)
// {
//     t_list *head = NULL;
//     t_list *n1;
//     t_list *n2;
//     t_list *n3;
//     t_list *tmp;
// 	t_list *next;

//     n1 = ft_lstnew("Primo");
//     n2 = ft_lstnew("Secondo");
//     n3 = ft_lstnew("Terzo");
//     head = n1;
//     n1->next = n2;
//     n2->next = n3;
//     printf("Numero di nodi: %d\n", ft_lstsize(head));
//     tmp = head;
//     while (tmp)
//     {
//         next = tmp->next;
//         free(tmp);
//         tmp = next;
//     }
//     return 0;
// }
