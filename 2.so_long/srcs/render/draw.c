/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:30:56 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:21:05 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	draw_floor(t_window **window, int y, int x)
{
	int		xx;
	int		yy;

	yy = 0;
	while (yy < T_SIZE)
	{
		xx = 0;
		while (xx < T_SIZE)
		{
			(*window)->img_data[(y * T_SIZE + yy) * (*window)->w_width
				+ (x * T_SIZE + xx)] =
				(*window)->texture[FNUM]->img_data[yy * T_SIZE + xx];
			xx++;
		}
		yy++;
	}
}

void	draw_wall(t_window **window, int y, int x)
{
	int		xx;
	int		yy;

	yy = 0;
	while (yy < T_SIZE)
	{
		xx = 0;
		while (xx < T_SIZE)
		{
			(*window)->img_data[(y * T_SIZE + yy) * (*window)->w_width
				+ (x * T_SIZE + xx)] =
				(*window)->texture[WNUM]->img_data[yy * T_SIZE + xx];
			xx++;
		}
		yy++;
	}
}

void	draw_player(t_window **window, int y, int x)
{
	int		xx;
	int		yy;
	int		temp;

	temp = (T_SIZE - P_SIZE) / 2;
	yy = 0;
	while (yy < P_SIZE)
	{
		xx = 0;
		while (xx < P_SIZE)
		{
			(*window)->img_data[(y * T_SIZE + yy + temp)
				* (*window)->w_width + (x * T_SIZE + xx + temp)] =
				(*window)->texture[PNUM]->img_data[yy * P_SIZE + xx];
			xx++;
		}
		yy++;
	}
}

void	draw_exit(t_window **window, int y, int x)
{
	int		xx;
	int		yy;
	int		temp;

	temp = (T_SIZE - P_SIZE) / 2;
	yy = 0;
	while (yy < P_SIZE)
	{
		xx = 0;
		while (xx < P_SIZE)
		{
			(*window)->img_data[(y * T_SIZE + yy + temp)
				* (*window)->w_width + (x * T_SIZE + xx + temp)] =
				(*window)->texture[ENUM]->img_data[yy * P_SIZE + xx];
			xx++;
		}
		yy++;
	}
}

void	draw_collectors(t_window **window, int y, int x)
{
	int		xx;
	int		yy;
	int		temp;

	temp = (T_SIZE - C_SIZE) / 2;
	yy = 0;
	while (yy < C_SIZE)
	{
		xx = 0;
		while (xx < C_SIZE)
		{
			(*window)->img_data[(y * T_SIZE + yy + temp)
				* (*window)->w_width + (x * T_SIZE + xx + temp)] =
				(*window)->texture[CNUM]->img_data[yy * C_SIZE + xx];
			xx++;
		}
		yy++;
	}
}
