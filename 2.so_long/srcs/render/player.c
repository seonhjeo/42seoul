/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:14:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:55:15 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int		do_exit(t_window **window)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
		mlx_destroy_image(
			(*window)->mlx_ptr, (*window)->texture[i++]->img_ptr);
	mlx_destroy_image((*window)->mlx_ptr, (*window)->img_ptr);
	free_window(window);
	exit(0);
	return (SUCCESS);
}

int		can_go_there(t_window **window, int x, int y)
{
	if (x < 0 || x >= (*window)->m_width)
		return (0);
	if (y < 0 || y >= (*window)->m_height)
		return (0);
	if ((*window)->m_data[y][x] == '1')
		return (0);
	return (1);
}

void	eat_and_exit(t_window **window, int x, int y)
{
	if ((*window)->m_data[y][x] == 'C')
	{
		(*window)->colnum--;
		(*window)->m_data[y][x] = '0';
	}
	if ((*window)->m_data[y][x] == 'E' && (*window)->colnum == 0)
	{
		ft_putstr("You Clear the Map!\n");
		do_exit(window);
	}
}

void	move_player(t_window **window, int x, int y)
{
	int		newx;
	int		newy;

	newx = (*window)->px + x;
	newy = (*window)->py + y;
	if (can_go_there(window, newx, newy))
	{
		(*window)->px = newx;
		(*window)->py = newy;
		(*window)->movecount++;
		ft_printf("y : %d, x : %d, movecount = %d, colnumber : %d\n",
			newy, newx, (*window)->movecount, (*window)->colnum);
	}
	eat_and_exit(window, newx, newy);
}

int		key_press(int keycode, t_window **window)
{
	if (keycode == KEY_W)
		move_player(window, 0, -1);
	if (keycode == KEY_S)
		move_player(window, 0, +1);
	if (keycode == KEY_D)
		move_player(window, +1, 0);
	if (keycode == KEY_A)
		move_player(window, -1, 0);
	if (keycode == KEY_ESC)
		do_exit(window);
	return (0);
}
