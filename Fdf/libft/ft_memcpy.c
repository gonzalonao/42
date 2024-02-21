/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:34:19 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/16 17:01:59 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	while (n--)
		s2[i++] = *s1++;
	return (dst);
}
