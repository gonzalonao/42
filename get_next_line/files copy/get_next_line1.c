/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:21:19 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/05 19:10:19 by glopez-c         ###   ########.fr       */
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
/*
static char	*trim_line(char	**gnl)
{
	char	*res;
	int		i;
	char	**first;

	i = 0;
	first = gnl;
	if (ft_strchr(*gnl, '\n'))
		while ((*gnl)[i] != '\n')
			i++;
	else 
		i = ft_strlen(*gnl);
	if ((*gnl)[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while ((*gnl)[i] && (*gnl)[i] != '\n')
	{
		res[i] = (*gnl)[i];
		i++;
	}
	if ((*gnl)[i])
	{
		res[i] = (*gnl)[i];
		i++;
		res[i] = '\0';
		*gnl = (*gnl) + i + 1;
	}
	return (res);
}*/

static char	*trim_line(char **gnl)
{
	char	*res;
	int		i;
	char	*first;

	i = 0;
	first = *gnl;
	while ((*gnl)[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
	{
		free(*gnl);
		*gnl = NULL;
		return (NULL);
	}
	else
	{
		i = -1;
		while ((*gnl)[++i] != '\n')
			res[i] = (*gnl)[i];
		res[i] = '\n';
		res[++i] = '\0';
		first = ft_strdup((*gnl) + i);
		if (!first)
		{
			free(res);
			free(*gnl);
			*gnl = NULL;
			return (NULL);
		}
		else
		{
			free(*gnl);
			(*gnl) = first;
			return (res);
		}
	}
}

char	*ft_nonewline(char **gnl)
{
	char	*res;
	int		i;
	char	*first;

	i = 0;
	first = *gnl;
	while ((*gnl)[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
	{
		free(*gnl);
		*gnl = NULL;
		return (NULL);
	}
	else
	{
		i = -1;
		while ((*gnl)[++i])
			res[i] = (*gnl)[i];
		res[i] = '\0';
		free(*gnl);
		(*gnl) = NULL;
		return (res);
	}
}

char	*get_next_line(int fd)
{
	static char	*gnl[256];
	char		*buf;
	char		*res;
	int			i;

	buf = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (gnl[fd])
			free(gnl[fd]);
		gnl[fd] = NULL;
		return (NULL);
	}
	i = 1;
	if (!ft_strchr(gnl[fd], '\n'))
	{
		while (1)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i <= 0)
				break ;
			buf[i] = '\0';
			gnl[fd] = ft_strjoin(gnl[fd], buf);
			if (!gnl[fd])
				break ;
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	free(buf);
	if (i < 0 && gnl[fd])
	{
		free(gnl[fd]);
		gnl[fd] = NULL;
		return (NULL);
	}
	if (!gnl[fd])
		return (NULL);
	else if (i == 0 && !gnl[fd][0])
	{
		free(gnl[fd]);
		gnl[fd] = NULL;
		return (NULL);
	}
	else if (i == 0 && !ft_strchr(gnl[fd], '\n'))
	{
		res = ft_nonewline(&gnl[fd]);
		if (!res)
			return (NULL);
		return (res);
	}
	res = trim_line(&gnl[fd]);
	if (!res)
		return (NULL);
	return (res);
}
/*
int	main(){
	int	fd = open("hola", O_RDONLY);
	int	i;
	char *str;
	str = get_next_line(fd);
	i = 0;
	if (!str)
		write(1, "NULL RETURNED", 13);
	else
		while (str[i])
			write (1, &str[i++], 1);
	write(1, "1\n", 2);
	str = get_next_line(fd);
	i = 0;
	if (!str)
		write(1, "NULL RETURNED", 13);
	else
		while (str[i])
			write (1, &str[i++], 1);
	write(1, "2\n", 2);
	str = get_next_line(fd);
	i = 0;
	if (!str)
		write(1, "NULL RETURNED", 13);
 	else
		while (str[i])
			write (1, &str[i++], 1);
	write(1, "3\n", 2);
	str = get_next_line(fd);
	i = 0;
	if (!str)
		write(1, "NULL RETURNED", 13);
	else
		while (str[i])
			write (1, &str[i++], 1);
	write(1, "4\n", 2);
	str = get_next_line(fd);
	i = 0;
	if (!str)
		write(1, "NULL RETURNED", 13);
	else
		while (str[i])
			write (1, &str[i++], 1);
	write(1, "5\n", 2);
}*/
