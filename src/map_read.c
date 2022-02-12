/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:10:21 by avalerio          #+#    #+#             */
/*   Updated: 2022/01/21 22:46:49 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_columns(char *file)
{
	int		width;
	int		fd;
	int		test_width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_error(2);
	width = count_wds(line, ' ');
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		test_width = count_wds(line, ' ');
		if (width != test_width)
			ft_error(4);
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}

static int	total_lines(char *file)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		lines++;
		free(line);
	}
	free(line);
	close(fd);
	return (lines);
}

static void	read_num(t_fdf *fdf, char *line, int i)
{
	int		j;
	int		n;
	char	**numbers;

	numbers = ft_split(line, ' ');
	n = 0;
	j = 0;
	while (numbers[n] && (j != fdf->map.columns))
	{
		fdf->map.z[i][j] = ft_atoi(numbers[n]);
		free(numbers[n]);
		j++;
		n++;
	}
	free(numbers);
}

void	map_read(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;

	fdf->map.columns = count_columns(file);
	fdf->map.lines = total_lines(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	fdf->map.z = (int **)malloc(sizeof(int *) * fdf->map.lines);
	if (fdf->map.z == NULL)
		ft_error(3);
	i = 0;
	while (get_next_line(fd, &line) == 1 && i != fdf->map.lines)
	{
		fdf->map.z[i] = (int *)malloc(sizeof(int) * fdf->map.columns);
		if (fdf->map.z[i] == NULL)
			ft_error(3);
		read_num(fdf, line, i);
		i++;
		free(line);
	}
	free(line);
	close(fd);
}
