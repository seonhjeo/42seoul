/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:47:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/20 12:32:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_window **window, int x, int y, int color)
{
	(*window)->map->m_img_data[y * (*window)->w_width + x] = color;
}

void	draw_line(t_window **window, int color)
{
	float	deltaX;
	float	deltaY;
	float	step;

	deltaX = (*window)->xy->x2 - (*window)->xy->x1;
	deltaY = (*window)->xy->y2 - (*window)->xy->y1;
	step = fabs(deltaY);
	if (fabs(deltaX) > step)
		step = fabs(deltaX);
	deltaX /= step;
	deltaY /= step;
	while (fabs((*window)->xy->x2 - (*window)->xy->x1) > 1
		|| fabs((*window)->xy->y2 - (*window)->xy->y1) > 1)
	{
		put_pixel(window, (int)floor((*window)->xy->x1),
			(int)floor((*window)->xy->y1), color);
		(*window)->xy->x1 += deltaX;
		(*window)->xy->y1 += deltaY;
	}
}

void	draw_horz_line(t_window **window, double x1, double x2, double y)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = 0;
	step = fabs(deltaX);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01)
	{
		(*window)->map->m_img_data[
			(int)floor(y) * (*window)->w_width + (int)floor(x1)] = 0xC0C0C0;
		x1 += deltaX;
		y += deltaY;
	}
}

void	draw_vert_line(t_window **window, double x, double y1, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = 0;
	deltaY = y2 - y1;
	step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(y2 - y1) > 0.01)
	{
		(*window)->map->m_img_data[
			(int)floor(y1) * (*window)->w_width + (int)floor(x)] = 0xC0C0C0;
		x += deltaX;
		y1 += deltaY;
	}
}
