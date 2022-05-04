/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:16:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/18 12:12:59 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
	{
		*angle = TWO_PI + *angle;
	}
}

bool	is_inside_map(t_window **window, float x, float y)
{
	return (x >= 0 && x <= (*window)->map->m_width
		&& y >= 0 && y <= (*window)->map->m_height);
}

int	has_wall_at(t_window **window, float x, float y)
{
	int		mapGridIndexX;
	int		mapGridIndexY;

	if (!is_inside_map(window, x, y))
		return (1);
	mapGridIndexX = floor(x);
	mapGridIndexY = floor(y);
	if ((*window)->map->m_data[mapGridIndexY][mapGridIndexX] == '1'
		|| (*window)->map->m_data[mapGridIndexY][mapGridIndexX] == ' ')
		return (1);
	return (0);
}

char	getMapAt(t_window **window, int i, int j)
{
	return ((*window)->map->m_data[i][j]);
}

float	dis_between_p(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
