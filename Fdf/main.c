/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/10 18:46:37 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_key_hook(mlx_key_data_t key_data, void *param)
{
	mlx_image_t	*image;

	image = (mlx_image_t *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
	{
		write(1, "ESC pressed\n", 12);
	}
}

int	ft_generate_image(t_coords *coords)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(1200, 1200, "Fdf", true);
	if (!mlx)
		return (-100);
	image = mlx_new_image(mlx, 1200, 1200);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		return (-100);
	ft_show_points(coords, image);
	mlx_key_hook(mlx, ft_key_hook, image);
	mlx_loop(mlx);
	return (1);
}

void	main2(char ***split)
{
	t_coords	*coords;
	t_coords	*first;
	t_map		map;

	coords = ft_innit_coords(split);
	ft_free_split(split);
	if (!coords)
	{
		ft_printf("Error creating coords");
		exit(0);
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
	main2(split);
}
