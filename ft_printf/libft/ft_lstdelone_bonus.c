/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elguiduc <elguiduc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:05:33 by elguiduc          #+#    #+#             */
/*   Updated: 2025/12/08 16:23:11 by elguiduc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Takes a node as parameter and frees its content using the function ’del’. 
//Free the node itself but does NOT free the next node.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// void	print_list(t_list *lst)
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

// int main(void)
// {
// 	t_list *n1 = malloc(sizeof(t_list));
// 	t_list *n2 = malloc(sizeof(t_list));
// 	t_list *n3 = malloc(sizeof(t_list));
// 	//uso strdup per allocare memoria con malloc
// 	//permettere di fare free(content) in sicurezza dentro del()
// 	n1->content = ft_strdup("Primo");
// 	n2->content = ft_strdup("Secondo");
// 	n3->content = ft_strdup("Terzo");

// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;

// 	printf("Lista prima della cancellazione:\n");
// 	print_list(n1);

// 	// cancello il nodo centrale (n2)
// 	ft_lstdelone(n2, del);

// 	//dopo aver cancellato n2, dobbiamo "staccarlo" dalla lista
// 	n1->next = n3;

// 	printf("\nLista dopo la cancellazione del nodo 1:\n");
// 	print_list(n1);

// 	// Cleanup finale per evitare memory leak
// 	ft_lstdelone(n1, del);
// 	ft_lstdelone(n3, del);

// 	return (0);
// }
