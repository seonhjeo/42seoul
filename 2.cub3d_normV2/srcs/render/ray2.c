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
	t_window **window, float nexthorztouchx,
	float nexthorztouchy, float rayangle)
{
	float	xtocheck;
	float	ytocheck;

	while (is_inside_map(window, nexthorztouchx, nexthorztouchy))
	{
		xtocheck = nexthorztouchx;
		ytocheck = nexthorztouchy;
		if (israyfacingup(rayangle))
			ytocheck -= 1;
		if (has_wall_at(window, xtocheck, ytocheck) == 1)
		{
			(*window)->rc->horzwallhitx = nexthorztouchx;
			(*window)->rc->horzwallhity = nexthorztouchy;
			(*window)->rc->horzwalltex = 1;
			(*window)->rc->horzwallhit = true;
			break ;
		}
		else
		{
			nexthorztouchx += (*window)->rc->xstep;
			nexthorztouchy += (*window)->rc->ystep;
		}
	}
}

void	horizontal_ray(t_window **window, float rayangle)
{
	float	nexthorztouchx;
	float	nexthorztouchy;

	(*window)->rc->yintercept = floor((*window)->player->p_y);
	if (israyfacingdown(rayangle))
		(*window)->rc->yintercept += 1;
	(*window)->rc->xintercept = (*window)->player->p_x
		+ ((*window)->rc->yintercept - (*window)->player->p_y) / tan(rayangle);
	(*window)->rc->ystep = 1;
	if (israyfacingup(rayangle))
		(*window)->rc->ystep = -1;
	(*window)->rc->xstep = 1 / tan(rayangle);
	if (israyfacingleft(rayangle) && (*window)->rc->xstep > 0)
		(*window)->rc->xstep *= -1;
	if (israyfacingright(rayangle) && (*window)->rc->xstep < 0)
		(*window)->rc->xstep *= -1;
	nexthorztouchx = (*window)->rc->xintercept;
	nexthorztouchy = (*window)->rc->yintercept;
	horizontal_loop(window, nexthorztouchx, nexthorztouchy, rayangle);
}

void	vertical_loop(
	t_window **window, float nextverttouchx,
	float nextverttouchy, float rayangle)
{
	float	xtocheck;
	float	ytocheck;

	while (is_inside_map(window, nextverttouchx, nextverttouchy))
	{
		xtocheck = nextverttouchx;
		if (israyfacingleft(rayangle))
			xtocheck -= 1;
		ytocheck = nextverttouchy;
		if (has_wall_at(window, xtocheck, ytocheck) == 1)
		{
			(*window)->rc->vertwallhitx = nextverttouchx;
			(*window)->rc->vertwallhity = nextverttouchy;
			(*window)->rc->vertwalltex = 1;
			(*window)->rc->vertwallhit = true;
			break ;
		}
		else
		{
			nextverttouchx += (*window)->rc->xstep;
			nextverttouchy += (*window)->rc->ystep;
		}
	}
}

void	vertical_ray(t_window **window, float rayangle)
{
	float	nextverttouchx;
	float	nextverttouchy;

	(*window)->rc->xintercept = floor((*window)->player->p_x);
	if (israyfacingright(rayangle))
		(*window)->rc->xintercept += 1;
	(*window)->rc->yintercept = (*window)->player->p_y
		+ ((*window)->rc->xintercept - (*window)->player->p_x) * tan(rayangle);
	(*window)->rc->xstep = 1;
	if (israyfacingleft(rayangle))
		(*window)->rc->xstep = -1;
	(*window)->rc->ystep = tan(rayangle);
	if (israyfacingup(rayangle) && (*window)->rc->ystep > 0)
		(*window)->rc->ystep *= -1;
	if (israyfacingdown(rayangle) && (*window)->rc->ystep < 0)
		(*window)->rc->ystep *= -1;
	nextverttouchx = (*window)->rc->xintercept;
	nextverttouchy = (*window)->rc->yintercept;
	vertical_loop(window, nextverttouchx, nextverttouchy, rayangle);
}
