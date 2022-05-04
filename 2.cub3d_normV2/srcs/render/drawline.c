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
	float	deltax;
	float	deltay;
	float	step;

	deltax = (*window)->xy->x2 - (*window)->xy->x1;
	deltay = (*window)->xy->y2 - (*window)->xy->y1;
	step = fabs(deltay);
	if (fabs(deltax) > step)
		step = fabs(deltax);
	deltax /= step;
	deltay /= step;
	while (fabs((*window)->xy->x2 - (*window)->xy->x1) > 1
		|| fabs((*window)->xy->y2 - (*window)->xy->y1) > 1)
	{
		put_pixel(window, (int)floor((*window)->xy->x1),
			(int)floor((*window)->xy->y1), color);
		(*window)->xy->x1 += deltax;
		(*window)->xy->y1 += deltay;
	}
}

void	draw_horz_line(t_window **window, double x1, double x2, double y)
{
	double	deltax;
	double	deltay;
	double	step;

	deltax = x2 - x1;
	deltay = 0;
	step = fabs(deltax);
	deltax /= step;
	deltay /= step;
	while (fabs(x2 - x1) > 0.01)
	{
		(*window)->map->m_img_data[
			(int)floor(y) * (*window)->w_width + (int)floor(x1)] = 0xC0C0C0;
		x1 += deltax;
		y += deltay;
	}
}

void	draw_vert_line(t_window **window, double x, double y1, double y2)
{
	double	deltax;
	double	deltay;
	double	step;

	deltax = 0;
	deltay = y2 - y1;
	step = fabs(deltay);
	deltax /= step;
	deltay /= step;
	while (fabs(y2 - y1) > 0.01)
	{
		(*window)->map->m_img_data[
			(int)floor(y1) * (*window)->w_width + (int)floor(x)] = 0xC0C0C0;
		x += deltax;
		y1 += deltay;
	}
}
