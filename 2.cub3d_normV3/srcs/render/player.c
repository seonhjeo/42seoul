/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:34:46 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/20 12:10:45 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	can_go_there(t_window **window, float newPlayerX, float newPlayerY)
{
	float	px;

	px = (*window)->player->p_size;
	if (has_wall_at(window, newPlayerX - px, newPlayerY)
		|| has_wall_at(window, newPlayerX + px, newPlayerY)
		|| has_wall_at(window, newPlayerX, newPlayerY - px)
		|| has_wall_at(window, newPlayerX, newPlayerY + px))
		return (0);
	return (1);
}

void	move_player(t_window **window)
{
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	(*window)->player->p_rotationAngle
		+= (*window)->player->p_turnDirection * (*window)->player->p_turnSpeed;
	normalize_angle(&((*window)->player->p_rotationAngle));
	moveStep = (*window)->player->p_walkDirection
		* (*window)->player->p_walkSpeed;
	newPlayerX = (*window)->player->p_x
		+ cos((*window)->player->p_rotationAngle) * moveStep;
	newPlayerY = (*window)->player->p_y
		+ sin((*window)->player->p_rotationAngle) * moveStep;
	if (can_go_there(window, newPlayerX, newPlayerY))
	{
		(*window)->player->p_x = newPlayerX;
		(*window)->player->p_y = newPlayerY;
	}
}

void	draw_player(t_window **window, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	player_size;

	y = floor((*window)->player->p_y * (*window)->m_size);
	x = floor((*window)->player->p_x * (*window)->m_size);
	player_size = PLAYER_SIZE * M_SCALE;
	dy = -(int)floor(player_size) / 2;
	while (dy < player_size / 2)
	{
		dx = -player_size / 2;
		while (dx < player_size / 2)
		{
			(*window)->map->m_img_data[
				(*window)->w_width * (y + dy) + (x + dx)] = color;
			dx++;
		}
		dy++;
	}
}
