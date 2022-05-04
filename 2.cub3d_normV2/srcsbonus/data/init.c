/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:28:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 15:04:07 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

void	init_mapdata(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->map->m_height)
	{
		window->map->m_data[i][0] = '\0';
		i++;
	}
}

void	init_window_player(t_window *window)
{
	window->player->p_x = 0;
	window->player->p_y = 0;
	window->player->p_turndirection = 0;
	window->player->p_walkdirection = 0;
	window->player->p_walksidedir = 0;
	window->player->p_rotationangle = 0;
	window->player->p_turnspeed = PLAYER_TURNSPEED * (PI / 180);
	window->player->p_walkspeed = PLAYER_WALKSPEED;
	window->player->p_size = (float)PLAYER_SIZE / (float)TILE_SIZE / 4;
}

void	init_textures(t_window *window)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		window->texture[i]->t_path = NULL;
		window->texture[i]->t_height = 0;
		window->texture[i]->t_width = 0;
		window->texture[i]->t_bpp = 0;
		window->texture[i]->t_line_size = 0;
		window->texture[i]->t_endian = 0;
		window->texture[i]->t_img_ptr = NULL;
		window->texture[i]->t_img_data = NULL;
		i++;
	}
}

void	init_map(t_window *window)
{
	window->map->m_name = NULL;
	window->map->m_height = 0;
	window->map->m_width = 0;
	window->map->m_data = NULL;
	window->map->m_img = NULL;
	window->map->m_img_data = 0;
	window->map->m_bpp = 0;
	window->map->m_line_size = 0;
	window->map->m_endian = 0;
}

void	init_window(t_window *window)
{
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->w_width = 0;
	window->w_height = 0;
	window->w_color_ceiling = 0;
	window->w_color_floor = 0;
	window->m_size = TILE_SIZE * M_SCALE;
	window->key->k_backward = 0;
	window->key->k_forward = 0;
	window->key->k_left = 0;
	window->key->k_right = 0;
	init_window_player(window);
	init_map(window);
	init_textures(window);
}
