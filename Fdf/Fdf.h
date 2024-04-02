/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:27:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/03/22 16:23:21 by glopez-c         ###   ########.fr       */
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
	int				*color;
	struct s_coords	*next;
	struct s_coords	*right;
	struct s_coords	*down;
}					t_coords;

typedef struct s_map
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	min_z;
	double	max_z;
	int		width;
	int		height;
	int		range_x;
	int		range_y;
	int		range_z;
	double	max_range;
	int		offset_x;
	int		offset_y;
}			t_map;

typedef struct s_line_utils
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		max;
	int		min;
	int		color;
	double	percent;
}			t_line_utils;

uint8_t		ft_percent(uint8_t min, uint8_t max, double percent);
int			*get_color(double percent, int min_color, int max_color);
char		*ft_capitalize(char *str);
int			*ft_atoi_base(const char *str, const char *base);
void		ft_drawline(t_coords coord1, t_coords coord2,
				t_line_utils utils, mlx_image_t *image);
void		ft_line(t_coords coord1, t_coords coord2, mlx_image_t *image);
void		ft_show_points(t_coords *coords, mlx_image_t *image);
t_coords	*ft_new_coords(t_coords *next);
t_coords	*ft_find_right(t_coords *coords);
t_coords	*ft_find_down(t_coords *coords);
void		ft_get_coords(t_coords *coords, char **split, int i, int j);
t_coords	*ft_innit_coords(char ***split);
void		ft_transform_coords(t_coords *coords);
void		ft_adjust_values(t_coords *coords, t_map map);
t_map		ft_innit_map(t_coords *coords);
char		***ft_readmap(char *argv);
void		ft_free_split(char ***split);
void		ft_free_array(void **array);
int			ft_countlines(char *argv);

#endif
