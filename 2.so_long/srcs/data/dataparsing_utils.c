/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataparsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:05:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:33:11 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int		check_wall(t_window **window)
{
	int		i;

	i = 0;
	while (i < (*window)->m_height)
	{
		if ((*window)->m_data[i][0] != '1'
			|| (*window)->m_data[i][(*window)->m_width - 1] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < (*window)->m_width)
	{
		if ((*window)->m_data[0][i] != '1'
			|| (*window)->m_data[(*window)->m_height - 1][i] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		check_valid_map(t_window **window)
{
	int		exitflag;
	int		colflag;
	int		i;

	exitflag = 0;
	colflag = 0;
	i = 0;
	while (i < (*window)->m_height)
	{
		if (!ft_inter((*window)->m_data[i], "01CEP"))
			return (ERROR);
		if (ft_inter_c('E', (*window)->m_data[i]))
			exitflag++;
		i++;
	}
	colflag = find_col(window);
	if (exitflag == 0 || colflag == 0)
		return (ERROR);
	(*window)->colnum = colflag;
	return (SUCCESS);
}

int		find_player_pos(t_window **window)
{
	int		flag;
	int		i;
	int		j;

	flag = 0;
	i = 0;
	while (i < (*window)->m_height)
	{
		j = 0;
		while ((*window)->m_data[i][j])
		{
			if ((*window)->m_data[i][j] == 'P')
			{
				(*window)->py = i;
				(*window)->px = j;
				flag++;
			}
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (ERROR);
	return (SUCCESS);
}

void	save_mapdata(t_window **window, char *line)
{
	int	width;
	int	len;
	int	i;

	width = (*window)->m_width;
	i = 0;
	while ((*window)->m_data[i][0] != '\0')
		i++;
	len = ft_strlen(line);
	ft_strlcpy((*window)->m_data[i], line, width + 1);
}

int		write_mapfile(t_window **window, char *filename)
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
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res == 1)
			save_mapdata(window, line);
		free(line);
	}
	close(fd);
	return (SUCCESS);
}
