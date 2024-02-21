/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:55:26 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/29 11:52:42 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_fd(long nb, int fd, int j)
{
	static int	x;

	x = j;
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		nb *= -1;
		x++;
	}
	if (nb > 9)
	{
		if (ft_printnbr_fd(nb / 10, fd, x) == -1)
			return (-1);
		if (ft_printnbr_fd(nb % 10, fd, x) == -1)
			return (-1);
	}
	else
	{
		if (ft_printchar_fd(nb + '0', fd) == -1)
			return (-1);
		x++;
	}
	return (x);
}
