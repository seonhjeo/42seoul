/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:26 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/28 12:56:30 by seonhjeo         ###   ########.fr       */
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

void	free_window(t_window **window)
{
	if ((*window)->rays)
		free_rays(window);
	if ((*window)->map->m_data)
		free_mapdata(window);
	if ((*window)->texture)
		free_texture(window);
	free((*window)->xy);
	free((*window)->rc);
	free((*window)->wc);
	free((*window)->map);
	free((*window)->key);
	free((*window)->player);
	free((*window));
}
