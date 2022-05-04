/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:34:46 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 15:06:38 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

int		can_go_there(t_window **window, float newplayerx, float newplayery)
{
	float	px;

	px = (*window)->player->p_size;
	if (has_wall_at(window, newplayerx - px, newplayery)
		|| has_wall_at(window, newplayerx + px, newplayery)
		|| has_wall_at(window, newplayerx, newplayery - px)
		|| has_wall_at(window, newplayerx, newplayery + px))
		return (0);
	return (1);
}

void	move_player(t_window **window)
{
	float	movestep;
	float	movestep2;
	float	newplayerx;
	float	newplayery;

	(*window)->player->p_rotationangle +=
		(*window)->player->p_turndirection * (*window)->player->p_turnspeed;
	normalize_angle(&((*window)->player->p_rotationangle));
	movestep = (*window)->player->p_walkdirection
		* (*window)->player->p_walkspeed;
	movestep2 = (*window)->player->p_walksidedir
		* (*window)->player->p_walkspeed;
	newplayerx = (*window)->player->p_x
		+ cos((*window)->player->p_rotationangle) * movestep
		+ cos((*window)->player->p_rotationangle + PI / 2) * movestep2;
	newplayery = (*window)->player->p_y
		+ sin((*window)->player->p_rotationangle) * movestep
		+ sin((*window)->player->p_rotationangle + PI / 2) * movestep2;
	if (can_go_there(window, newplayerx, newplayery))
	{
		(*window)->player->p_x = newplayerx;
		(*window)->player->p_y = newplayery;
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
