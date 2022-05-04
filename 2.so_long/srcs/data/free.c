/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:57:45 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/14 14:41:57 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	free_mapdata(t_window **window)
{
	int		i;

	i = 0;
	while (i < (*window)->m_height)
		free((*window)->m_data[i++]);
	free((*window)->m_data);
}

void	free_texture(t_window **window)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		free((*window)->texture[i]->path);
		free((*window)->texture[i++]);
	}
	free((*window)->texture);
}

void	free_window(t_window **window)
{
	if ((*window)->m_data)
		free_mapdata(window);
	if ((*window)->texture)
		free_texture(window);
	free(*window);
}
