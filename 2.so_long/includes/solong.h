/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:38 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:54:20 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../printf/includes/ft_printf.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define ERROR -1
# define SUCCESS 0

# define TEXTURE_NUM 5
# define PNUM 0
# define FNUM 1
# define WNUM 2
# define CNUM 3
# define ENUM 4
# define PLAYER_TEXDIR "textures/player.xpm"
# define FLOOR_TEXDIR "textures/floor.xpm"
# define WALL_TEXDIR "textures/wall.xpm"
# define COL_TEXDIR "textures/collectors.xpm"
# define EXIT_TEXDIR "textures/exit.xpm"

# define T_SIZE 64
# define C_SIZE 32
# define P_SIZE 48

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

typedef struct	s_texture{
	char		*path;
	int			width;
	int			height;
	int			bpp;
	int			line_size;
	int			endian;
	void		*img_ptr;
	int			*img_data;
}				t_texture;

typedef struct	s_window{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	int			w_width;
	int			w_height;
	int			m_width;
	int			m_height;
	char		**m_data;
	int			px;
	int			py;
	int			colnum;
	int			movecount;
	t_texture	**texture;
}				t_window;

int		alloc_texture(t_window **window);
int		alloc_window(t_window **window);
int		alloc_mapdata(t_window **window);

void	init_window(t_window *window);
void	init_mapdata(t_window *window);

void	free_texture(t_window **window);
void	free_window(t_window **window);
void	free_mapdata(t_window **window);

int		get_next_line(int fd, char **line);

int		check_and_save_file(t_window **window, char *map);

int		check_wall(t_window **window);
int		check_valid_map(t_window **window);
int		find_player_pos(t_window **window);
int		write_mapfile(t_window **window, char *filename);

int		ft_inter_c(char c, char *needle);
int		ft_inter(char *str, char *needle);
int		find_col(t_window **window);

int		load_textures(t_window **window);
int		loop_manager(t_window **window);
void	render_image(t_window *window);
int		init_mlx(t_window *window);

int		do_exit(t_window **window);
int		key_press(int keycode, t_window **window);

void	draw_floor(t_window **window, int y, int x);
void	draw_wall(t_window **window, int y, int x);
void	draw_player(t_window **window, int y, int x);
void	draw_exit(t_window **window, int y, int x);
void	draw_collectors(t_window **window, int y, int x);

#endif
