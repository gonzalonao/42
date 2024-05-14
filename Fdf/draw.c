/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:32:22 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 18:12:52 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_drawline(t_coords coord1, t_coords coord2,
	t_line_utils utils, mlx_image_t *image)
{
	while (coord1.iso_x != coord2.iso_x || coord1.iso_y != coord2.iso_y)
	{
		if (utils.dx > utils.dy)
			utils.percent = (double)(coord1.iso_x - utils.min)
				/ (utils.max - utils.min);
		else
			utils.percent = (double)(coord1.iso_y - utils.min)
				/ (utils.max - utils.min);
		utils.colour = get_colour(utils.percent, *coord1.colour, *coord2.colour);
		if (coord1.iso_x >= 0 && coord1.iso_x < WIDTH
			&& coord1.iso_y >= 0 && coord1.iso_y < HEIGHT)
			mlx_put_pixel(image, coord1.iso_x, coord1.iso_y, utils.colour);
		//free(utils.colour);
		utils.e2 = utils.err;
		if (utils.e2 > -utils.dx)
		{
			utils.err -= utils.dy;
			coord1.iso_x += utils.sx;
		}
		if (utils.e2 < utils.dy)
		{
			utils.err += utils.dx;
			coord1.iso_y += utils.sy;
		}
	}
}

void	ft_line(t_coords coord1, t_coords coord2, mlx_image_t *image)
{
	t_line_utils	utils;

	utils.dx = fabs(coord2.iso_x - coord1.iso_x);
	utils.dy = fabs(coord2.iso_y - coord1.iso_y);
	if (utils.dx != 0)
		utils.sx = (coord2.iso_x - coord1.iso_x) / utils.dx;
	else
		utils.sx = 1;
	if (utils.dy != 0)
		utils.sy = (coord2.iso_y - coord1.iso_y) / utils.dy;
	else
		utils.sy = 1;
	if (utils.dx > utils.dy)
	{
		utils.min = coord1.iso_x;
		utils.max = coord2.iso_x;
		utils.err = utils.dx / 2;
	}
	else
	{
		utils.min = coord1.iso_y;
		utils.max = coord2.iso_y;
		utils.err = -utils.dy / 2;
	}
	ft_drawline(coord1, coord2, utils, image);
}

void	ft_show_points(t_coords *coord, mlx_image_t *image)
{
	while (coord && coord->iso_x && coord->iso_y)
	{
		if (coord->iso_x >= 0 && coord->iso_x < WIDTH
			&& coord->iso_y >= 0 && coord->iso_y < HEIGHT)
			mlx_put_pixel(image, coord->iso_x, coord->iso_y, *coord->colour);
		if (coord->down)
			ft_line(*coord, *coord->down, image);
		if (coord->right)
			ft_line(*coord, *coord->right, image);
		coord = coord->next;
	}
	ft_free_coords(coord);
}
