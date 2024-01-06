/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:01:06 by ghelena-          #+#    #+#             */
/*   Updated: 2023/12/04 15:11:22 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	byte_to_char(char *byte, int c_pid)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	while (i < 8)
	{
		if (byte[i] == '1')
			c |= (1 << (7 - i));
		i++;
	}
	if (c != '\0')
		write (1, &c, 1);
	else
	{
		write (1, "\n", 1);
		kill(c_pid, SIGUSR1);
	}
}

void	bit_to_byte(int sig, siginfo_t	*info, void	*context)
{
	static int	i = 0;
	static int	bit = -1;
	static char	byte[8];

	(void)context;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	if (i < 8)
		byte[i] = '0' + bit;
	i++;
	if (i == 8)
	{
		byte_to_char(byte, info->si_pid);
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_printf("PID: %i\n", getpid());
	s_sig.sa_handler = NULL;
	s_sig.sa_sigaction = bit_to_byte;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (9)
		pause ();
}
