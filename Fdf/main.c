/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/03/06 06:06:05 by glopez-c         ###   ########.fr       */
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

uint32_t ft_generate_color(int z, int min_z, int max_z, uint32_t min_color, uint32_t max_color)
{
    double percentage;
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    percentage = (double)(z - min_z) / (max_z - min_z);
    //printf("percentage: %f\n", percentage);

    uint8_t min_red = (min_color >> 16) & 0xFF;
    uint8_t max_red = (max_color >> 16) & 0xFF;
    red = min_red + (uint8_t)(percentage * (max_red - min_red));
    // printf("red: %u\n", red);
    // printf("max_red: %u\n", max_red);
    // printf("min_red: %u\n", min_red);

    uint8_t min_green = (min_color >> 8) & 0xFF;
    uint8_t max_green = (max_color >> 8) & 0xFF;
    green = min_green + (uint8_t)(percentage * (max_green - min_green));
   // printf("max_green2: %u\n", max_green);
   // printf("min_green2: %u\n", min_green);
   // printf("green2: %u\n", green);

    uint8_t min_blue = min_color & 0xFF;
    uint8_t max_blue = max_color & 0xFF;
    blue = min_blue + (uint8_t)(percentage * (max_blue - min_blue));
    // printf("blue: %u\n", blue);
    // printf("max_blue: %u\n", max_blue);
    // printf("min_blue: %u\n", min_blue);;
    return ((red << 16) | (green << 8) | blue);
}
/*
uint32_t ft_generate_color(int z, int min_z, int max_z, uint32_t min_color, uint32_t max_color)
{
	double percentage;
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	percentage = (double)(z - min_z) / (max_z - min_z);
	red = ((min_color >> 16) & 0xFF) + (uint8_t)(percentage * (((max_color >> 16) & 0xFF) - ((min_color >> 16) & 0xFF)));
	green = ((min_color >> 8) & 0xFF) + (uint8_t)(percentage * (((max_color >> 8) & 0xFF) - ((min_color >> 8) & 0xFF)));
	blue = (min_color & 0xFF) + (uint8_t)(percentage * ((max_color & 0xFF) - (min_color & 0xFF)));

	return ((red << 16) | (green << 8) | blue);
}
*/
/*{
	uint32_t max_color;
	uint32_t min_color;

	max_color = 0xFC25B1FF;
	min_color = 0x259AFCFF;
	double percentage = (double)(z - min_z) / (max_z - min_z);
	uint8_t red = ((min_color >> 16) & 0xFF) + (uint8_t)(percentage * (((max_color >> 16) & 0xFF) - ((min_color >> 16) & 0xFF)));
	uint8_t green = ((min_color >> 8) & 0xFF) + (uint8_t)(percentage * (((max_color >> 8) & 0xFF) - ((min_color >> 8) & 0xFF)));
	uint8_t blue = (min_color & 0xFF) + (uint8_t)(percentage * ((max_color & 0xFF) - (min_color & 0xFF)));

	return ((red << 16) | (green << 8) | blue);
}*/

uint32_t	ft_atoi_base(const char *str, const char *base)
{
	uint32_t	result;
	int			sign;
	int			i;
	int			j;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j])
			result = result * ft_strlen(base) + j;
		else
			break ;
		i++;
	}
	return (result * sign);
}

void	ft_line(t_coords coord1, t_coords coord2, mlx_image_t *image)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int max;
	int min;
	uint32_t color;


	dx = fabs(coord2.iso_x - coord1.iso_x);
	dy = fabs(coord2.iso_y - coord1.iso_y);
	if (dx != 0)
		sx = (coord2.iso_x - coord1.iso_x) / dx;
	else
		sx = 1;
	if (dy != 0)
		sy = (coord2.iso_y - coord1.iso_y) / dy;
	else
		sy = 1;
	if (dx > dy)
	{
		max = coord1.iso_x;
		min = coord2.iso_x;
		err = dx / 2;
	}
	else
	{
		max = coord1.iso_y;
		min = coord2.iso_y;
		err = -dy / 2;
	}
	//ft_printf("hola1");
	while (coord1.iso_x != coord2.iso_x || coord1.iso_y != coord2.iso_y)
	{
		if (dx > dy)
			color = ft_generate_color(coord1.iso_x, max, min, coord1.color, coord2.color);
		else
			color = ft_generate_color(coord1.iso_y, max, min, coord1.color, coord2.color);
		//if (coord1.iso_x >= 0 && coord1.iso_x < 1080 && coord1.iso_y >= 0 && coord1.iso_y < 1080)
		printf("Coord x: %f\nCoord y: %f\n", coord1.iso_x, coord1.iso_y);
		mlx_put_pixel(image, coord1.iso_x, coord1.iso_y, color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			coord1.iso_x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			coord1.iso_y += sy;
		}
	}
}

void	ft_show_points(t_coords *coord, mlx_image_t *image)
{
	while (coord)
	{
		//ft_printf("%i\n%i\n", coord->iso_x, coord->iso_y);
		printf("Coord x: %f\nCoord y: %f\n", coord->iso_x, coord->iso_y);
		if (coord->iso_x >= 0 && coord->iso_x < 1080 && coord->iso_y >= 0 && coord->iso_y < 1080)
		{
			mlx_put_pixel(image, coord->iso_x, coord->iso_y, coord->color);
			//ft_printf("hola2");
		}
		//mlx_put_pixel(image, coord->iso_x+1, coord->iso_y, 0xFF0000FF);
		//mlx_put_pixel(image, coord->iso_x, coord->iso_y+1, 0xFF0000FF);
		//mlx_put_pixel(image, coord->iso_x-1, coord->iso_y, 0xFF0000FF);
		//mlx_put_pixel(image, coord->iso_x, coord->iso_y-1, 0xFF0000FF);
		if (coord->down)
			ft_line(*coord, *coord->down, image);
		if (coord->right)
			ft_line(*coord, *coord->right, image);
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
		if (right->y == coords->y && right->x == coords->x + 1)
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
		if (down->x == coords->x && down->y == coords->y + 1)
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
	char		**split2;
	int			i;
	int			j;
	t_coords	*coords;
	t_coords	*first;
	t_map		map;
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
		j = 0;
		while (split[i][j])
			j++;
	}
	map.width = j;
	map.height = i;
	i = -1;
	coords = ft_new_coords(NULL);
	first = coords;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			split2 = ft_split(split[i][j], ',');
			coords->x = j;
			coords->y = i;
			coords->z = ft_atoi(split[i][j]);
			//ft_printf("hola3");
			if (split2[1] && split2[1][0] == '0' && split2[1][1] == 'x')
				coords->color = ft_atoi_base(split2[1] + 2, "0123456789ABCDEF");
			else
				coords->color = 0;
			if (split[i][j + 1] || split[i + 1])
				coords->next = ft_new_coords(NULL);
			coords = coords->next;
		}
	}
	// ft_printf("hola4");
	//	ft_printf("%i%i%i%i%i%i%i%i%i", first->x, first->y, first->z, first->next->x, first->next->y, first->next->z,first->next->next->x, first->next->next->y, first->next->next->z);
	coords = first;
	while (coords)
	{
		coords->iso_x = coords->x - coords->y;
		coords->iso_y = (((double)coords->x + (double)coords->y) / 2) - (double)coords->z;
		//printf("Coord x: %f\nCoord y: %f\n", coords->iso_x, coords->iso_y);
		coords->right = ft_find_right(coords);
		coords->down = ft_find_down(coords);
		coords = coords->next;
	}
	coords = first;
	double min_x;
	double max_x;
	double min_y;
	double max_y;
	double min_z;
	double max_z;

	min_x = INT_MAX;
	max_x = INT_MIN;
	min_y = INT_MAX;
	max_y = INT_MIN;
	min_z = INT_MAX;
	max_z = INT_MIN;
	while (coords)
	{
		min_x = fmin(min_x, coords->iso_x);
		max_x = fmax(max_x, coords->iso_x);
		min_y = fmin(min_y, coords->iso_y);
		max_y = fmax(max_y, coords->iso_y);
		min_z = fmin(min_z, coords->z);
		max_z = fmax(max_z, coords->z);
		coords = coords->next;
	}
	//ft_printf("%i%i\n", max_x, max_y);
	map.offset_x = fmax(-min_x, 0);
	map.offset_y = fmax(-min_y, 0);
	map.range_x = max_x - min_x;
	map.range_y = max_y - min_y;
	map.range_z = max_z - min_z;
	map.max_range = fmax(map.range_x, map.range_y);
	ft_printf("Range_x: %i\n", map.range_x);
	ft_printf("Range_y: %i\n", map.range_y);
	ft_printf("Range_z: %i\n", map.range_z);
	coords = first;
	uint32_t max_color = 0xFC25B1FF;
	uint32_t min_color = 0x259AFCFF;
	while (coords)
	{
		coords->iso_x = round(coords->iso_x * (1080 / map.range_x) - (min_x) * (1080 / map.range_x));
		coords->iso_y = round(coords->iso_y * (1080 / map.range_y) - (min_y) * (1080 / map.range_y));
		//ft_printf("hola5");
		if (!coords->color)
			coords->color = ft_generate_color(coords->z, min_z, max_z, max_color, min_color);
		coords = coords->next;
	}
	//ft_printf("hola6");
	mlx = mlx_init(1200, 1200, "Fdf", true);
	if (!mlx)
		return (-100);
	image = mlx_new_image(mlx, 1080, 1080);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (-100);
	//ft_printf("hola7");
	ft_show_points(first, image);
	mlx_loop(mlx);
}
