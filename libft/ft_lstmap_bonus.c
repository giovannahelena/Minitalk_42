/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:43:36 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 10:59:00 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			ft_lstdelone (new_node, del);
		new_node->content = f(lst -> content);
		new_node->next = 0;
		lst = lst -> next;
		ft_lstadd_back(&new_list, new_node);
	}
	return (new_list);
}
