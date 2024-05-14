/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:46:11 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 18:15:42 by glopez-c         ###   ########.fr       */
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
	t_coords	*first;
	double		percent;

	first = coords;
	while (coords)
	{
		coords->iso_x = round((WIDTH - X_MARGIN * 2)
				* (coords->iso_x - map.min_x) / map.range_x + X_MARGIN);
		coords->iso_y = round((HEIGHT - Y_MARGIN * 2)
				* (coords->iso_y - map.min_y) / map.range_y + Y_MARGIN);
		if (!coords->colour)
		{
			percent = (double)(coords->z - map.min_z)
				/ (map.max_z - map.min_z);
			coords->colour = colour_dup(
					get_colour(percent, MIN_COLOUR, MAX_COLOUR));
			if (!coords->colour)
				ft_mlx_error(coords);
		}
		coords = coords->next;
	}
	coords = first;
}
