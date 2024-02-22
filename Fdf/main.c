/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/22 22:04:57 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

/*void	ft_print_points(t_coords *coord, mlx_image_t *image)
{
	uint32_t	color;

	while (coord)
	{
		if (coord->z == 10)
			color = 0x00FF00FF;
		else
			color = 0xFF0000FF;
		mlx_put_pixel(image, (coord->iso_x * 15) + 500, (coord->iso_y * 15) + 500, color);
		mlx_put_pixel(image, (coord->iso_x * 15) + 501, coord->iso_y * 15 + 500, color);
		mlx_put_pixel(image, coord->iso_x * 15 + 500,( coord->iso_y * 15) + 501, color);
		mlx_put_pixel(image, (coord->iso_x * 15) + 499, coord->iso_y * 15 + 500, color);
		mlx_put_pixel(image, coord->iso_x * 15 + 500, (coord->iso_y * 15) + 499, color);
		coord = coord->next;
	}
}*/

void	ft_line(t_coords *coord1, t_coords *coord2, mlx_image_t *image)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(coord2->x - coord1->x);
	dy = abs(coord2->y - coord1->y);
	if (dx != 0)
		sx = (coord2->x - coord1->x) / dx;
	else
		sx = 0;
	if (dy != 0)
		sy = (coord2->y - coord1->y) / dy;
	else
		sy = 0;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	ft_printf("hola");
	while (coord1->x != coord2->x || coord1->y != coord2->y)
	{
		ft_printf("hola");
		mlx_put_pixel(image, (uint32_t)coord1->x,
			(uint32_t)coord1->y, 0xFF0000FF);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			coord1->x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			coord1->y += sy;
		}
	}
}

void	ft_show_points(t_coords *coord, mlx_image_t *image)
{
	while (coord)
	{
		ft_printf("\nx%iy%i", coord->x, coord->y);
		mlx_put_pixel(image, coord->x, coord->y, 0xFF0000FF);
		mlx_put_pixel(image, coord->x+1, coord->y, 0xFF0000FF);
		mlx_put_pixel(image, coord->x, coord->y+1, 0xFF0000FF);
		mlx_put_pixel(image, coord->x-1, coord->y, 0xFF0000FF);
		mlx_put_pixel(image, coord->x, coord->y-1, 0xFF0000FF);
		if (coord->right)
		{
			ft_line(coord, coord->right, image);
			ft_printf("hola");
		}
		if (coord->down)
		{
			ft_line(coord, coord->down, image);
			ft_printf("hola");
		}
		coord = coord->next;
	}
}

t_coords	*ft_new_coords(t_coords *next)
{
	t_coords	*coords;

	coords = malloc(sizeof(t_coords) * 1);
	coords->next = next;
	coords->right = NULL;
	coords->down = NULL;
	return (coords);
}

t_coords	*ft_find_right(t_coords *coords)
{
	t_coords	*right;

	right = coords->next;
	if (right)
	{
		if (right->y == coords->y && right->x == coords->x + 20)
			return (right);
		right = right->next;
	}
	return (NULL);
}

t_coords	*ft_find_down(t_coords *coords)
{
	t_coords	*down;

	down = coords->next;
	while (down)
	{
		if (down->x == coords->x && down->y == coords->y + 20)
			return (down);
		down = down->next;
	}
	return (NULL);
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
	i = 0;
	coords = ft_new_coords(NULL);
	first = coords;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			coords->x = j * 20 + 500;
			coords->y = i * 20 + 500;
			coords->z = ft_atoi(split[i][j]);
			if (split[i][j + 1])
				coords->next = ft_new_coords(NULL);
			coords = coords->next;
			j++;
		}
		i++;
	}
	//	ft_printf("%i%i%i%i%i%i%i%i%i", first->x, first->y, first->z, first->next->x, first->next->y, first->next->z,first->next->next->x, first->next->next->y, first->next->next->z);
	coords = first;
	while (coords)
	{
		coords->iso_x = (coords->x - coords->y) * 20 + 540;
		coords->iso_y = (((coords->x + coords->y) / 2) - coords->z) * 20 + 540;
		coords->right = ft_find_right(coords);
		coords->down = ft_find_down(coords);
		coords = coords->next;
	}
	mlx = mlx_init(1080, 1080, "Fdf", true);
	if (!mlx)
		return (-100);
	image = mlx_new_image(mlx, 1080, 1080);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (-100);
	ft_show_points(first, image);
	mlx_loop(mlx);
}
