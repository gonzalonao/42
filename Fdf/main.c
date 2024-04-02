/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/03/22 16:51:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

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
	mlx_loop(mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	char		***split;
	t_coords	*coords;
	t_coords	*first;
	t_map		map;

	if (argc != 2)
	{
		ft_printf("Wrong number of arguments");
		return (0);
	}
	split = ft_readmap(argv[1]);
	if (!split)
	{
		ft_printf("Error reading file");
		return (0);
	}
	coords = ft_innit_coords(split);
	if (!coords)
	{
		ft_printf("Error creating coords");
		return (0);
	}
	first = coords;
	ft_transform_coords(coords);
	map = ft_innit_map(coords);
	coords = first;
	ft_adjust_values(coords, map);
	ft_generate_image(first);
}
