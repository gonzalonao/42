/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:21:19 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:16:10 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return ((char *)s + i);
	if ((char) c == 0)
		return ((char *)s + i);
	return (NULL);
}

static void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*trim_line(char **gnl)
{
	int		len;
	char	*res;
	char	*first;
	char	*str;

	str = ft_strchr(*gnl, '\n');
	if (!str)
		len = ft_strlen(*gnl);
	else
		len = (str - (*gnl)) + 1;
	res = ft_substr(*gnl, 0, len);
	if (!res)
	{
		ft_free(gnl);
		return (NULL);
	}
	first = ft_substr(*gnl, len, ft_strlen(*gnl) - len);
	ft_free(gnl);
	if (!first)
		ft_free(&res);
	*gnl = first;
	return (res);
}

static int	ft_readline(int fd, char **gnl)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (*gnl)
			ft_free(gnl);
		return (0);
	}
	i = 1;
	while (!ft_strchr(*gnl, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		*gnl = ft_strjoin(*gnl, buf);
		if (!*gnl)
			break ;
	}
	free(buf);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*res;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	i = ft_readline(fd, &gnl);
	if (!gnl)
		return (NULL);
	else if ((i == 0 && !gnl[0]) || i < 0)
	{
		ft_free(&gnl);
		return (NULL);
	}
	else
		res = trim_line(&gnl);
	return (res);
}
