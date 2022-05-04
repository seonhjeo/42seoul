/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:19:08 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 15:00:59 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define ERROR -1
# define SUCCESS 0
# define NUM_MAX 9999999

# define PI 3.14159265
# define TWO_PI 6.28318530
# define VIEW_ANGLE 60

# define DEFAULT_WIDTH 1280
# define DEFAULT_HEIGHT 800
# define MIN_WIDTH 600
# define MIN_HEIGHT 400
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

# define TILE_SIZE 32
# define PLAYER_SIZE 8
# define M_SCALE 0.2
# define WALL_HEIGHT 1
# define TEXTURE_NUM 5
# define RAY_DRAW_TERM 100
# define VIEW_MARGIN 0

# define PLAYER_TURNSPEED 3
# define PLAYER_WALKSPEED 0.03

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define NORTH_TEX 0
# define SOUTH_TEX 1
# define WEST_TEX 2
# define EAST_TEX 3

typedef struct	s_xy{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
}				t_xy;

typedef struct	s_rc{
	float		xintercept;
	float		yintercept;
	float		xstep;
	float		ystep;
	bool		horzwallhit;
	float		horzwallhitx;
	float		horzwallhity;
	int			horzwalltex;
	bool		vertwallhit;
	float		vertwallhitx;
	float		vertwallhity;
	int			vertwalltex;
}				t_rc;

typedef struct	s_wc{
	float		distproj;
	float		prepdis;
	float		wallheight;
	int			walltopy;
	int			wallbottomy;
	int			distfromtop;
	int			texoffsetx;
	int			texoffsety;
	int			texnum;
	int			texwidth;
	int			texheight;
	int			texcolor;
}				t_wc;

typedef struct	s_ray{
	float		r_rayangle;
	float		r_wallhitx;
	float		r_wallhity;
	float		r_distance;
	int			r_direction;
	int			r_texture;
	bool		r_washitvert;
}				t_ray;

typedef struct	s_player{
	float		p_x;
	float		p_y;
	int			p_turndirection;
	int			p_walkdirection;
	int			p_walksidedir;
	float		p_rotationangle;
	float		p_walkspeed;
	float		p_turnspeed;
	float		p_size;
}				t_player;

typedef struct	s_map{
	char		*m_name;
	int			m_width;
	int			m_height;
	char		**m_data;
	void		*m_img;
	int			*m_img_data;
	int			m_bpp;
	int			m_line_size;
	int			m_endian;
}				t_map;

typedef struct	s_key{
	int			k_forward;
	int			k_backward;
	int			k_left;
	int			k_right;
}				t_key;

typedef struct	s_texture{
	char		*t_path;
	int			t_width;
	int			t_height;
	int			t_bpp;
	int			t_line_size;
	int			t_endian;
	void		*t_img_ptr;
	int			*t_img_data;
}				t_texture;

typedef struct	s_window{
	void		*mlx_ptr;
	void		*win_ptr;
	int			w_width;
	int			w_height;
	int			w_color_floor;
	int			w_color_ceiling;
	float		m_size;
	float		fov_angle;
	float		dist_proj;
	t_xy		*xy;
	t_rc		*rc;
	t_wc		*wc;
	t_map		*map;
	t_key		*key;
	t_player	*player;
	t_texture	**texture;
	t_ray		**rays;

}				t_window;

int				calculating_mapsize(char *filename, t_window *window);
int				transfer_line_to_mapdata(char *line, t_window *window);
int				write_mapfile(char *filename, t_window *window);
int				saving_mapfile(char *filename, t_window *window);
int				check_input_and_save_file(
					int argc, char **argv, t_window *window);

int				check_around_value(t_window *window, int x, int y);
int				save_mapdata(char *line, t_window *window);
int				check_valid_mapdata(t_window *window);

void			free_splited_lines(char **str);
int				get_resolution(char *line, t_window *window);
int				get_texture_dir(char *line, t_window *window);
int				get_color(char *line, t_window *window);

int				ft_inter_c(char c, char *needle);
int				ft_inter(char *str, char *needle);
void			calculate_mapsize(t_window *window, char *line);
int				check_mapfile_name(char *argv);
int				is_mapdata(char *line);

int				alloc_texture(t_window **window);
int				alloc_mapdata(t_window **window);
int				alloc_rays(t_window **window);
int				alloc_window(t_window **window);

void			init_mapdata(t_window *window);
void			init_window(t_window *window);

void			free_texture(t_window **window);
void			free_mapdata(t_window **window);
void			free_rays(t_window **window);
void			free_window(t_window **window);

int				get_next_line(int fd, char **line);

int				init_mlx(t_window *window);

void			render_image(t_window *window);
int				loop_manager(t_window **window);
int				load_textures(t_window **window);

void			draw_minimap(t_window **window);

void			put_pixel(t_window **window, int x, int y, int color);
void			draw_line(t_window **window, int color);
void			draw_horz_line(
					t_window **window, double x1, double x2, double y);
void			draw_vert_line(
					t_window **window, double x, double y1, double y2);

void			move_player(t_window **window);
void			draw_player(t_window **window, int color);

int				key_press(int keycode, t_window **window);
int				key_release(int keycode, t_window **window);

void			cast_all_rays(t_window **window);
void			draw_rays(t_window **window);

void			horizontal_ray(t_window **window, float rayangle);
void			vertical_ray(t_window **window, float rayangle);

void			calculate_ray(t_window **window, float rayangle, int col);

bool			israyfacingdown(float angle);
bool			israyfacingup(float angle);
bool			israyfacingright(float angle);
bool			israyfacingleft(float angle);
int				get_ray_texture(float rayangle, bool hitvert);

void			render_walls(t_window **window);

void			normalize_angle(float *angle);
bool			is_inside_map(t_window **window, float x, float y);
int				has_wall_at(t_window **window, float x, float y);
float			dis_between_p(float x1, float y1, float x2, float y2);

#endif
