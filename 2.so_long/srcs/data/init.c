/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:28:38 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 10:09:57 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	init_mapdata(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->m_height)
	{
		window->m_data[i][0] = '\0';
		i++;
	}
}

void	init_texture_dir(t_window *window)
{
	window->texture[0]->path = ft_strdup(PLAYER_TEXDIR);
	window->texture[1]->path = ft_strdup(FLOOR_TEXDIR);
	window->texture[2]->path = ft_strdup(WALL_TEXDIR);
	window->texture[3]->path = ft_strdup(COL_TEXDIR);
	window->texture[4]->path = ft_strdup(EXIT_TEXDIR);
}

void	init_window(t_window *window)
{
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->img_ptr = NULL;
	window->img_data = 0;
	window->m_width = 0;
	window->m_height = 0;
	window->m_data = NULL;
	window->px = 0;
	window->py = 0;
	window->colnum = 0;
	window->movecount = 0;
	init_texture_dir(window);
}
