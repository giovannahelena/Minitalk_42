/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:44 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:06:12 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	if (!dst && !size)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	j = dstlen;
	if (size > 0 && (dstlen <= size - 1))
	{
		while (src[i] != '\0' && (i < (size - dstlen - 1)))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		return (srclen + dstlen);
	}
	return (srclen + size);
}
