/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/20 13:43:31 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_show_points(t_coords coord, mlx_image_t* image)
{
	while (coord)
	{
		mlx_put_pixel(image, (coord->iso_x) + 500, (coord->iso_y) + 500, 0xFF0000FF);
		coord = coord->next;
	}
}

void	ft_line(t_coords *coord1, t_coords *coord2, mlx_image_t *image)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

	dx = abs(coord2->iso_x - coord1->iso_x);
	dy = abs(coord2->iso_y - coord1->iso_y);
	sx = (coord2->iso_x - coord1->iso_x) / dx;
	sy = (coord2->iso_y - coord1->iso_y) / dy;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_put_pixel(image, coord1->iso_x, coord1->iso_y, 0xFF0000FF);
		if (coord1->iso_x == coord2->iso_x && coord1->iso_y == coord2->iso_y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			coord1->iso_x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			coord1->iso_y += sy;
		}
	}
}

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
	mlx_t		*mlx;
	mlx_image_t	*image;

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
	mlx = mlx_init(1080, 1080, "Fdf", true);
	if (!mlx)
		return (-100);
	image = mlx_new_image(mlx, 1080, 1080);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (-100);
	ft_show_points(first, image);
	mlx_loop(mlx);
}
