/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:38:58 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:19:00 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr_hex(unsigned long int nbr);

int	ft_putptr(unsigned long int p)
{
	int	return_value;

	return_value = 0;
	if (!p)
		return_value += ft_putstr("(nil)");
	else
	{
		return_value += ft_putstr("0x");
		return_value += ft_put_ptr_hex(p);
	}
	return (return_value);
}

static int	ft_put_ptr_hex(unsigned long int nbr)
{
	int			count;
	const char	*case_low;

	count = 0;
	case_low = "0123456789abcdef";
	if (nbr < 16)
		count += ft_putchar(case_low[nbr]);
	else
	{
		count += ft_put_ptr_hex(nbr / 16);
		count += ft_put_ptr_hex(nbr % 16);
	}
	return (count);
}
