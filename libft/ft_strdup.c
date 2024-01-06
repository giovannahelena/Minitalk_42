/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:58:39 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 20:03:16 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str_dup;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	str_dup = (char *) malloc((len + 1) * sizeof(char));
	if (!str_dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_dup[i] = s1[i];
		i++;
	}
	str_dup[len] = '\0';
	return (str_dup);
}
