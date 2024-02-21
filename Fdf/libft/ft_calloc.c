/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:40 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/16 15:28:43 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)malloc(size * count);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < count * size)
		s[i] = 0;
	return (s);
}
