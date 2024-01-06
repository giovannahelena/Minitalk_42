/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:53:55 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 20:02:35 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	memsize;
	void	*alloc;

	if ((nmemb * size != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	memsize = nmemb * size;
	alloc = (void *)malloc(memsize);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, memsize);
	return (alloc);
}
