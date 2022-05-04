/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:10:30 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:13:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

void	init_rc(t_window **window)
{
	(*window)->rc->horzwallhit = false;
	(*window)->rc->horzwallhitx = 0;
	(*window)->rc->horzwallhity = 0;
	(*window)->rc->horzwalltex = 0;
	(*window)->rc->vertwallhit = false;
	(*window)->rc->vertwallhitx = 0;
	(*window)->rc->vertwallhity = 0;
	(*window)->rc->vertwalltex = 0;
}

void	cast_ray(t_window **window, float rayangle, int col)
{
	init_rc(window);
	normalize_angle(&rayangle);
	horizontal_ray(window, rayangle);
	vertical_ray(window, rayangle);
	calculate_ray(window, rayangle, col);
}

void	cast_all_rays(t_window **window)
{
	float	rayangle;
	int		col;

	col = 0;
	while (col < (*window)->w_width)
	{
		rayangle = (*window)->player->p_rotationangle
			+ atan((col - (*window)->w_width / 2) / (*window)->dist_proj);
		cast_ray(window, rayangle, col);
		col++;
	}
}

void	draw_rays(t_window **window)
{
	int	i;

	i = 0;
	while (i < (*window)->w_width)
	{
		(*window)->xy->x1 = (*window)->player->p_x * (*window)->m_size;
		(*window)->xy->y1 = (*window)->player->p_y * (*window)->m_size;
		(*window)->xy->x2 = (*window)->rays[i]->r_wallhitx * (*window)->m_size;
		(*window)->xy->y2 = (*window)->rays[i]->r_wallhity * (*window)->m_size;
		draw_line(window, 0xFF0000);
		i += RAY_DRAW_TERM;
	}
}
