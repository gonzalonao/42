/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:40:28 by glopez-c          #+#    #+#             */
/*   Updated: 2024/07/16 18:24:38 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

// void	ft_send_bits(int pid, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		if ((c & (0x01 << i)) != 0)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(100);
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	int	i;

// 	i = 0;
// 	if (argc == 3)
// 	{
// 		pid = ft_atoi(argv[1]);
// 		while (argv[2][i] != '\0')
// 		{
// 			ft_send_bits(pid, argv[2][i]);
// 			i++;
// 		}
// 		ft_send_bits(pid, '\n');
// 	}
// 	else
// 	{
// 		ft_printf("\033[91mError: wrong format.\033[0m\n");
// 		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
// 		return (1);
// 	}
// 	return (0);
// }

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t ack_received = 0;

void ack_handler(int sig)
{
	sig++;
	ack_received = 1;
}

void ft_send_bits(int pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        ack_received = 0; // Reset acknowledgment flag
        if ((c & (0x01 << i)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
		// Give time for the server to process the signal
        //pause(); // Pause the process until a signal is received
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;
    struct sigaction sa;

    // Setup the acknowledgment signal handler
    ft_memset(&sa, 0, sizeof(sa));
    sa.sa_handler = ack_handler;
    sigaction(SIGUSR1, &sa, NULL);

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            ft_send_bits(pid, argv[2][i]);
            i++;
        }
        ft_send_bits(pid, '\n'); // Send newline character at the end
    }
    else
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
        ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
        return (1);
    }
    return (0);
}
