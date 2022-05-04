/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:03:52 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:15:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	put_pixel(t_window **window, int x, int y, int color)
{
	(*window)->img_data[y * (*window)->w_width + x] = color;
}

int		load_textures(t_window **window)
{
	int		i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		(*window)->texture[i]->img_ptr = mlx_xpm_file_to_image(
			(*window)->mlx_ptr, (*window)->texture[i]->path,
			&(*window)->texture[i]->width,
			&(*window)->texture[i]->height);
		if ((*window)->texture[i]->img_ptr != NULL)
		{
			(*window)->texture[i]->img_data = (int *)mlx_get_data_addr(
				(*window)->texture[i]->img_ptr,
				&(*window)->texture[i]->bpp,
				&(*window)->texture[i]->line_size,
				&(*window)->texture[i]->endian);
		}
		else
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	render_image(t_window *window)
{
	window->img_ptr = mlx_new_image(
			window->mlx_ptr, window->w_width, window->w_height);
	window->img_data = (int *)mlx_get_data_addr(
			window->img_ptr, &window->bpp,
			&window->line_size, &window->endian);
}
