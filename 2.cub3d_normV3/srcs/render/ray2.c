/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:32:18 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/18 17:04:08 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	horizontal_loop(
	t_window **window, float nextHorzTouchX,
	float nextHorzTouchY, float rayangle)
{
	float	xToCheck;
	float	yToCheck;

	while (is_inside_map(window, nextHorzTouchX, nextHorzTouchY))
	{
		xToCheck = nextHorzTouchX;
		yToCheck = nextHorzTouchY;
		if (isRayFacingUp(rayangle))
			yToCheck -= 1;
		if (has_wall_at(window, xToCheck, yToCheck) == 1)
		{
			(*window)->rc->horzwallhitX = nextHorzTouchX;
			(*window)->rc->horzwallhitY = nextHorzTouchY;
			(*window)->rc->horzwalltex = 1;
			(*window)->rc->horzwallhit = true;
			break ;
		}
		else
		{
			nextHorzTouchX += (*window)->rc->xstep;
			nextHorzTouchY += (*window)->rc->ystep;
		}
	}
}

void	horizontal_ray(t_window **window, float rayangle)
{
	float	nextHorzTouchX;
	float	nextHorzTouchY;

	(*window)->rc->yintercept = floor((*window)->player->p_y);
	if (isRayFacingDown(rayangle))
		(*window)->rc->yintercept += 1;
	(*window)->rc->xintercept = (*window)->player->p_x
		+ ((*window)->rc->yintercept - (*window)->player->p_y) / tan(rayangle);
	(*window)->rc->ystep = 1;
	if (isRayFacingUp(rayangle))
		(*window)->rc->ystep = -1;
	(*window)->rc->xstep = 1 / tan(rayangle);
	if (isRayFacingLeft(rayangle) && (*window)->rc->xstep > 0)
		(*window)->rc->xstep *= -1;
	if (isRayFacingRight(rayangle) && (*window)->rc->xstep < 0)
		(*window)->rc->xstep *= -1;
	nextHorzTouchX = (*window)->rc->xintercept;
	nextHorzTouchY = (*window)->rc->yintercept;
	horizontal_loop(window, nextHorzTouchX, nextHorzTouchY, rayangle);
}

void	vertical_loop(
	t_window **window, float nextVertTouchX,
	float nextVertTouchY, float rayangle)
{
	float	xToCheck;
	float	yToCheck;

	while (is_inside_map(window, nextVertTouchX, nextVertTouchY))
	{
		xToCheck = nextVertTouchX;
		if (isRayFacingLeft(rayangle))
			xToCheck -= 1;
		yToCheck = nextVertTouchY;
		if (has_wall_at(window, xToCheck, yToCheck) == 1)
		{
			(*window)->rc->vertwallhitX = nextVertTouchX;
			(*window)->rc->vertwallhitY = nextVertTouchY;
			(*window)->rc->vertwalltex = 1;
			(*window)->rc->vertwallhit = true;
			break ;
		}
		else
		{
			nextVertTouchX += (*window)->rc->xstep;
			nextVertTouchY += (*window)->rc->ystep;
		}
	}
}

void	vertical_ray(t_window **window, float rayangle)
{
	float	nextVertTouchX;
	float	nextVertTouchY;

	(*window)->rc->xintercept = floor((*window)->player->p_x);
	if (isRayFacingRight(rayangle))
		(*window)->rc->xintercept += 1;
	(*window)->rc->yintercept = (*window)->player->p_y
		+ ((*window)->rc->xintercept - (*window)->player->p_x) * tan(rayangle);
	(*window)->rc->xstep = 1;
	if (isRayFacingLeft(rayangle))
		(*window)->rc->xstep = -1;
	(*window)->rc->ystep = tan(rayangle);
	if (isRayFacingUp(rayangle) && (*window)->rc->ystep > 0)
		(*window)->rc->ystep *= -1;
	if (isRayFacingDown(rayangle) && (*window)->rc->ystep < 0)
		(*window)->rc->ystep *= -1;
	nextVertTouchX = (*window)->rc->xintercept;
	nextVertTouchY = (*window)->rc->yintercept;
	vertical_loop(window, nextVertTouchX, nextVertTouchY, rayangle);
}
