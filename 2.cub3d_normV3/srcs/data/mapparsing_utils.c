/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:56:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/25 16:00:51 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_splited_lines(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	get_resolution(char *line, t_window *window)
{
	char	**buf;

	buf = ft_split(line, ' ');
	if (buf == NULL)
		return (ERROR);
	window->w_width = ft_atoi(buf[1]);
	window->w_height = ft_atoi(buf[2]);
	free_splited_lines(buf);
	if (window->w_width < MIN_WIDTH || window->w_width > MAX_WIDTH)
		window->w_width = DEFAULT_WIDTH;
	if (window->w_height < MIN_HEIGHT || window->w_height > MAX_HEIGHT)
		window->w_height = DEFAULT_HEIGHT;
	return (SUCCESS);
}

int	get_texture_quarter(char *line)
{
	int		res;

	res = ft_strcmp(line, "NO");
	if (res == 0)
		return (0);
	res = ft_strcmp(line, "SO");
	if (res == 0)
		return (1);
	res = ft_strcmp(line, "WE");
	if (res == 0)
		return (2);
	res = ft_strcmp(line, "EA");
	if (res == 0)
		return (3);
	res = ft_strcmp(line, "S");
	if (res == 0)
		return (4);
	return (ERROR);
}

int	get_texture_dir(char *line, t_window *window)
{
	char	**buf;
	int		res;

	buf = ft_split(line, ' ');
	if (buf == NULL)
		return (ERROR);
	res = get_texture_quarter(buf[0]);
	if (res == ERROR)
	{
		free_splited_lines(buf);
		return (ERROR);
	}
	window->texture[res]->t_path = ft_strdup(buf[1]);
	free_splited_lines(buf);
	return (SUCCESS);
}

int	get_color(char *line, t_window *window)
{
	char	**buf;
	char	**code;

	buf = ft_split(line, ' ');
	code = ft_split(buf[1], ',');
	if (!buf || !code)
	{
		free_splited_lines(code);
		free_splited_lines(buf);
		return (ERROR);
	}
	if (ft_strcmp(buf[0], "F"))
		window->w_color_floor = (ft_atoi(code[0]) << 16)
			+ (ft_atoi(code[1]) << 8) + (ft_atoi(code[2]));
	else if (ft_strcmp(buf[0], "C"))
		window->w_color_ceiling = (ft_atoi(code[0]) << 16)
			+ (ft_atoi(code[1]) << 8) + (ft_atoi(code[2]));
	free_splited_lines(code);
	free_splited_lines(buf);
	return (SUCCESS);
}
