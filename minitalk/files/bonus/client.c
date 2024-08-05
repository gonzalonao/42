/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:19:55 by ajordan-          #+#    #+#             */
/*   Updated: 2024/08/05 07:45:08 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send_string(char *s)
{
	static int	bit;
	static char	*str;
	static int	i;
	int			signal;

	if (!str && s)
		str = s;
	if (((unsigned char)str[i] & (0x01 << bit)))
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		i++;
	}
	return (signal);
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	int	pid;
	int	sig;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		sig = ft_send_string(NULL);
		kill(pid, sig);
	}
	if (signal == SIGUSR2)
	{
		ft_printf("\033[31mFull message received by server\033[0m\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;
	int					signal;

	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	pid = ft_atoi(argv[1]);
	signal = ft_send_string(argv[2]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	kill(pid, signal);
	while(1)
	{
		pause();
	}
	return (0);
}
