/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:34:42 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:53:49 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int		check_input_dir(int argc, char **argv)
{
	char	*s;
	int		i;

	if (argc != 2)
	{
		ft_putstr("Error\nwrong input number\n");
		return (ERROR);
	}
	s = argv[1];
	i = ft_strlen(s);
	if (i < 4 || s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
	{
		ft_putstr("Error\nwrong file name\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_window	*window;

	if (check_input_dir(argc, argv) == ERROR)
		return (ERROR);
	if (alloc_window(&window) == ERROR)
		return (ERROR);
	init_window(window);
	if (check_and_save_file(&window, argv[1]) == ERROR)
		return (ERROR);
	if (init_mlx(window) == ERROR)
		return (ERROR);
	render_image(window);
	if (load_textures(&window) == ERROR)
		return (ERROR);
	mlx_hook(window->win_ptr, 2, 0, key_press, &window);
	mlx_hook(window->win_ptr, 17, 0, do_exit, &window);
	mlx_loop_hook(window->mlx_ptr, loop_manager, &window);
	mlx_loop(window->mlx_ptr);
	return (SUCCESS);
}
