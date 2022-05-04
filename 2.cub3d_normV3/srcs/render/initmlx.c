/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:02:26 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/11 13:00:25 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx_values(t_window *window)
{
	window->fov_angle = VIEW_ANGLE * (PI / 180);
	window->dist_proj = (window->w_width / 2) / tan(window->fov_angle / 2);
}

int	init_mlx(t_window *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(
			window->mlx_ptr, window->w_width, window->w_height, "cub3D");
	if (window->win_ptr == NULL || window->mlx_ptr == NULL)
	{
		free_window(&window);
		return (ERROR);
	}
	if (alloc_rays(&window) == ERROR)
		return (ERROR);
	init_mlx_values(window);
	return (SUCCESS);
}
