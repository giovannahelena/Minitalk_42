/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:51:29 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 19:52:15 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = dest;
	source = src;
	i = 0;
	while (n > 0)
	{
		destination[i] = source[i];
		i++;
		n--;
	}
	return (destination);
}
