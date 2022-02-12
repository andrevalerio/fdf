/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:57:39 by avalerio          #+#    #+#             */
/*   Updated: 2022/01/21 23:05:39 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Translating world to screen coordinates with isometric projection
** ref: http://www.gandraxa.com/isometric_projection.xml
*/

static void	isometric(int *x, int *y, int z, t_fdf *fdf)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * fdf->map.angle_x;
	*y = -z + (old_x + old_y) * fdf->map.angle_y;
}

static void	horizontal_line(t_fdf *fdf, int x, int y)
{
	int	z0;
	int	z1;

	fdf->map.x0 = x * fdf->map.tile - (fdf->map.columns * fdf->map.tile) / 2;
	fdf->map.y0 = y * fdf->map.tile - (fdf->map.lines * fdf->map.tile) / 2;
	z0 = fdf->map.z[y][x] * fdf->map.tile / fdf->map.zoom;
	isometric(&fdf->map.x0, &fdf->map.y0, z0, fdf);
	fdf->map.x1 = (x + 1) * fdf->map.tile
		- (fdf->map.columns * fdf->map.tile) / 2;
	fdf->map.y1 = y * fdf->map.tile - (fdf->map.lines * fdf->map.tile) / 2;
	z1 = fdf->map.z[y][x + 1] * fdf->map.tile / fdf->map.zoom;
	isometric(&fdf->map.x1, &fdf->map.y1, z1, fdf);
	fdf->map.x0 += (WIN_W) / 2 + fdf->map.position_x;
	fdf->map.y0 += (WIN_H) / 2
		+ fdf->map.position_y;
	fdf->map.x1 += (WIN_W) / 2 + fdf->map.position_x;
	fdf->map.y1 += (WIN_H) / 2
		+ fdf->map.position_y;
	bresenham(fdf);
}

static void	vertical_line(t_fdf *fdf, int x, int y)
{
	int	z0;
	int	z1;

	fdf->map.x0 = x * fdf->map.tile - (fdf->map.columns * fdf->map.tile) / 2;
	fdf->map.y0 = y * fdf->map.tile - (fdf->map.lines * fdf->map.tile) / 2;
	z0 = fdf->map.z[y][x] * fdf->map.tile / fdf->map.zoom;
	isometric(&fdf->map.x0, &fdf->map.y0, z0, fdf);
	fdf->map.x1 = x * fdf->map.tile - (fdf->map.columns * fdf->map.tile) / 2;
	fdf->map.y1 = (y + 1) * fdf->map.tile
		- (fdf->map.lines * fdf->map.tile) / 2;
	z1 = fdf->map.z[y + 1][x] * fdf->map.tile / fdf->map.zoom;
	isometric(&fdf->map.x1, &fdf->map.y1, z1, fdf);
	fdf->map.x0 += (WIN_W) / 2 + fdf->map.position_x;
	fdf->map.y0 += (WIN_H) / 2
		+ fdf->map.position_y;
	fdf->map.x1 += (WIN_W) / 2 + fdf->map.position_x;
	fdf->map.y1 += (WIN_H) / 2
		+ fdf->map.position_y;
	bresenham(fdf);
}

static void	map_iterate(t_fdf *fdf, int y)
{
	int	x;

	while (fdf->map.lines > y)
	{
		x = 0;
		while (fdf->map.columns > x)
		{
			if (x + 1 < fdf->map.columns)
				horizontal_line(fdf, x, y);
			if (y + 1 < fdf->map.lines)
				vertical_line(fdf, x, y);
			x++;
		}
		y++;
	}
}

int	map_draw(t_fdf *fdf)
{
	int	y;

	fdf->mlx.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr, WIN_W, WIN_H);
	fdf->img.data = mlx_get_data_addr(fdf->mlx.img_ptr,
			&fdf->img.bpp, &fdf->img.size_l, &fdf->img.endian);
	y = 0;
	map_iterate(fdf, y);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr,
		fdf->mlx.win, fdf->mlx.img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img_ptr);
	return (0);
}
