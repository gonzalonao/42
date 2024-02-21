/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:03 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 15:04:31 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;
	unsigned char	ch;
	size_t			i;

	i = 0;
	st = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (st[i] == ch)
			return (st + i);
		i++;
	}
	return (NULL);
}
