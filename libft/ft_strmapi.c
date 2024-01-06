/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:52:03 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:23:31 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	newstr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	if (!newstr)
		return (NULL);
	return (newstr);
}
