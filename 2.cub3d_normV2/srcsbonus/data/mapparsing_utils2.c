/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:16:19 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:12:33 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

int		ft_inter_c(char c, char *needle)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_inter(char *str, char *needle)
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

int		is_mapdata(char *line)
{
	if (line[0] == 'R')
		return (0);
	else if (line[0] == 'S' || line[0] == 'N'
		|| line[0] == 'W' || line[0] == 'E')
		return (0);
	else if (line[0] == 'F' || line[0] == 'C')
		return (0);
	else if (line[0] == '\0')
		return (0);
	return (1);
}

void	calculate_mapsize(t_window *window, char *line)
{
	int	len;

	window->map->m_height++;
	len = ft_strlen(line);
	if (len > window->map->m_width)
		window->map->m_width = len;
}

int		check_mapfile_name(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'b' || argv[len - 2] != 'u'
		|| argv[len - 3] != 'c' || argv[len - 4] != '.')
	{
		printf("Error\nMapname error\n");
		return (ERROR);
	}
	return (SUCCESS);
}
