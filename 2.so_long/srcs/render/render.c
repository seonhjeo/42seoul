/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:22:13 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:38:32 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	init_mlx_values(t_window *window)
{
	window->w_height = window->m_height * T_SIZE;
	window->w_width = window->m_width * T_SIZE;
}

void	draw_map(t_window **window, int y, int x)
{
	if (ft_inter_c((*window)->m_data[y][x], "0PCE"))
		draw_floor(window, y, x);
	if ((*window)->m_data[y][x] == '1')
		draw_wall(window, y, x);
	if ((*window)->m_data[y][x] == 'C')
		draw_collectors(window, y, x);
	if ((*window)->m_data[y][x] == 'E')
		draw_exit(window, y, x);
}

int		loop_manager(t_window **window)
{
	int		y;
	int		x;

	y = 0;
	while (y < (*window)->m_height)
	{
		x = 0;
		while (x < (*window)->m_width)
		{
			draw_map(window, y, x);
			x++;
		}
		y++;
	}
	draw_player(window, (*window)->py, (*window)->px);
	mlx_put_image_to_window(
		(*window)->mlx_ptr, (*window)->win_ptr, (*window)->img_ptr, 0, 0);
	return (0);
}

int		init_mlx(t_window *window)
{
	init_mlx_values(window);
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(
			window->mlx_ptr, window->w_width, window->w_height, "so_long");
	if (window->win_ptr == NULL || window->mlx_ptr == NULL)
	{
		ft_putstr("Error\nMaking window failed\n");
		free_window(&window);
		return (ERROR);
	}
	return (SUCCESS);
}
