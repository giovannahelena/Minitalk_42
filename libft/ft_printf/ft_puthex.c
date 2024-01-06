/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:04:52 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:26:25 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, unsigned int flag)
{
	int			count;
	const char	*case_low;
	const char	*case_up;
	char		*case_use;

	count = 0;
	case_low = "0123456789abcdef";
	case_up = "0123456789ABCDEF";
	if (flag == 1)
		case_use = (char *)case_up;
	else if (flag == 0)
		case_use = (char *)case_low;
	if (nbr < 16)
		count += ft_putchar(case_use[nbr]);
	else
	{
		count += ft_puthex(nbr / 16, flag);
		count += ft_puthex(nbr % 16, flag);
	}
	return (count);
}
