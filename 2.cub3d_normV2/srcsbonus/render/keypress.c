/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:38:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 15:04:45 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

int		do_exit(t_window **window)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
		mlx_destroy_image(
			(*window)->mlx_ptr, (*window)->texture[i++]->t_img_ptr);
	mlx_destroy_image((*window)->mlx_ptr, (*window)->map->m_img);
	free_window(window);
	exit(0);
	return (SUCCESS);
}

int		key_release(int keycode, t_window **window)
{
	if (keycode == KEY_W)
		(*window)->player->p_walkdirection = 0;
	if (keycode == KEY_S)
		(*window)->player->p_walkdirection = 0;
	if (keycode == KEY_D)
		(*window)->player->p_walksidedir = 0;
	if (keycode == KEY_A)
		(*window)->player->p_walksidedir = 0;
	if (keycode == KEY_LEFT)
		(*window)->player->p_turndirection = 0;
	if (keycode == KEY_RIGHT)
		(*window)->player->p_turndirection = 0;
	return (0);
}

int		key_press(int keycode, t_window **window)
{
	if (keycode == KEY_W)
		(*window)->player->p_walkdirection = +1;
	if (keycode == KEY_S)
		(*window)->player->p_walkdirection = -1;
	if (keycode == KEY_D)
		(*window)->player->p_walksidedir = +1;
	if (keycode == KEY_A)
		(*window)->player->p_walksidedir = -1;
	if (keycode == KEY_RIGHT)
		(*window)->player->p_turndirection = +1;
	if (keycode == KEY_LEFT)
		(*window)->player->p_turndirection = -1;
	if (keycode == KEY_ESC)
	{
		do_exit(window);
	}
	return (0);
}
