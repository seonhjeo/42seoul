/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:05:43 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/18 16:33:08 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_vert_ray_values(
	t_window **window, float vertHitDistance, float rayangle, int col)
{
	bool	hitvert;

	hitvert = true;
	(*window)->rays[col]->r_distance = vertHitDistance;
	(*window)->rays[col]->r_wallHitX = (*window)->rc->vertwallhitX;
	(*window)->rays[col]->r_wallHitY = (*window)->rc->vertwallhitY;
	(*window)->rays[col]->r_direction = (*window)->rc->vertwalltex;
	(*window)->rays[col]->r_wasHitVert = hitvert;
	(*window)->rays[col]->r_rayAngle = rayangle;
	(*window)->rays[col]->r_texture = get_ray_texture(rayangle, hitvert);
}

void	put_horz_ray_values(
	t_window **window, float horzHitDistance, float rayangle, int col)
{
	bool	hitvert;

	hitvert = false;
	(*window)->rays[col]->r_distance = horzHitDistance;
	(*window)->rays[col]->r_wallHitX = (*window)->rc->horzwallhitX;
	(*window)->rays[col]->r_wallHitY = (*window)->rc->horzwallhitY;
	(*window)->rays[col]->r_direction = (*window)->rc->horzwalltex;
	(*window)->rays[col]->r_wasHitVert = hitvert;
	(*window)->rays[col]->r_rayAngle = rayangle;
	(*window)->rays[col]->r_texture = get_ray_texture(rayangle, hitvert);
}

void	calculate_ray(t_window **window, float rayangle, int col)
{
	float	horzHitDistance;
	float	vertHitDistance;

	if ((*window)->rc->horzwallhit)
	{
		horzHitDistance = dis_between_p(
				(*window)->player->p_x, (*window)->player->p_y,
				(*window)->rc->horzwallhitX, (*window)->rc->horzwallhitY);
	}
	else
		horzHitDistance = NUM_MAX;
	if ((*window)->rc->vertwallhit)
	{
		vertHitDistance = dis_between_p(
				(*window)->player->p_x, (*window)->player->p_y,
				(*window)->rc->vertwallhitX, (*window)->rc->vertwallhitY);
	}
	else
		vertHitDistance = NUM_MAX;
	if (vertHitDistance < horzHitDistance)
		put_vert_ray_values(window, vertHitDistance, rayangle, col);
	else
		put_horz_ray_values(window, horzHitDistance, rayangle, col);
}
