/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:33:02 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 10:14:59 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_ceiling(t_window **window, int x)
{
	int	y;

	y = 0;
	while (y < (*window)->wc->wallTopY)
	{
		put_pixel(window, x, y, (*window)->w_color_ceiling);
		y++;
	}
}

void	draw_wall_proj(t_window **window, int x)
{

	int	y;

	y = 0;
	(*window)->wc->texNum = (*window)->rays[x]->r_texture;
	(*window)->wc->texWidth = (*window)->texture[(*window)->wc->texNum]->t_width;
	(*window)->wc->texHeight = (*window)->texture[(*window)->wc->texNum]->t_height;
	if ((*window)->rays[x]->r_wasHitVert)
		(*window)->wc->texOffsetX = (int)((*window)->rays[x]->r_wallHitY * (*window)->wc->texWidth) % (*window)->wc->texWidth;
	else
		(*window)->wc->texOffsetX = (int)((*window)->rays[x]->r_wallHitX * (*window)->wc->texWidth) % (*window)->wc->texWidth;
	y = (*window)->wc->wallTopY;
	while (y < (*window)->wc->wallBottomY)
	{
		(*window)->wc->distFromTop = y + ((*window)->wc->wallHeight / 2)
			- ((*window)->w_height / 2);
		(*window)->wc->texOffsetY = (*window)->wc->distFromTop
			* ((float)(*window)->wc->texHeight / (*window)->wc->wallHeight);
		(*window)->wc->texColor = (*window)->texture[(*window)->wc->texNum]
			->t_img_data[(*window)->wc->texWidth * (*window)->wc->texOffsetY
			+ (*window)->wc->texOffsetX];
		put_pixel(window, x, y, (*window)->wc->texColor);
		y++;
	}
}

void	draw_floor(t_window **window, int x)
{
	int	y;

	y = (*window)->wc->wallBottomY;
	while (y < (*window)->w_height)
	{
		put_pixel(window, x, y, (*window)->w_color_floor);
		y++;
	}
}

void	render_walls(t_window **window)
{
	int	x;

	x = 0;
	while (x < (*window)->w_width)
	{
		(*window)->wc->prepDis = (*window)->rays[x]->r_distance
			* cos((*window)->rays[x]->r_rayAngle - (*window)->player->p_rotationAngle);
		(*window)->wc->wallHeight = (WALL_HEIGHT / (*window)->wc->prepDis) * (*window)->wc->distProj;
		(*window)->wc->wallTopY = ((*window)->w_height / 2) - ((*window)->wc->wallHeight / 2);
		if ((*window)->wc->wallTopY < 0)
			(*window)->wc->wallTopY = 0;
		(*window)->wc->wallBottomY = ((*window)->w_height / 2) + ((*window)->wc->wallHeight / 2);
		if ((*window)->wc->wallBottomY > (*window)->w_height)
			(*window)->wc->wallBottomY = (*window)->w_height;
		draw_ceiling(window, x);
		draw_wall_proj(window, x);
		draw_floor(window, x);
		x++;
	}
}

