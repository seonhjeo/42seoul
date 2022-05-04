/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:27:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 12:19:24 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sprite_square(t_window **window, int i, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	sprite_size;

	y = floor((*window)->sprites[i]->s_y * (*window)->m_size);
	x = floor((*window)->sprites[i]->s_x  * (*window)->m_size);
	sprite_size = SPRITE_SIZE * M_SCALE;
	dy = -(int)floor(sprite_size) / 2;
	while (dy <= sprite_size / 2)
	{
		dx = -sprite_size / 2;
		while (dx <= sprite_size / 2)
		{
			put_pixel(window, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_sprite(t_window **window)
{
	int	i;
	int	color;

	i = 0;
	while (i < (*window)->num_sprites)
	{
		if ((*window)->sprites[i]->s_visible)
			color = 0x00FF00;
		else
			color = 0x444444;
		draw_sprite_square(window, i, color);
		i++;
	}
}
