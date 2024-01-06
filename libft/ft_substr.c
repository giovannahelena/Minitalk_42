/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:41:12 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:12:14 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makesub(char const *s, char *sub, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
		return (sub);
	}
	else if (len > (ft_strlen(s) - start))
		sub = ft_calloc(((ft_strlen(s) - start) + 1), sizeof(char));
	else
		sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	return (makesub(s, sub, start, len));
}

static char	*makesub(char const *s, char *sub, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && i != start)
		i++;
	if (i == start)
	{
		while (s[i] != '\0' && len-- > 0)
		sub[j++] = s[i++];
		return (sub);
	}
	return (0);
}
