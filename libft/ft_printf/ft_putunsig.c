/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:38:05 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:15:36 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsig(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else if (n > 0 && n <= 9)
	{
		num = n + 48;
		count += write(1, &num, 1);
	}
	else if (n > 9)
	{
		count += ft_putunsig((n / 10));
		num = (n % 10) + 48;
		count += write(1, &num, 1);
	}
	return (count);
}
