/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:16:19 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 09:59:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_inter_c(char c, char *needle)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (needle[i])
	{
		if (needle[i] == c)
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	ft_inter(char *str, char *needle)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = ft_strlen(str);
	if (i == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (needle[j])
		{
			if (str[i] == needle[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (0);
		flag = 0;
		i++;
	}
	return (1);
}

void	calculate_mapsize_spritenum(t_window *window, char *line)
{
	int	len;
	int	i;

	window->map->m_height++;
	len = ft_strlen(line);
	if (len > window->map->m_width)
		window->map->m_width = len;
	i = 0;
	while (i < len)
	{
		if (line[i] == '2')
			window->num_sprites++;
		i++;
	}
}

int		check_mapfile_name(char *argv)
{
	int	len;
	len = ft_strlen(argv);

	if (argv[len - 1] != 'b' || argv[len - 2] != 'u'
		|| argv[len - 3] != 'c' || argv[len - 4] != '.')
	{
		printf("mapname error!\n");
		return (ERROR);
	}
	return (SUCCESS);
}

void	get_sprites_pos(t_window *window)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < window->map->m_height)
	{
		x = 0;
		while (x < window->map->m_width)
		{
			if (window->map->m_data[y][x] == '2')
			{
				window->sprites[i]->s_x = x + 0.5;
				window->sprites[i]->s_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}
