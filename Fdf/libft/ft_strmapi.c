/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:07:45 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/16 19:11:35 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*str;
	size_t	i;

	x = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < x)
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
