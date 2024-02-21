/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:01:29 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 13:39:06 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_valid_base(char *base)
{
	long	x;

	x = -1;
	while (base[++x])
		if (base[x] == '-' || base[x] == '+' || base[x] == base[x + 1])
			return (0);
	if (x <= 1)
		return (0);
	else
		return (x);
}

int	ft_printunbr_base_fd(unsigned long nbr, char *base, int fd)
{
	unsigned long	size;
	static int		x;

	x = 0;
	size = ft_valid_base(base);
	if (size)
	{
		if (nbr >= size)
			if (ft_printunbr_base_fd(nbr / size, base, fd) == -1)
				return (-1);
		if (ft_printchar_fd(base[nbr % size], fd) == -1)
			return (-1);
		x++;
	}
	return (x);
}
