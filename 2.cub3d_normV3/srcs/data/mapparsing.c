/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:44:22 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 12:18:52 by seonhjeo         ###   ########.fr       */
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
		return (ERROR);
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (ft_inter(line, "012NSEW "))
			calculate_mapsize_spritenum(window, line);
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
		|| line[0] == 'W' || line [0] == 'E')
		res = get_texture_dir(line, window);
	else if (line[0] == 'F' || line[0] == 'C')
		res = get_color(line, window);
	else if (ft_inter(line, "012NSEW "))
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
		return (ERROR);
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
		return (ERROR);
	if (alloc_mapdata(&window) == ERROR)
		return (ERROR);
	if (alloc_sprite(&window) == ERROR)
		return (ERROR);
	if (alloc_visible_sprite(&window) == ERROR)
		return (ERROR);
	init_mapdata(window);
	if (write_mapfile(filename, window) == ERROR)
		return (ERROR);
	if (check_valid_mapdata(window) == ERROR)
		return (ERROR);
	get_sprites_pos(window);
	return (SUCCESS);
}

int	check_input_and_save_file(int argc, char **argv, t_window *window)
{
	if (argc != 2 && argc != 3)
		return (ERROR);
	if (check_mapfile_name(argv[1]) == ERROR)
		return (ERROR);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			window->w_save = 1;
		else
			return (ERROR);
	}
	if (saving_mapfile(argv[1], window) == ERROR)
	{
		free_window(&window);
		return (ERROR);
	}
	return (SUCCESS);
}
