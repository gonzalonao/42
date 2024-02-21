/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:18:38 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/02 11:46:51 by glopez-c         ###   ########.fr       */
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
		return (NULL);
	i = -1;
	while ((*gnl)[++i] != '\n')
		res[i] = (*gnl)[i];
	res[i] = '\n';
	res[++i] = '\0';
	first = ft_strdup((*gnl) + i);
	if (!first)
	{
		free(res);
		return (NULL);
	}
	free(*gnl);
	(*gnl) = first;
	return (res);
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
		return (NULL);
	i = -1;
	while ((*gnl)[++i])
		res[i] = (*gnl)[i];
	res[i] = '\0';
	free(*gnl);
	(*gnl) = NULL;
	return (res);
}
*/

char	*ft_trimline(char *gnl)
{
	char	*new_gnl;
	char	*str;
	int		len;

	str = ft_strchr(gnl, '\n');
	if (!str)
	{
		new_gnl = NULL;
		return (NULL);
	}
	else 
		len = (str - gnl) + 1;
	if (!gnl[len])
		return (NULL);
	new_gnl = ft_substr(gnl, len, ft_strlen(gnl) - len);
	if (!new_gnl)
		return (NULL);
	return (new_gnl);
}

char	*ft_getline(char *gnl)
{
	char	*res;
	char	*str;
	int		len;

	str = ft_strchr(gnl, '\n');
	len = (str - gnl) + 1;
	res = ft_substr(gnl, 0, len);
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_readline(int fd, char *gnl)
{
	int		i;
	char	*buff;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		gnl = ft_strjoin(gnl, buff);
	}
	free(buff);
	if (i == -1)
		return (NULL);
	return (gnl);
}

char	*get_next_line(int fd)
{
	static char	*gnl[256];
	char		*res;

	if (fd < 0)
		return (NULL);
	if ((gnl[fd] && !ft_strchr(gnl[fd], '\n')) || !gnl[fd])
		gnl[fd] = ft_readline(fd , gnl[fd]);
	if (!gnl[fd])
		return (NULL);
	res = ft_getline(gnl[fd]);
	if (!line)
		return (NULL);
	gnl[fd] = ft_trimline(gnl[fd]);
	return (res);
}

/*
char	*get_next_line(int fd)
{
	static char	*gnl[256];
	char		*buf;
	char		*res;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
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
		return (res);
	}
	return (trim_line(&gnl[fd]));
}*/
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

