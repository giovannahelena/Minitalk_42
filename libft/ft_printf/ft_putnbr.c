/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:38:05 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:19:17 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negative(int n);

int	ft_putnbr(int n)
{
	char	num;
	int		return_count;

	return_count = 0;
	if (n == 0)
		return_count += write(1, "0", 1);
	if (n < 0)
		return_count += negative(n);
	else if (n > 0 && n <= 9)
	{
		num = n + 48;
		return_count += write(1, &num, 1);
	}
	else if (n > 9)
	{
		return_count += ft_putnbr((n / 10));
		num = (n % 10) + 48;
		return_count += write(1, &num, 1);
	}
	return (return_count);
}

static int	negative(int n)
{
	char	num;
	int		return_count;

	return_count = 0;
	return_count += write(1, "-", 1);
	if (n == -2147483648)
		return_count += write(1, "2147483648", 10);
	else if (n < 0 && n >= -9)
		return_count += ft_putnbr((n * -1));
	else
	{
		return_count += ft_putnbr(((n * -1) / 10));
		num = -(n % 10) + 48;
		return_count += write(1, &num, 1);
	}
	return (return_count);
}
