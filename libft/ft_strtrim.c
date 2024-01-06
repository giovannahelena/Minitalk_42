/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:18:44 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:30:16 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string_trim(char const	*s1, char const	*set);
static int	len_count_front(char	*s1, char const	*set);
static int	len_count_back(char	*s1, char const	*set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	s2 = string_trim(s1, set);
	if (!s2)
		return (NULL);
	return (s2);
}

static char	*string_trim(char const	*s1, char const	*set)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	s2 = ft_calloc(len_count_back((char *)s1, set) + 1, sizeof(char));
	if (!s2)
		return (NULL);
	while (set[j] != '\0' && s1[i] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	j = 0;
	while (s1[i] != '\0' && j < len_count_back((char *)s1, set))
		s2[j++] = s1[i++];
	return (s2);
}

static int	len_count_front(char	*s1, char const	*set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else if (set[j] != '\0')
			j++;
	}
	while (s1[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static int	len_count_back(char	*s1, char const	*set)
{
	int	i;
	int	j;
	int	count;

	count = len_count_front(s1, set);
	i = ft_strlen (s1) - 1;
	j = 0;
	while (set[j] != '\0' && i != 0)
	{
		if (s1[i] == set[j])
		{
			if (count != 0)
				count--;
			i--;
			j = 0;
		}
		else if (set[j] != '\0')
			j++;
	}
	return (count);
}
