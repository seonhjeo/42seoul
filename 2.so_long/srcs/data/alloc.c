/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:42:36 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 12:59:43 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int		alloc_mapdata(t_window **window)
{
	int		i;

	i = 0;
	(*window)->m_data =
		(char **)malloc(sizeof(char *) * (*window)->m_height);
	if (!((*window)->m_data))
		return (ERROR);
	while (i < (*window)->m_height)
	{
		(*window)->m_data[i] =
			(char *)malloc(sizeof(char) * ((*window)->m_width + 1));
		if (!((*window)->m_data[i]))
		{
			free_mapdata(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int		alloc_texture(t_window **window)
{
	int		i;

	i = 0;
	(*window)->texture =
		(t_texture **)malloc(sizeof(t_texture *) * TEXTURE_NUM);
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

int		alloc_window(t_window **window)
{
	(*window) = (t_window *)malloc(sizeof(t_window));
	if (!(*window))
	{
		ft_putstr("Error\nAllocating window failed\n");
		return (ERROR);
	}
	if (alloc_texture(window) == ERROR)
	{
		ft_putstr("Error\nAllocating texture failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}
