/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:40:15 by glopez-c          #+#    #+#             */
/*   Updated: 2024/08/08 18:03:35 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
// #include <sys/types.h>

// void	ft_handler(int signal)
// {
// 	static int	i;
// 	static int	current;

// 	if (signal == SIGUSR1)
// 		current |= (0x01 << i);
// 	i++;
// 	if (i == 8)
// 	{
// 		ft_printf("%c", current);
// 		current = 0;
// 		i = 0;
// 	}
// }

// int	main(void)
// {
// 	pid_t	pid;

// 	pid = getpid();
// 	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m \033[95m");
// 	ft_printf("%i", pid);
// 	ft_printf("\033[0m\n\033[90mWaiting for a message...\033[0m\n");
// 	// signal(SIGUSR1, ft_handler);
// 	// signal(SIGUSR2, ft_handler);
// 	while (1)
// 	{
// 		signal(SIGUSR1, ft_handler);
// 		signal(SIGUSR2, ft_handler);
// 		pause();
// 	}
// 	return (0);
// }

#include "minitalk.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void ft_handler(int signal, siginfo_t *info, void *context)
{
    static int i = 0;
    static int current = 0;
    (void)context; // Context is not used, avoid unused parameter warning

    if (signal == SIGUSR1)
        current |= (0x01 << i);
    i++;
    if (i == 8)
    {
        ft_printf("%c", current);
        current = 0;
        i = 0;
        // Send acknowledgment back to sender
        kill(info->si_pid, SIGUSR1);
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;
	int i = 0;

    ft_memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_handler;

    pid = getpid();
    ft_printf("\033[94mPID\033[0m \033[96m->\033[0m \033[95m%i\033[0m\n\033[90mWaiting for a message...\033[0m\n", pid);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        i++; // Wait for signals
    }
    return (0);
}
