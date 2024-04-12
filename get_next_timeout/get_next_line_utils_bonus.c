/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:13:29 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:19:01 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strjoin2(char s2[5][BUFFER_SIZE + 1], int n, int size, char *str)
{
	int		j;
	int		k;
	int		i;

	i = ft_strlen(str);
	j = -1;
	while (++j < n - 1)
	{
		k = -1;
		while (++k < BUFFER_SIZE)
			str[i++] = s2[j][k];
	}
	if (size > 0)
	{
		k = -1;
		while (++k < size)
			str[i++] = s2[j][k];
	}
	str[i] = 0;
}

char	*ft_strjoin(char *s1, char s2[5][BUFFER_SIZE + 1], int n, int size)
{
	int		i;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (n - 1)
				* BUFFER_SIZE + size + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	ft_strjoin2(s2, n, size, str);
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > slen - start)
		len = slen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
