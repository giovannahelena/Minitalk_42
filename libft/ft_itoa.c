/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:23:09 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 20:21:14 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(int n);
static char		*min(char *minimal);

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	s;
	char	*output;
	size_t	count;

	i = 0;
	s = 0;
	count = digit_count(n);
	output = (char *)ft_calloc((count + 1), sizeof(char));
	if (!output)
		return (NULL);
	if (n == -2147483648)
		return (min(output));
	while (i < count - s)
	{
		if (n < 0)
		{
			output[i] = '-';
			n = -n;
			s++;
		}	
		output[count - ++i] = (n % 10) + '0';
		n = n / 10;
	}
	return (output);
}

static size_t	digit_count(int n)
{
	size_t	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*min(char *minimal)
{
	minimal[0] = '-';
	minimal[1] = '2';
	minimal[2] = '1';
	minimal[3] = '4';
	minimal[4] = '7';
	minimal[5] = '4';
	minimal[6] = '8';
	minimal[7] = '3';
	minimal[8] = '6';
	minimal[9] = '4';
	minimal[10] = '8';
	minimal[11] = '\0';
	return (minimal);
}
