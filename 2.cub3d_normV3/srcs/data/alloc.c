/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:02:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 09:26:09 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	alloc_mapdata(t_window **window)
{
	int		height;
	int		width;
	int		i;

	height = (*window)->map->m_height;
	width = (*window)->map->m_width;
	i = 0;
	(*window)->map->m_data
		= (char **)malloc(sizeof(char *) * height);
	if (!((*window)->map->m_data))
		return (ERROR);
	while (i < height)
	{
		(*window)->map->m_data[i]
			= (char *)malloc(sizeof(char) * (width + 1));
		if (!((*window)->map->m_data[i]))
		{
			free_mapdata(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	alloc_rays(t_window **window)
{
	int		i;

	i = 0;
	(*window)->rays
		= (t_ray **)malloc(sizeof(t_ray *) * (*window)->w_width);
	if (!(*window)->rays)
		return (ERROR);
	while (i < (*window)->w_width)
	{
		(*window)->rays[i] = (t_ray *)malloc(sizeof(t_ray));
		if (!(*window)->rays[i])
		{
			free_rays(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	alloc_texture(t_window **window)
{
	int		i;

	i = 0;
	(*window)->texture
		= (t_texture **)malloc(sizeof(t_texture *) * TEXTURE_NUM);
	if (!(*window)->texture)
		return (ERROR);
	while (i < TEXTURE_NUM)
	{
		(*window)->texture[i] = (t_texture *)malloc(sizeof(t_texture));
		if (!(*window)->texture[i])
		{
			free_texture(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	alloc_sprite(t_window **window)
{
	int		i;

	i = 0;
	(*window)->sprites
		= (t_sprite **)malloc(sizeof(t_sprite) * (*window)->num_sprites);
	if (!(*window)->sprites)
		return (ERROR);
	while (i < (*window)->num_sprites)
	{
		(*window)->sprites[i] = (t_sprite *)malloc(sizeof(t_sprite));
		if (!(*window)->sprites[i])
		{
			free_sprite(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	alloc_window(t_window **window)
{
	int	res;

	(*window) = (t_window *)malloc(sizeof(t_window));
	if (!(*window))
		return (ERROR);
	(*window)->xy = (t_xy *)malloc(sizeof(t_xy));
	(*window)->rc = (t_rc *)malloc(sizeof(t_rc));
	(*window)->wc = (t_wc *)malloc(sizeof(t_wc));
	(*window)->sc = (t_sc *)malloc(sizeof(t_sc));
	(*window)->map = (t_map *)malloc(sizeof(t_map));
	(*window)->key = (t_key *)malloc(sizeof(t_key));
	(*window)->player = (t_player *)malloc(sizeof(t_player));
	res = alloc_texture(window);
	if (!(*window)->map || !(*window)->key || !(*window)->player
		|| !(*window)->xy || !(*window)->wc || !(*window)->sc
		|| res == ERROR)
	{
		free_window(window);
		return (ERROR);
	}
	return (SUCCESS);
}
