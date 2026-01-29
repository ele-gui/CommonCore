/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:11:12 by elguiduc          #+#    #+#             */
/*   Updated: 2026/01/29 17:26:34 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	del(void *s)
// {
//     free(s);
// }

// void	*duplicate_str(void *s)
// {
//     return ft_strdup((char *)s);
// }

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

// int main(void)
// {
//     t_list *n1 = ft_lstnew(ft_strdup("Uno"));
//     t_list *n2 = ft_lstnew(ft_strdup("Due"));
//     t_list *n3 = ft_lstnew(ft_strdup("Tre"));
// 	t_list *new_list;

//     n1->next = n2;
//     n2->next = n3;

//     printf("Lista originale:\n");
//     ft_print_list(n1);

//     new_list = ft_lstmap(n1, duplicate_str, del);

//     printf("\nNuova lista duplicata:\n");
// 	ft_print_list(new_list);

//     ft_lstclear(&n1, del);
//     ft_lstclear(&new_list, del);

//     return 0;
// }
