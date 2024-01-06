/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:41:47 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/05 16:09:22 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c);
static int	lentochar(const char *s, char c);
static char	*strprepare(char *s, char c);
static char	**process(char *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*strinit;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		result = ft_calloc(1, sizeof(char *));
		if (!result)
			return (NULL);
		return (result);
	}
	else
	{
		str = strprepare((char *)s, c);
		strinit = str;
		result = process(str, c);
	}
	free (strinit);
	return (result);
}	

static int	lentochar(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*s == c)
	{
		s++;
		if (!*s)
			return (count);
	}
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*strprepare(char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (*s == c)
		s++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] == c || s[i + 1] == '\0'))
			i++;
		else
			str[j++] = s[i++];
	}
	return (str);
}

static char	**process(char *str, char c)
{
	char	**result;
	int		k;
	int		word_count;

	word_count = wordcount(str, c);
	k = 0;
	result = ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (*str)
	{
		result[k] = ft_calloc(lentochar(str, c) + 1, sizeof(char));
		if (!result[k])
		{
			while (k-- > 0)
				free (result[k]);
			free (result);
			return (NULL);
		}	
		ft_strlcpy(result[k++], str, lentochar(str, c) + 1);
		str = str + lentochar(str, c);
		if (*str == c && *str != '\0')
			str++;
	}
	return (result);
}
