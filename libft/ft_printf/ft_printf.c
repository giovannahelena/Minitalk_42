/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:15:45 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:27:31 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *p1, ...)
{
	va_list	var;
	int		return_value;
	int		i;

	return_value = 0;
	i = 0;
	va_start(var, p1);
	if (!p1)
		return (-1);
	while (p1[i] != '\0')
	{
		if (p1[i] == '%')
			return_value += format_specifier(p1[++i], var);
		else
			return_value += write(1, &p1[i], 1);
		i++;
	}
	va_end(var);
	return (return_value);
}

int	format_specifier(char a, va_list var)
{
	int	return_value;

	return_value = 0;
	if (a == 'c')
		return_value += ft_putchar(va_arg(var, int));
	else if (a == 's')
		return_value += ft_putstr(va_arg(var, char *));
	else if (a == 'p')
		return_value += ft_putptr(va_arg(var, unsigned long int));
	else if (a == 'd' || a == 'i')
		return_value += ft_putnbr(va_arg(var, int));
	else if (a == 'u')
		return_value += ft_putunsig(va_arg(var, unsigned int));
	else if (a == 'x')
		return_value += ft_puthex(va_arg(var, unsigned int), 0);
	else if (a == 'X')
		return_value += ft_puthex(va_arg(var, unsigned int), 1);
	else if (a == '%')
		return_value += ft_putchar('%');
	return (return_value);
}
