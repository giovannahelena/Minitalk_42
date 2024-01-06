/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:34:41 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:07:57 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!big && !len)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	while (big[j] != 0 && ((i + j) < len))
	{
		i = 0;
		while (little[i] == big[j + i] && ((i + j) < len))
		{
			i++;
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		if (little[i] != big[j + i])
			j++;
	}
	return (NULL);
}
