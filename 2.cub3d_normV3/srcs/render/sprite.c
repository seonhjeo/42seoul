/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:36:30 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 16:29:33 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	change_values_f(float *v1, float *v2)
{
	float	temp;

	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void	sort_visible_sprites(t_window **window, int numVisSp)
{
	int	i;
	int	j;

	i = 0;
	while (i < numVisSp - 1)
	{
		j = i + 1;
		while (j < numVisSp)
		{
			if ((*window)->visibleSp[i]->s_dis < (*window)->visibleSp[j]->s_dis)
			{
			change_values_f(&(*window)->visibleSp[i]->s_x, &(*window)->visibleSp[j]->s_x);
			change_values_f(&(*window)->visibleSp[i]->s_y, &(*window)->visibleSp[j]->s_y);
			change_values_f(&(*window)->visibleSp[i]->s_dis, &(*window)->visibleSp[j]->s_dis);
			change_values_f(&(*window)->visibleSp[i]->s_angle, &(*window)->visibleSp[j]->s_angle);
			}
			j++;
		}
		i++;
	}
}

void	add_visible_sprites(t_window **window, int *numVisSp, int i)
{
	(*window)->visibleSp[*numVisSp]->s_x = (*window)->sprites[i]->s_x;
	(*window)->visibleSp[*numVisSp]->s_y = (*window)->sprites[i]->s_y;
	(*window)->visibleSp[*numVisSp]->s_visible = true;
	(*window)->visibleSp[*numVisSp]->s_angle = (*window)->sprites[i]->s_angle;
	(*window)->visibleSp[*numVisSp]->s_dis = (*window)->sprites[i]->s_dis;
	(*window)->visibleSp[*numVisSp]->s_texture = SPRITE_TEX;
}

void	find_visible_sprites(t_window **window, int *numVisSp, int i)
{
	(*window)->sc->angleSpritePlayer = (*window)->player->p_rotationAngle
		- atan2(((*window)->sprites[i]->s_y - (*window)->player->p_y),
		((*window)->sprites[i]->s_x - (*window)->player->p_x));
	if ((*window)->sc->angleSpritePlayer > PI)
		(*window)->sc->angleSpritePlayer -= TWO_PI;
	if ((*window)->sc->angleSpritePlayer < -PI)
		(*window)->sc->angleSpritePlayer += TWO_PI;
	(*window)->sc->angleSpritePlayer = fabs((*window)->sc->angleSpritePlayer);
	if ((*window)->sc->angleSpritePlayer < ((*window)->fov_angle / 2) + VIEW_MARGIN)
	{
		(*window)->sprites[i]->s_visible = true;
		(*window)->sprites[i]->s_angle = (*window)->sc->angleSpritePlayer;
		(*window)->sprites[i]->s_dis = dis_between_p(
			(*window)->sprites[i]->s_x, (*window)->sprites[i]->s_y,
			(*window)->player->p_x, (*window)->player->p_y);
		(*window)->sprites[i]->s_texture = SPRITE_TEX;
		add_visible_sprites(window, numVisSp, i);
		*numVisSp += 1;
	}
	else
		(*window)->sprites[i]->s_visible = false;
}

void	render_sprites(t_window **window)
{
	int	i;
	int	numVisSp;

	i = 0;
	numVisSp = 0;
	while (i < (*window)->num_sprites)
		find_visible_sprites(window, &numVisSp, i++);
	sort_visible_sprites(window, numVisSp);
	printf("numVisSp : %d\n", numVisSp);
	if (numVisSp > 0)
	{
		i = 0;
		while (i < numVisSp)
			render_visible_sprites(window, i++);
	}
}
