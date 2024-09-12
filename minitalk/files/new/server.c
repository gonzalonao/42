/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:24:27 by glopez-c          #+#    #+#             */
/*   Updated: 2024/07/16 16:29:32 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_printer(int signal)
{
	static int	i;
	static int	current;

	if (signal == SIGUSR1)
		current |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", current);
		current = 0;
		i = 0;
	}
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID -> %i\nWaiting for a message...\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_printer);
		signal(SIGUSR2, ft_printer);
	}
}