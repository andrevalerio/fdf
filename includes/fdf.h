/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:08:47 by avalerio          #+#    #+#             */
/*   Updated: 2022/01/19 23:17:31 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "keys.h"

# define WIN_W		1200
# define WIN_H		900
# define TITLE		"fdf"

typedef struct s_img
{
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img_ptr;
}				t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	int		**z;
	int		lines;
	int		columns;
	int		position_x;
	int		position_y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	float	angle_x;
	float	angle_y;
	float	tile;
	int		zoom;
}				t_map;

typedef struct s_fdf
{
	t_img	img;
	t_mlx	mlx;
	t_map	map;
}				t_fdf;

void	ft_error(int i);

void	map_read(char *file, t_fdf *fdf);

int		map_draw(t_fdf *fdf);

void	bresenham(t_fdf *fdf);

#endif