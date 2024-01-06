/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:01:10 by ghelena-          #+#    #+#             */
/*   Updated: 2023/11/24 16:25:46 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "./../libft/ft_printf/ft_printf.h"
# include "./../libft/libft.h"

void	message_to_bit(int pid, char *message);
void	byte_to_char(char *byte, int pid);
void	end_message(int pid);
void	send_pid(int s_pid);
void	steal_c_pid(char c);
void	hand_shake(int sig, siginfo_t *info, void *context);

#endif