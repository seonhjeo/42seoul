/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:45:43 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/28 14:16:31 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		save_mapdata(char *line, t_window *window)
{
	int	width;
	int	len;
	int	i;
	int	j;

	width = window->map->m_width;
	i = 0;
	while (window->map->m_data[i][0] != '\0')
		i++;
	len = ft_strlen(line);
	ft_strlcpy(window->map->m_data[i], line, width + 1);
	if (len < width)
	{
		j = 0;
		while (j + len < width)
			window->map->m_data[i][len + j++] = ' ';
		window->map->m_data[i][len + j] = '\0';
	}
	return (SUCCESS);
}

void	get_player_dir(t_window *window, int x, int y)
{
	if (window->map->m_data[y][x] == 'S')
		window->player->p_rotationangle = PI / 2;
	else if (window->map->m_data[y][x] == 'N')
		window->player->p_rotationangle = PI / 2 * 3;
	else if (window->map->m_data[y][x] == 'E')
		window->player->p_rotationangle = PI;
	else if (window->map->m_data[y][x] == 'W')
		window->player->p_rotationangle = 0;
}

int		check_player_pos(t_window *window)
{
	int	flag;
	int	x;
	int	y;

	flag = 0;
	y = 0;
	while (y < window->map->m_height)
	{
		x = 0;
		while (x < window->map->m_width)
		{
			if (ft_inter_c(window->map->m_data[y][x], "NSEW"))
			{
				flag++;
				window->player->p_x = x + 0.5;
				window->player->p_y = y + 0.5;
				get_player_dir(window, x, y);
			}
			x++;
		}
		y++;
	}
	if (flag != 1)
		return (ERROR);
	return (SUCCESS);
}

int		check_around_value(t_window *window, int x, int y)
{
	if (x == 0 || y == 0
		|| x == window->map->m_width - 1
		|| y == window->map->m_height - 1)
	{
		printf("Error\nWrong map in %d %d!\n", y, x);
		return (ERROR);
	}
	if (!ft_inter_c(window->map->m_data[y][x - 1], "012NSEW")
		|| !ft_inter_c(window->map->m_data[y][x + 1], "012NSEW")
		|| !ft_inter_c(window->map->m_data[y - 1][x], "012NSEW")
		|| !ft_inter_c(window->map->m_data[y + 1][x], "012NSEW"))
	{
		printf("Error\nWrong map!\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int		check_valid_mapdata(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->map->m_height)
	{
		x = 0;
		while (x < window->map->m_width)
		{
			if (!ft_inter_c(window->map->m_data[y][x], "01NSEW "))
			{
				printf("Error\nNot valid mapdata character at %d %d\n", x, y);
				return (ERROR);
			}
			if (ft_inter_c(window->map->m_data[y][x], "0NSEW"))
			{
				if (check_around_value(window, x, y) == ERROR)
					return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (check_player_pos(window));
}
