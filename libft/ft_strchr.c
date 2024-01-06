/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:48:42 by ghelena-          #+#    #+#             */
/*   Updated: 2023/05/30 20:10:07 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pi;

	i = 0;
	if (c > 127)
		c = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			pi = (char *)&s[i];
			return (pi);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
