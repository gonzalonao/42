/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:45:56 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 18:14:10 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[j + i] && i + j < len)
			if (!needle[++j])
				return ((char *)haystack + i);
	}
	return (0);
}
