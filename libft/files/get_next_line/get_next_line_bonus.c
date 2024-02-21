/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:21:19 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/07 20:46:00 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_strchr(const char *s, int c)
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

	str = ft_get_strchr(*gnl, '\n');
	if (!str)
		len = ft_get_strlen(*gnl);
	else
		len = (str - (*gnl)) + 1;
	res = ft_get_substr(*gnl, 0, len);
	if (!res)
	{
		ft_free(gnl);
		return (NULL);
	}
	first = ft_get_substr(*gnl, len, ft_get_strlen(*gnl) - len);
	ft_free(gnl);
	if (!first)
		ft_free(&res);
	*gnl = first;
	return (res);
}

int	ft_readline(int fd, char *gnl[256])
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (gnl[fd])
			ft_free(&gnl[fd]);
		return (0);
	}
	i = 1;
	while (!ft_get_strchr(gnl[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		gnl[fd] = ft_get_strjoin(gnl[fd], buf);
		if (!gnl[fd] || ft_get_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*gnl[OPEN_MAX];
	char		*res;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	i = ft_readline(fd, gnl);
	if (!gnl[fd])
		return (NULL);
	else if ((i == 0 && !gnl[fd][0]) || i < 0)
	{
		ft_free(&gnl[fd]);
		return (NULL);
	}
	else
		res = trim_line(&gnl[fd]);
	return (res);
}
