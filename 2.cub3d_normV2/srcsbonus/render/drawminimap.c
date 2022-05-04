/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:48:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:12:47 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

void	draw_square(t_window **window, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < (*window)->m_size)
	{
		dx = 0;
		while (dx < (*window)->m_size)
		{
			(*window)->map->m_img_data[
				(*window)->w_width * (y + dy) + (x + dx)] = color;
			dx++;
		}
		dy++;
	}
}

void	draw_squares(t_window **window)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*window)->map->m_height)
	{
		x = 0;
		while (x < (*window)->map->m_width)
		{
			if ((*window)->map->m_data[y][x] == '1')
				draw_square(window, (*window)->m_size * x,
					(*window)->m_size * y, 0x0000FF);
			else if ((*window)->map->m_data[y][x] == ' ')
				draw_square(window, (*window)->m_size * x,
					(*window)->m_size * y, 0x777777);
			else
				draw_square(window, (*window)->m_size * x,
					(*window)->m_size * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_lines(t_window **window)
{
	int		mapheight;
	int		mapwidth;
	int		i;

	mapheight = (*window)->m_size * (*window)->map->m_height;
	mapwidth = (*window)->m_size * (*window)->map->m_width;
	i = -1;
	while (i++ < (*window)->map->m_height)
		draw_horz_line(window, 0, mapwidth, (*window)->m_size * i);
	i = -1;
	while (i++ < (*window)->map->m_width)
		draw_vert_line(window, (*window)->m_size * i, 0, mapheight);
}

void	draw_minimap(t_window **window)
{
	draw_squares(window);
	draw_lines(window);
}
