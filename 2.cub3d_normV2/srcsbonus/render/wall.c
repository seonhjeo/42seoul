/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:33:02 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 15:07:20 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

void	draw_ceiling(t_window **window, int x)
{
	int	y;

	y = (*window)->wc->wallbottomy;
	while (y < (*window)->w_height)
	{
		put_pixel(window, x, y, (*window)->w_color_ceiling);
		y++;
	}
}

void	draw_wall_proj_loop(t_window **window, int x)
{
	int	y;

	y = 0;
	y = (*window)->wc->walltopy;
	while (y < (*window)->wc->wallbottomy)
	{
		(*window)->wc->distfromtop = y + ((*window)->wc->wallheight / 2)
			- ((*window)->w_height / 2);
		(*window)->wc->texoffsety = (*window)->wc->distfromtop
			* ((float)(*window)->wc->texheight / (*window)->wc->wallheight);
		(*window)->wc->texcolor = (*window)->texture[(*window)->wc->texnum]
			->t_img_data[(*window)->wc->texwidth * (*window)->wc->texoffsety
			+ (*window)->wc->texoffsetx];
		put_pixel(window, x, y, (*window)->wc->texcolor);
		y++;
	}
}

void	draw_wall_proj(t_window **window, int x)
{
	(*window)->wc->texnum = (*window)->rays[x]->r_texture;
	(*window)->wc->texwidth =
		(*window)->texture[(*window)->wc->texnum]->t_width;
	(*window)->wc->texheight =
		(*window)->texture[(*window)->wc->texnum]->t_height;
	if ((*window)->rays[x]->r_washitvert)
		(*window)->wc->texoffsetx = (int)((*window)->rays[x]->r_wallhity
			* (*window)->wc->texwidth) % (*window)->wc->texwidth;
	else
		(*window)->wc->texoffsetx = (int)((*window)->rays[x]->r_wallhitx
			* (*window)->wc->texwidth) % (*window)->wc->texwidth;
	draw_wall_proj_loop(window, x);
}

void	draw_floor(t_window **window, int x)
{
	int	y;

	y = 0;
	while (y < (*window)->wc->walltopy)
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
		(*window)->wc->prepdis = (*window)->rays[x]->r_distance
			* cos((*window)->rays[x]->r_rayangle
			- (*window)->player->p_rotationangle);
		(*window)->wc->wallheight = (WALL_HEIGHT / (*window)->wc->prepdis)
			* (*window)->wc->distproj;
		(*window)->wc->walltopy = ((*window)->w_height / 2)
			- ((*window)->wc->wallheight / 2);
		if ((*window)->wc->walltopy < 0)
			(*window)->wc->walltopy = 0;
		(*window)->wc->wallbottomy = ((*window)->w_height / 2)
			+ ((*window)->wc->wallheight / 2);
		if ((*window)->wc->wallbottomy > (*window)->w_height)
			(*window)->wc->wallbottomy = (*window)->w_height;
		draw_ceiling(window, x);
		draw_wall_proj(window, x);
		draw_floor(window, x);
		x++;
	}
}
