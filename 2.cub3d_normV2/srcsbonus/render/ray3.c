/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:05:43 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:13:09 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

void	put_vert_ray_values(
	t_window **window, float verthitdistance, float rayangle, int col)
{
	bool	hitvert;

	hitvert = true;
	(*window)->rays[col]->r_distance = verthitdistance;
	(*window)->rays[col]->r_wallhitx = (*window)->rc->vertwallhitx;
	(*window)->rays[col]->r_wallhity = (*window)->rc->vertwallhity;
	(*window)->rays[col]->r_direction = (*window)->rc->vertwalltex;
	(*window)->rays[col]->r_washitvert = hitvert;
	(*window)->rays[col]->r_rayangle = rayangle;
	(*window)->rays[col]->r_texture = get_ray_texture(rayangle, hitvert);
}

void	put_horz_ray_values(
	t_window **window, float horzhitdistance, float rayangle, int col)
{
	bool	hitvert;

	hitvert = false;
	(*window)->rays[col]->r_distance = horzhitdistance;
	(*window)->rays[col]->r_wallhitx = (*window)->rc->horzwallhitx;
	(*window)->rays[col]->r_wallhity = (*window)->rc->horzwallhity;
	(*window)->rays[col]->r_direction = (*window)->rc->horzwalltex;
	(*window)->rays[col]->r_washitvert = hitvert;
	(*window)->rays[col]->r_rayangle = rayangle;
	(*window)->rays[col]->r_texture = get_ray_texture(rayangle, hitvert);
}

void	calculate_ray(t_window **window, float rayangle, int col)
{
	float	horzhitdistance;
	float	verthitdistance;

	if ((*window)->rc->horzwallhit)
	{
		horzhitdistance = dis_between_p(
				(*window)->player->p_x, (*window)->player->p_y,
				(*window)->rc->horzwallhitx, (*window)->rc->horzwallhity);
	}
	else
		horzhitdistance = NUM_MAX;
	if ((*window)->rc->vertwallhit)
	{
		verthitdistance = dis_between_p(
				(*window)->player->p_x, (*window)->player->p_y,
				(*window)->rc->vertwallhitx, (*window)->rc->vertwallhity);
	}
	else
		verthitdistance = NUM_MAX;
	if (verthitdistance < horzhitdistance)
		put_vert_ray_values(window, verthitdistance, rayangle, col);
	else
		put_horz_ray_values(window, horzhitdistance, rayangle, col);
}
