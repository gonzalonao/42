/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:18:05 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/16 17:05:41 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dst;
	i = 0;
	if (s2 == s1)
		return (s2);
	if (s2 > s1)
		while (len--)
			s2[len] = s1[len];
	else
		while (len--)
			s2[i++] = *s1++;
	return (s2);
}
