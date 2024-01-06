/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:23:40 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/02 19:09:29 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	negative(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		negative(n, fd);
	}
	else if (n > 0 && n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		num = (n % 10) + 48;
		write(fd, &num, 1);
	}
}

static void	negative(int n, int fd)
{
	char	num;

	write(fd, "-", 1);
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
	}
	else if (n < 0 && n >= -9)
	{
		ft_putnbr_fd((n * -1), fd);
	}
	else
	{
		ft_putnbr_fd(((n * -1) / 10), fd);
		num = -(n % 10) + 48;
		write(fd, &num, 1);
	}
}
