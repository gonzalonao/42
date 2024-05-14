/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:37:38 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 20:26:28 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

t_coords	*ft_new_coords(t_coords *next)
{
	t_coords	*coords;

	coords = malloc(sizeof(t_coords) * 1);
	coords->next = next;
	coords->right = NULL;
	coords->down = NULL;
	coords->colour = NULL;
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

void	ft_get_coords(t_coords *coords, char **split, int i, int j)
{
	int			colour;
	t_coords	*first;

	first = coords;
	while (coords->next)
		coords = coords->next;
	coords->x = j;
	coords->y = i;
	coords->z = ft_atoi(split[0]);
	if (split[1] && split[1][0] == '0' && split[1][1] == 'x')
	{
		colour = ft_colour_atoi_base(ft_capitalize(split[1] + 2),
				"0123456789ABCDEF");
		coords->colour = colour_dup(colour);
		if (!coords->colour)
			ft_mlx_error(first);
	}
	else
		coords->colour = NULL;
}

t_coords	*ft_innit_coords(char ***split)
{
	t_coords	*coords;
	t_coords	*first;
	char		**split2;
	int			i;
	int			j;

	coords = ft_new_coords(NULL);
	if (!coords)
		return (NULL);
	first = coords;
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			split2 = ft_split(split[i][j], ',');
			ft_get_coords(coords, split2, i, j);
			ft_free_array((void **)split2);
			if (split[i][j + 1] || split[i + 1])
				coords->next = ft_new_coords(NULL);
			coords = coords->next;
		}
	}
	return (first);
}
