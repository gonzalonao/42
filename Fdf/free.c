/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:16:01 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/13 17:04:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_free_split(char ***split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			free(split[i][j]);
			j++;
		}
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_coords(t_coords *coords)
{
	t_coords	*tmp;

	while (coords)
	{
		tmp = coords->next;
		if (coords->color)
			free(coords->color);
		free(coords);
		coords = tmp;
	}
}
