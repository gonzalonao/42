/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:26:08 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 18:31:53 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	if (start > slen)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		if (len > slen - start)
			len = slen - start;
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (++i < len)
			str[i] = s[start + i];
		str[i] = 0;
	}
	return (str);
}
