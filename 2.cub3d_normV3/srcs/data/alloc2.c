/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:09:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 12:19:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	alloc_visible_sprite(t_window **window)
{
	int		i;

	i = 0;
	(*window)->visibleSp
		= (t_sprite **)malloc(sizeof(t_sprite) * (*window)->num_sprites);
	if (!(*window)->visibleSp)
		return (ERROR);
	while (i < (*window)->num_sprites)
	{
		(*window)->visibleSp[i] = (t_sprite *)malloc(sizeof(t_sprite));
		if (!(*window)->visibleSp[i])
		{
			free_sprite(window);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
