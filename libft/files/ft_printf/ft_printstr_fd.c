/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:54:16 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/07 20:46:41 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = -1;
	while (s[++i])
		if (write(fd, &s[i], 1) == -1)
			return (-1);
	return (i);
}
