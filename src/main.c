/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:38:47 by avalerio          #+#    #+#             */
/*   Updated: 2022/01/21 23:01:08 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Proper use: ./fdf *.fdf\n", 1);
	if (i == 2)
		ft_putstr_fd("Error opening file!\n", 1);
	if (i == 3)
		ft_putstr_fd("Error with memory allocation!\n", 1);
	if (i == 4)
		ft_putstr_fd("Map not properly configured!\n", 1);
	exit (0);
}

static void	map_init(t_fdf *fdf)
{
	fdf->map.position_x = 0;
	fdf->map.position_y = 0;
	fdf->map.angle_x = cos(M_PI / 6);
	fdf->map.angle_y = sin(M_PI / 6);
	fdf->map.zoom = 1;
	if ((WIN_W / fdf->map.columns / 2) > (WIN_H / fdf->map.lines / 2))
	{
		if (WIN_H / fdf->map.lines / 2 < 4)
			fdf->map.tile = 2;
		else
			fdf->map.tile = WIN_H / fdf->map.lines / 2;
	}
	else
	{
		if (WIN_W / fdf->map.columns / 2 < 4)
			fdf->map.tile = 2;
		else
			fdf->map.tile = WIN_W / fdf->map.columns / 2;
	}
}

static void	fdf_free(t_fdf *fdf)
{
	int	i;

	mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win);
	mlx_destroy_display(fdf->mlx.mlx_ptr);
	free(fdf->mlx.mlx_ptr);
	i = 0;
	while (i < fdf->map.lines)
		free(fdf->map.z[i++]);
	free(fdf->map.z);
	free(fdf);
}

static int	map_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		fdf_free(fdf);
		exit(0);
	}
	else if (keycode == KEY_R)
		map_init(fdf);
	else if (keycode == KEY_W)
		fdf->map.position_y--;
	else if (keycode == KEY_S)
		fdf->map.position_y++;
	else if (keycode == KEY_D)
		fdf->map.position_x++;
	else if (keycode == KEY_A)
		fdf->map.position_x--;
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_error(1);
	else
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (fdf == NULL)
			return (-1);
		map_read(argv[1], fdf);
		map_init(fdf);
		fdf->mlx.mlx_ptr = mlx_init();
		fdf->mlx.win = mlx_new_window(fdf->mlx.mlx_ptr, WIN_W, WIN_H, TITLE);
		mlx_hook(fdf->mlx.win, 2, 1L << 0, map_keys, fdf);
		mlx_loop_hook(fdf->mlx.mlx_ptr, map_draw, fdf);
		mlx_loop(fdf->mlx.mlx_ptr);
	}
	return (0);
}
