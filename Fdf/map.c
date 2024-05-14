/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:44:44 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 16:47:53 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int	ft_countlines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

char	***ft_readmap(int fd, int lines)
{
	char	***split;
	char	*line;
	int		i;

	split = (char ***)malloc(sizeof(char **) * (lines + 1));
	if (!split)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		split[i++] = ft_split(line, ' ');
		if (!split[i - 1])
		{
			ft_free_split(split);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	split[i] = NULL;
	return (split);
}

t_map	ft_innit_map(t_coords *coords)
{
	t_map	map;

	map.min_x = INT_MAX;
	map.max_x = INT_MIN;
	map.min_y = INT_MAX;
	map.max_y = INT_MIN;
	map.min_z = INT_MAX;
	map.max_z = INT_MIN;
	while (coords)
	{
		map.min_x = fmin(map.min_x, coords->iso_x);
		map.max_x = fmax(map.max_x, coords->iso_x);
		map.min_y = fmin(map.min_y, coords->iso_y);
		map.max_y = fmax(map.max_y, coords->iso_y);
		map.min_z = fmin(map.min_z, coords->z);
		map.max_z = fmax(map.max_z, coords->z);
		coords = coords->next;
	}
	map.range_x = map.max_x - map.min_x;
	map.range_y = map.max_y - map.min_y;
	return (map);
}
