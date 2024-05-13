/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/13 21:36:54 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_key_hook(mlx_key_data_t key_data, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
	{
		mlx_terminate(mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_close_func(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	mlx_terminate(mlx);
	exit(EXIT_SUCCESS);
}

int	ft_generate_image(t_coords *coords)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(1200, 1200, "Fdf", true);
	if (!mlx)
		ft_mlx_error(coords);
	mlx_close_hook(mlx, ft_close_func, mlx);
	mlx_key_hook(mlx, ft_key_hook, mlx);
	image = mlx_new_image(mlx, 1200, 1200);
	if (!image)
		ft_image_error(coords, mlx);
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
		ft_image_error(coords, mlx);
	ft_show_points(coords, image);
	mlx_loop(mlx);
	return (1);
}

void	ft_create_image(char ***split)
{
	t_coords	*coords;
	t_coords	*first;
	t_map		map;

	coords = ft_innit_coords(split);
	ft_free_split(split);
	if (!coords)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	first = coords;
	ft_transform_coords(coords);
	map = ft_innit_map(coords);
	coords = first;
	ft_adjust_values(coords, map);
	ft_generate_image(first);
}

int	main(int argc, char **argv)
{
	char	***split;
	int		fd;
	int		lines;

	if (argc != 2)
	{
		ft_printf("Wrong number of arguments");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	lines = ft_countlines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	split = ft_readmap(fd, lines);
	close(fd);
	if (!split)
	{
		ft_printf("Error reading file");
		return (0);
	}
	ft_create_image(split);
}
