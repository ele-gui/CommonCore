/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:50:57 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:15 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }

// int main(void)
// {
//     t_list *n1 = ft_lstnew("Uno");
//     t_list *n2 = ft_lstnew("Due");
//     t_list *n3 = ft_lstnew("Tre");
//     n1->next = n2;
//     n2->next = n3;
//     ft_lstiter(n1, print_content);
//     t_list *tmp;
//     while (n1)
//     {
//         tmp = n1->next;
//         free(n1);
//         n1 = tmp;
//     }
//     return (0);
// }
