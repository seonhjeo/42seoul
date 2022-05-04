/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:10:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:04:13 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int		calculate_mapsize(t_window *window, char *line)
{
	int	len;

	if (line[0] != '\0')
	{
		window->m_height++;
		len = ft_strlen(line);
		if (window->m_width == 0)
			window->m_width = len;
		if (window->m_width != 0 && window->m_width != len)
			return (ERROR);
	}
	return (SUCCESS);
}

int		calculating_mapsize(t_window *window, char *filename)
{
	char	*line;
	int		fd;
	int		res;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		return (ERROR);
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (calculate_mapsize(window, line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		free(line);
	}
	close(fd);
	if (res == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		save_map(t_window **window, char *filename)
{
	if (alloc_mapdata(window) == ERROR)
		return (ERROR);
	init_mapdata((*window));
	if (write_mapfile(window, filename) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		check_and_save_file(t_window **window, char *filename)
{
	if (calculating_mapsize((*window), filename) == ERROR
		|| save_map(window, filename) == ERROR)
	{
		ft_putstr("Error\nFail to loading mapdata\n");
		free_window(window);
		return (ERROR);
	}
	if (check_wall(window) == ERROR
		|| check_valid_map(window) == ERROR
		|| find_player_pos(window) == ERROR)
	{
		ft_putstr("Error\nNot a valid mapdata\n");
		free_window(window);
		return (ERROR);
	}
	return (SUCCESS);
}
