/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:19:55 by ajordan-          #+#    #+#             */
/*   Updated: 2024/06/27 19:32:59 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_string(int pid, char *s)
{
	static int	bit;
	static char	*str;

	if (!str && s)
		str = s;
	if ((*str & (0x01 << bit)) != 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (*str == '\0')
			return ;
		str++;
	}
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	int	pid;

	void(context);
	pid = info->si_pid;
	if (signal == SIGUSR1)
		ft_send_string(pid, NULL);
	else if (signal == SIGUSR2)
	{
		ft_printf("\033[31mFull message received by server\033[0m\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	ft_send_string(pid, argv[2]);
	return (0);
}
