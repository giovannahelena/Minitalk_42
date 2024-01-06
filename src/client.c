/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:01:02 by ghelena-          #+#    #+#             */
/*   Updated: 2023/12/04 16:04:22 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_next_bit = 1;

void	end_message(int pid)
{
	int		i;
	char	c;

	i = 8;
	c = '\0';
	while (i--)
	{
		if ((c >> i) & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
	}
}

void	message_to_bit(int pid, char *message)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (message[j] != '\0')
	{
		i = 8;
		c = message[j];
		while (i--)
		{
			g_next_bit = 0;
			if ((c >> i) & 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			while (g_next_bit == 0)
				;
			usleep(100);
		}
		j++;
		if (message[j] == '\0')
			end_message(pid);
	}
}

void	hand_shake(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_printf("message successfully passed to %i\n", info->si_pid);
		exit(1);
	}
	else if (sig == SIGUSR2)
		g_next_bit = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;
	int					pid;

	if (argc != 3 || ((ft_str_isdigit(argv[1]) == 0)))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	s_sig.sa_handler = NULL;
	s_sig.sa_sigaction = hand_shake;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	message_to_bit(pid, argv[2]);
	while (9)
		pause();
}
