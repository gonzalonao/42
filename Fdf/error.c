/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:34:44 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/13 21:34:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	ft_mlx_error(t_coords *coords)
{
	ft_free_coords(coords);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_image_error(t_coords *coords, mlx_t *mlx)
{
	ft_free_coords(coords);
	mlx_terminate(mlx);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
