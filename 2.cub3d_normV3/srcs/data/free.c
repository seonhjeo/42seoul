/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:26 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 12:15:24 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_mapdata(t_window **window)
{
	int	i;

	i = 0;
	while (i < (*window)->map->m_height)
		free((*window)->map->m_data[i++]);
	free((*window)->map->m_data);
}

void	free_texture(t_window **window)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		free((*window)->texture[i]->t_path);
		free((*window)->texture[i++]);
	}
	free((*window)->texture);
}

void	free_rays(t_window **window)
{
	int	i;

	i = 0;
	while (i < (*window)->w_width)
		free((*window)->rays[i++]);
	free((*window)->rays);
}

void	free_sprite(t_window **window)
{
	int	i;

	i = 0;
	if ((*window)->sprites)
	{
		while (i < (*window)->num_sprites)
			free((*window)->sprites[i++]);
		free((*window)->sprites);
	}
	i = 0;
	if ((*window)->visibleSp)
	{
		while (i < (*window)->num_sprites)
			free((*window)->visibleSp[i++]);
		free((*window)->visibleSp);
	}
}

void	free_window(t_window **window)
{
	if ((*window)->rays)
		free_rays(window);
	if ((*window)->map->m_data)
		free_mapdata(window);
	if ((*window)->texture)
		free_texture(window);
	if ((*window)->sprites)
		free_sprite(window);
	free((*window)->xy);
	free((*window)->rc);
	free((*window)->wc);
	free((*window)->sc);
	free((*window)->map);
	free((*window)->key);
	free((*window)->player);
	free((*window));
}
