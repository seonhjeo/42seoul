/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:59:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 14:59:57 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_window	*window;

	window = NULL;
	if (alloc_window(&window) == ERROR)
		return (ERROR);
	init_window(window);
	if (check_input_and_save_file(argc, argv, window) == ERROR)
		return (ERROR);
	if (init_mlx(window) == ERROR)
		return (ERROR);
	render_image(window);
	if (load_textures(&window) == ERROR)
		return (ERROR);
	mlx_hook(window->win_ptr, 2, 0, key_press, &window);
	mlx_hook(window->win_ptr, 3, 0, key_release, &window);
	mlx_hook(window->win_ptr, 17, 0, do_exit, &window);
	mlx_loop_hook(window->mlx_ptr, loop_manager, &window);
	mlx_loop(window->mlx_ptr);
	return (SUCCESS);
}
