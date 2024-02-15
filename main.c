/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/14 18:48:35 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

t_coords	*ft_new_coords(t_coords *next)
{
	t_coords	*coords;

	coords = malloc(sizeof(t_coords) * 1);
	coords->next = next;
	return (coords);
}

int	main(int argc, char **argv)
{
	char		*line;
	int			fd;
	char		***split;
	int			i;
	int			j;
	t_coords	*coords;
	t_coords	*first;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Wrong number of arguments");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	split = (char ***)malloc(sizeof(char **) * (i + 1));
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		split[i++] = ft_split(line, ' ');
		line = get_next_line(fd);
	}
	split[i] = NULL;
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
			ft_printf(split[i][j]);
	}
	i = -1;
	coords = ft_new_coords(NULL);
	first = coords;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			coords->x = j;
			coords->y = i;
			coords->z = ft_atoi(split[i][j]);
			coords->next = ft_new_coords(NULL);
			coords = coords->next;
		}
	}
	//	ft_printf("%i%i%i%i%i%i%i%i%i", first->x, first->y, first->z, first->next->x, first->next->y, first->next->z,first->next->next->x, first->next->next->y, first->next->next->z);
	
	coords = first;
	while (coords)
	{
		coords->iso_x = coords->x - coords->y;
		coords->iso_y = ((coords->x + coords->y) / 2) - coords->z;
		coords = coords->next;
	}
}	
