/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:34:59 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 10:24:21 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pi;
	int		slen;

	slen = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[slen]);
	while (s + slen != s)
	{
		if (s[slen] == (unsigned char)c)
		{
			pi = (char *)&s[slen];
			return (pi);
		}
		slen--;
	}
	if (s[slen] == s[0] && s[slen] == (unsigned char)c)
	{
		pi = (char *)&s[slen];
		return (pi);
	}
	return (0);
}
