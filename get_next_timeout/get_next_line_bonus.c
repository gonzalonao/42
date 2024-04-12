/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:21:19 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:19:01 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_gnl	init_gnl(char **gnl, int fd)
{
	t_gnl	gnl_info;

	gnl_info.i = 1;
	gnl_info.j = 0;
	gnl_info.first_read = 1;
	gnl_info.found = ft_strchr(gnl[fd], '\n');
	return (gnl_info);
}

int	ft_readline(int fd, char **gnl)
{
	char	buf[5][BUFFER_SIZE + 1];
	t_gnl	gnl_info;

	gnl_info = init_gnl(gnl, fd);
	while (!gnl_info.found)
	{
		gnl_info.i = read(fd, buf[gnl_info.j], BUFFER_SIZE);
		if (gnl_info.i <= 0)
		{
			if (gnl_info.j > 0)
				gnl[fd] = ft_strjoin(gnl[fd], buf, gnl_info.j + 1, gnl_info.i);
			break ;
		}
		buf[gnl_info.j][gnl_info.i] = '\0';
		gnl_info.found = ft_strchr(buf[gnl_info.j], '\n');
		if (++gnl_info.j == 5 || gnl_info.first_read || gnl_info.found)
		{
			gnl[fd] = ft_strjoin(gnl[fd], buf, gnl_info.j, gnl_info.i);
			gnl_info.j = 0;
			gnl_info.first_read = 0;
		}
		if (!gnl[fd] || gnl_info.found)
			break ;
	}
	return (gnl_info.i);
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
