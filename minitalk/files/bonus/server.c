/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:14:41 by glopez-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:14:41 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	i;
	int			pid;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	else
		i |= (0x00 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (i == '\0')
		{
			ft_printf("\n");
			kill(pid, SIGUSR2);
			return ;
		}
		else
			ft_printf("%c", i);
		i = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m \033[95m");
	ft_printf("%i", pid);
	ft_printf("\033[0m\n\033[90mWaiting for a message...\033[0m\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
