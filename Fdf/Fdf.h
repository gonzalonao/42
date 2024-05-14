/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:27:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 20:12:36 by glopez-c         ###   ########.fr       */
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

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef MAX_COLOUR
#  define MAX_COLOUR 0xFF0000FF
# endif

# ifndef MIN_COLOUR
#  define MIN_COLOUR 0x0000FFFF
# endif

# ifndef X_MARGIN
#  define X_MARGIN 50
# endif

# ifndef Y_MARGIN
#  define Y_MARGIN 50
# endif

typedef struct s_coords
{
	int				x;
	int				y;
	int				z;
	double			iso_x;
	double			iso_y;
	int				*colour;
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
	double	range_x;
	double	range_y;
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
	int		colour;
	double	percent;
}			t_line_utils;

uint8_t		ft_percent(uint8_t min, uint8_t max, double percent);
int			get_colour(double percent, int min_colour, int max_colour);
char		*ft_capitalize(char *str);
int			ft_colour_atoi_base(const char *str, const char *base);
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
char		***ft_readmap(int fd, int lines);
void		ft_free_split(char ***split);
void		ft_free_array(void **array);
void		ft_free_coords(t_coords *coords);
void		ft_mlx_error(t_coords *coords);
void		ft_image_error(t_coords *coords, mlx_t *mlx);
int			ft_countlines(int fd);
int			*colour_dup(int colour);

#endif
