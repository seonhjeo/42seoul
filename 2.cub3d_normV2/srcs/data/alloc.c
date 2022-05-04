/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:02:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/28 13:53:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	alloc_mapdata(t_window **window)
{
	int		i;

	i = 0;
	(*window)->map->m_data =
		(char **)malloc(sizeof(char *) * (*window)->map->m_height);
	if (!((*window)->map->m_data))
	{
		printf("Error\nFailed allocating mapdata\n");
		return (ERROR);
	}
	while (i < (*window)->map->m_height)
	{
		(*window)->map->m_data[i] =
			(char *)malloc(sizeof(char) * ((*window)->map->m_width + 1));
		if (!((*window)->map->m_data[i]))
		{
			printf("Error\nFailed allocating mapdata[%d]\n", i);
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
	(*window)->rays =
		(t_ray **)malloc(sizeof(t_ray *) * (*window)->w_width);
	if (!(*window)->rays)
	{
		printf("Error\nFailed allocating rays\n");
		return (ERROR);
	}
	while (i < (*window)->w_width)
	{
		(*window)->rays[i] = (t_ray *)malloc(sizeof(t_ray));
		if (!(*window)->rays[i])
		{
			printf("Error\nFailed allocating ray[%d]\n", i);
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
	(*window)->texture =
		(t_texture **)malloc(sizeof(t_texture *) * TEXTURE_NUM);
	if (!(*window)->texture)
	{
		printf("Error\nFailed allocating textures\n");
		return (ERROR);
	}
	while (i < TEXTURE_NUM)
	{
		(*window)->texture[i] = (t_texture *)malloc(sizeof(t_texture));
		if (!(*window)->texture[i])
		{
			printf("Error\nFailed allocating texture[%d]\n", i);
			free_texture(window);
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
	(*window)->map = (t_map *)malloc(sizeof(t_map));
	(*window)->key = (t_key *)malloc(sizeof(t_key));
	(*window)->player = (t_player *)malloc(sizeof(t_player));
	res = alloc_texture(window);
	if (!(*window)->map || !(*window)->key || !(*window)->player
		|| !(*window)->xy || !(*window)->wc || res == ERROR)
	{
		printf("Error\nFailed allocating window struct\n");
		free_window(window);
		return (ERROR);
	}
	return (SUCCESS);
}
