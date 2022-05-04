/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:44:22 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/28 14:50:27 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	calculating_mapsize(char *filename, t_window *window)
{
	char	*line;
	int		fd;
	int		res;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
	{
		printf("Error\nFile open error\n");
		return (ERROR);
	}
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (is_mapdata(line))
			calculate_mapsize(window, line);
		free(line);
	}
	close(fd);
	if (res == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	transfer_line_to_mapdata(char *line, t_window *window)
{
	int	res;

	if (line[0] == 'R')
		res = get_resolution(line, window);
	else if (line[0] == 'S' || line[0] == 'N'
		|| line[0] == 'W' || line[0] == 'E')
		res = get_texture_dir(line, window);
	else if (line[0] == 'F' || line[0] == 'C')
		res = get_color(line, window);
	else if (line[0] != '\0')
		res = save_mapdata(line, window);
	else
		return (ERROR);
	return (SUCCESS);
}

int	write_mapfile(char *filename, t_window *window)
{
	char	*line;
	int		fd;
	int		res;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
	{
		printf("Error\nFile open error\n");
		return (ERROR);
	}
	i = 0;
	res = 1;
	while (res > -1)
	{
		res = get_next_line(fd, &line);
		res += transfer_line_to_mapdata(line, window);
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

int	saving_mapfile(char *filename, t_window *window)
{
	if (calculating_mapsize(filename, window) == ERROR)
	{
		printf("Error\nMapsize calculating error\n");
		return (ERROR);
	}
	if (alloc_mapdata(&window) == ERROR)
		return (ERROR);
	init_mapdata(window);
	if (write_mapfile(filename, window) == ERROR)
	{
		printf("Error\nMapdata writing error\n");
		return (ERROR);
	}
	if (check_valid_mapdata(window) == ERROR)
	{
		printf("Error\nValidating mapdata error\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	check_input_and_save_file(int argc, char **argv, t_window *window)
{
	if (argc != 2)
	{
		printf("Error\nOnly one values can be input\n");
		return (ERROR);
	}
	if (check_mapfile_name(argv[1]) == ERROR)
		return (ERROR);
	if (saving_mapfile(argv[1], window) == ERROR)
	{
		printf("Error\nSaving_mapfile error\n");
		free_window(&window);
		return (ERROR);
	}
	return (SUCCESS);
}
