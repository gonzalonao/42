/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:27:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/03/04 19:41:29 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_coords
{
	int				x;
	int				y;
	int				z;
	double			iso_x;
	double			iso_y;
	uint32_t		color;
	struct s_coords	*next;
	struct s_coords	*right;
	struct s_coords	*down;
}					t_coords;

typedef struct s_map
{
	int	width;
	int	height;
	int range_x;
	int range_y;
	int range_z;
	double max_range;
	int offset_x;
	int offset_y;
}			t_map;

#endif
