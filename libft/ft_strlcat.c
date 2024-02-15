/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:50:43 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 18:03:23 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < 1)
		return (src_len);
	j = dest_len;
	while (src[i] && j < dstsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	if (dstsize < dest_len)
		return (src_len + dstsize);
	else
		return (dest_len + src_len);
}
