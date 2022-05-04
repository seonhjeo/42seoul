/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:57:08 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 16:31:59 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	project_visible_sprites(t_window **window, t_sprite *sprite)
{
	int	x;
	int	y;

	x = (*window)->sc->spLeftX;
	while (x < (*window)->sc->spRightX)
	{
		(*window)->sc->texelWidth = (*window)->sc->texWidth / (*window)->sc->spWidth;
		(*window)->sc->texOffsetX = (x - (*window)->sc->spLeftX) * (*window)->sc->texelWidth;
		y = (*window)->sc->spTopY;
		while (y < (*window)->sc->spBottomY)
		{
			(*window)->sc->distFromTop = y + ((*window)->sc->spHeight / 2) - ((*window)->w_height/ 2);
			(*window)->sc->texOffsetY = (*window)->sc->distFromTop * ((*window)->sc->texHeight / (*window)->sc->spHeight);
			(*window)->sc->texelColor = (*window)->texture[sprite->s_texture]->t_img_data[
				(*window)->sc->texOffsetY * (*window)->sc->texWidth + (*window)->sc->texOffsetX];
			//if (sprite->s_dis < (*window)->rays[x]->r_distance)
				//put_pixel(window, x, y, (*window)->sc->texelColor);
			y++;
		}
		x++;
	}
}

void	render_visible_sprites(t_window **window, int i)
{
	t_sprite *sprite;

	sprite = (*window)->visibleSp[i];
	(*window)->sc->prepDis = sprite->s_dis * cos(sprite->s_angle);
	(*window)->sc->spHeight = (WALL_HEIGHT / (*window)->sc->prepDis) * (*window)->dist_proj;
	(*window)->sc->spWidth = (*window)->sc->spHeight;
	(*window)->sc->spTopY = ((*window)->w_height / 2) - ((*window)->sc->spHeight / 2);
	if ((*window)->sc->spTopY < 0)
		(*window)->sc->spTopY = 0;
	(*window)->sc->spBottomY = ((*window)->w_height / 2) + ((*window)->sc->spHeight / 2);
	if ((*window)->sc->spBottomY > (*window)->w_height)
		(*window)->sc->spBottomY = (*window)->w_height;
	(*window)->sc->spAngle = atan2(sprite->s_y - (*window)->player->p_y,
		sprite->s_x - (*window)->player->p_x) - (*window)->player->p_rotationAngle;
	(*window)->sc->spScreenPosX = tan((*window)->sc->spAngle) * (*window)->dist_proj;
	(*window)->sc->spLeftX = ((*window)->w_width / 2)
		+ (*window)->sc->spScreenPosX - ((*window)->sc->spWidth / 2);
	(*window)->sc->spRightX = (*window)->sc->spLeftX + (*window)->sc->spWidth;
	(*window)->sc->texWidth = (*window)->texture[sprite->s_texture]->t_width;
	(*window)->sc->texHeight = (*window)->texture[sprite->s_texture]->t_height;

	printf("sp_x :  %f, sp_y : %f, sp_angle : %f, sp_dis: %f, sp_tex : %d\n"
		, sprite->s_x, sprite->s_y, sprite->s_angle, sprite->s_dis, sprite->s_texture);
	printf("sc_prepdis : %f, sc_spHeight : %f, sc_spWidth : %f, sc_spTopY : %f, sc->spBottomY : %f\n sc_angle : %f, sc_spScPosX : %f, sc_spLeftX : %f, sc_spRightX : %f, sc_texWidth : %d, sc_texHeight : %d\n",
		(*window)->sc->prepDis, (*window)->sc->spHeight, (*window)->sc->spWidth, (*window)->sc->spTopY, (*window)->sc->spBottomY,
		(*window)->sc->spAngle, (*window)->sc->spScreenPosX, (*window)->sc->spLeftX, (*window)->sc->spRightX, (*window)->sc->texWidth, (*window)->sc->texHeight);

	//project_visible_sprites(window, sprite);
}
