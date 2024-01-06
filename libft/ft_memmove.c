/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:47:15 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 19:56:37 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = dest;
	source = (char *)src;
	if (destination > source)
	{
		while (n--)
			destination[n] = source[n];
		return (destination);
	}
	i = 0;
	while (n > 0)
	{
		destination[i] = source[i];
		i++;
		n--;
	}
	return (destination);
}
