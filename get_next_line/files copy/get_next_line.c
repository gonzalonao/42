/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:57 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/05 19:43:48 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == (char) c)
			return ((char *)s + i);
	if ((char) c == 0)
		return ((char *)s + i);
	return (NULL);
}

static char	*ft_free(char **gnl)
{
	free(*gnl);
	*gnl = NULL;
	return (NULL);
}

static char	*ft_trimline(char *gnl)
{
	char	*new_gnl;
	char	*str;
	int		len;

	str = ft_strchr(gnl, '\n');
	if (!str)
		return (ft_free(&gnl));
	else
		len = (str - gnl) + 1;
	if (!gnl[len])
		return (ft_free(&gnl));
	new_gnl = ft_substr(gnl, len, ft_strlen(gnl) - len);
	if (!new_gnl)
		return (NULL);
	return (new_gnl);
}

static char	*ft_getline(char *gnl)
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

static char	*ft_readline(int fd, char *gnl)
{
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&gnl));
	i = 1;
	while (!ft_strchr(buf, '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
	//	printf("%i", i);
		if (i == -1)
		{
			free(buf);
			free(gnl);
			gnl = NULL;
			return (NULL);
		}
		if (i == 0)
			break ;
		buf[i] = 0;
		gnl = ft_strjoin(gnl, buf);		
	}
	free(buf);
	return (gnl);
}

char	*get_next_line(int fd)
{
	static char	*gnl[256];
	char		*res;

	if (fd < 0)
		return (NULL);
	if (!gnl[fd])
		gnl[fd] = ft_readline(fd, NULL);
	else if (gnl[fd] && !ft_strchr(gnl[fd], '\n'))
		gnl[fd] = ft_readline(fd, gnl[fd]);
	if (!gnl[fd])
		return (NULL);
	res = ft_getline(gnl[fd]);
	if (!res)
		return (ft_free(&gnl[fd]));
	gnl[fd] = ft_trimline(gnl[fd]);
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
	fd = 100;
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
	i = read(100, str, 1);
	printf("%i", i);
}*/
