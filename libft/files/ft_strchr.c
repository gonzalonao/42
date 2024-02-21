/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:07:52 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/16 17:16:42 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*str;

	ch = (char) c;
	str = (char *)s;
	i = -1;
	while (s[++i])
		if (s[i] == ch)
			return (str + i);
	if (ch == 0)
		return (str + i);
	return (NULL);
}
