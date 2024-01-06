/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:16:09 by ghelena-          #+#    #+#             */
/*   Updated: 2023/07/10 17:31:17 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *p1, ...);
int	format_specifier(char str, va_list var);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putunsig(unsigned int n);
int	ft_puthex(unsigned int nbr, unsigned int flag);
int	ft_putptr(unsigned long int p);

#endif