/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:02:19 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/01 01:33:44 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	lstsize = 0;
	if (!lst)
		return (lstsize);
	while (lst)
	{
		lst = lst -> next;
		lstsize++;
	}
	return (lstsize);
}
