/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:27:00 by avalerio          #+#    #+#             */
/*   Updated: 2022/01/19 23:10:15 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = (x * fdf->img.bpp / 8) + (y * fdf->img.size_l);
		fdf->img.data[i] = color;
		fdf->img.data[++i] = color >> 8;
		fdf->img.data[++i] = color >> 16;
	}
}

/*
** Draw the line by DDA algorithm
** https://www.geeksforgeeks.org/dda-line-generation-algorithm-computer-graphics/
*/
static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	delta_calc(t_fdf *fdf, t_point *delta)
{
	delta->x = ft_abs(fdf->map.x1 - fdf->map.x0);
	delta->y = ft_abs(fdf->map.y1 - fdf->map.y0);
}

static void	signal_calc(t_fdf *fdf, t_point *sign)
{
	sign->x = 1;
	sign->y = 1;
	if (fdf->map.x0 > fdf->map.x1)
		sign->x *= -1;
	if (fdf->map.y0 > fdf->map.y1)
		sign->y *= -1;
}

void	bresenham(t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	error;
	t_point	p0;

	delta_calc(fdf, &delta);
	error.x = delta.x - delta.y;
	p0.x = fdf->map.x0;
	p0.y = fdf->map.y0;
	signal_calc(fdf, &sign);
	while (p0.x != fdf->map.x1 || p0.y != fdf->map.y1)
	{
		draw_pixel(fdf, p0.x, p0.y, 0x00FFFFff);
		error.y = error.x * 2;
		if (error.y > -delta.y)
		{
			error.x -= delta.y;
			p0.x += sign.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			p0.y += sign.y;
		}
	}
}
