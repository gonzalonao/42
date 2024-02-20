/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:27:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:47:40 by codespace        ###   ########.fr       */
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
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_coords
{
	int				x;
	int				y;
	int				z;
	double			iso_x;
	double			iso_y;
	struct s_coords	*next;
}					t_coords;

typedef struct s_map
{
	int	width;
	int	height;
}			t_map;

#endif
