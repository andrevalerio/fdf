/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:11:07 by avalerio          #+#    #+#             */
/*   Updated: 2021/11/02 18:45:48 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	line_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*line_gen(char *line)
{
	int		i;
	char	*new;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*static_upd(char *line_buff)
{
	char	*new;
	int		i;
	int		j;

	if (!line_buff)
		return (NULL);
	i = 0;
	while (line_buff[i] && line_buff[i] != '\n')
		i++;
	if (!line_buff[i])
	{
		free(line_buff);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(line_buff) - i + 1));
	if (new == NULL)
		return (NULL);
	j = 0;
	i++;
	while (line_buff[i])
		new[j++] = line_buff[i++];
	new[j] = '\0';
	free(line_buff);
	return (new);
}

static int	check_read_rt(int read_rt)
{
	if (read_rt == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			read_rt;
	char		*read_buff;
	static char	*line_buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buff == NULL)
		return (-1);
	read_rt = 1;
	while (!line_check(line_buff) && read_rt != 0)
	{
		read_rt = read(fd, read_buff, BUFFER_SIZE);
		if (read_rt == -1)
		{
			free(read_buff);
			return (-1);
		}
		read_buff[read_rt] = '\0';
		line_buff = strjoin_free(line_buff, read_buff);
	}
	free(read_buff);
	*line = line_gen(line_buff);
	line_buff = static_upd(line_buff);
	return (check_read_rt(read_rt));
}
