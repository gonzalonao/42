/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:46:11 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/13 21:13:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_transform_coords(t_coords *coords)
{
	int			x;
	int			y;
	int			z;
	t_coords	*first;

	first = coords;
	while (coords)
	{
		x = coords->x;
		y = coords->y;
		z = coords->z;
		coords->iso_x = x - y;
		coords->iso_y = (((double)x + (double)y) / 2) - (double)z;
		coords->right = ft_find_right(coords);
		coords->down = ft_find_down(coords);
		coords = coords->next;
	}
	coords = first;
}

void	ft_adjust_values(t_coords *coords, t_map map)
{
	int			max_color;
	int			min_color;
	t_coords	*first;
	double		percent;

	max_color = 0xFF0000FF;
	min_color = 0x0000FFFF;
	first = coords;
	while (coords)
	{
		coords->iso_x = round(1080 * (coords->iso_x - map.min_x)
				/ map.range_x + 20);
		coords->iso_y = round(1080 * (coords->iso_y - map.min_y)
				/ map.range_y + 20);
		if (!coords->color)
		{
			percent = (double)(coords->z - map.min_z)
				/ (map.max_z - map.min_z);
			coords->color = get_color(percent, min_color, max_color);
		}
		coords = coords->next;
	}
	coords = first;
}
