/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderscreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:02:07 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:13:15 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includesbonus/cub3d.h"

int		load_textures(t_window **window)
{
	int		i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		(*window)->texture[i]->t_img_ptr = mlx_xpm_file_to_image(
			(*window)->mlx_ptr, (*window)->texture[i]->t_path,
			&(*window)->texture[i]->t_width,
			&(*window)->texture[i]->t_height);
		if ((*window)->texture[i]->t_img_ptr != NULL)
		{
			(*window)->texture[i]->t_img_data = (int *)mlx_get_data_addr(
				(*window)->texture[i]->t_img_ptr,
				&(*window)->texture[i]->t_bpp,
				&(*window)->texture[i]->t_line_size,
				&(*window)->texture[i]->t_endian);
		}
		else
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	init_values(t_window *window)
{
	window->wc->distproj = ((window->w_width / 2) / tan(window->fov_angle / 2));
}

int		loop_manager(t_window **window)
{
	move_player(window);
	cast_all_rays(window);
	render_walls(window);
	draw_minimap(window);
	draw_player(window, 0x000000);
	draw_rays(window);
	mlx_put_image_to_window(
		(*window)->mlx_ptr, (*window)->win_ptr, (*window)->map->m_img, 0, 0);
	return (0);
}

void	render_image(t_window *window)
{
	window->map->m_img = mlx_new_image(
			window->mlx_ptr, window->w_width, window->w_height);
	window->map->m_img_data = (int *)mlx_get_data_addr(
			window->map->m_img, &window->map->m_bpp,
			&window->map->m_line_size, &window->map->m_endian);
	init_values(window);
}
