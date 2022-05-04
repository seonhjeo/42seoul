/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:19:08 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/05/26 16:23:14 by seonhjeo         ###   ########.fr       */
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

// error & value definition
# define ERROR -1
# define SUCCESS 0
# define NUM_MAX 9999999

// size & constant definition
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
# define SPRITE_SIZE 16
# define M_SCALE 0.2
# define WALL_HEIGHT 1
# define TEXTURE_NUM 5
# define RAY_DRAW_TERM 100
# define VIEW_MARGIN 0

# define PLAYER_TURNSPEED 3
# define PLAYER_WALKSPEED 0.05

// keyboard definition
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

// direction-texture definition
# define NORTH_TEX 0
# define SOUTH_TEX 1
# define WEST_TEX 2
# define EAST_TEX 3
# define SPRITE_TEX 4

// structure for drawing lines
typedef struct s_xy{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_xy;

// structure for saving raycasting variables
typedef struct s_rc{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	bool	horzwallhit;
	float	horzwallhitX;
	float	horzwallhitY;
	int		horzwalltex;
	bool	vertwallhit;
	float	vertwallhitX;
	float	vertwallhitY;
	int		vertwalltex;
}	t_rc;

// structure for saving wall projection variables
typedef struct s_wc{
	float	distProj;
	float	prepDis;
	float	wallHeight;
	int		wallTopY;
	int		wallBottomY;
	int		distFromTop;
	int		texOffsetX;
	int		texOffsetY;
	int		texNum;
	int		texWidth;
	int		texHeight;
	int		texColor;
}	t_wc;

//structure for saving sprite projection variables
typedef struct s_sc{
	float	angleSpritePlayer;
	float	prepDis;
	float	spHeight;
	float	spWidth;
	float	spTopY;
	float	spBottomY;
	float	spAngle;
	float	spScreenPosX;
	float	spLeftX;
	float	spRightX;
	int		texWidth;
	int		texHeight;
	int		texelWidth;
	int		texOffsetX;
	int		distFromTop;
	int		texOffsetY;
	int		texelColor;
}	t_sc;

// structure of ray
typedef struct s_ray{
	float	r_rayAngle;
	float	r_wallHitX;
	float	r_wallHitY;
	float	r_distance;
	int		r_direction;
	int		r_texture;
	bool	r_wasHitVert;
}	t_ray;

// structure of player
typedef struct s_player{
	float	p_x;
	float	p_y;
	int		p_turnDirection;
	int		p_walkDirection;
	float	p_rotationAngle;
	float	p_walkSpeed;
	float	p_turnSpeed;
	float	p_size;
}	t_player;

// structure of map
typedef struct s_map{
	char	*m_name;
	int		m_width;
	int		m_height;
	char	**m_data;
	void	*m_img;
	int		*m_img_data;
	int		m_bpp;
	int		m_line_size;
	int		m_endian;
}	t_map;

// sturcture of keyboard buffer
typedef struct s_key{
	int		k_forward;
	int		k_backward;
	int		k_left;
	int		k_right;
}	t_key;

// structure of textures
typedef struct s_texture{
	char	*t_path;
	int		t_width;
	int		t_height;
	int		t_bpp;
	int		t_line_size;
	int		t_endian;
	void	*t_img_ptr;
	int		*t_img_data;
}	t_texture;

// structure of sprites
typedef struct s_sprite{
	float	s_x;
	float	s_y;
	float	s_dis;
	float	s_angle;
	bool	s_visible;
	int		s_texture;
}	t_sprite;

// structure of window
typedef struct s_window{
	void		*mlx_ptr;
	void		*win_ptr;
	int			w_save;
	int			w_width;
	int			w_height;
	int			w_color_floor;
	int			w_color_ceiling;
	float		m_size;
	float		fov_angle;
	float		dist_proj;
	int			num_sprites;
	int			num_vis_sp;
	t_xy		*xy;
	t_rc		*rc;
	t_wc		*wc;
	t_sc		*sc;
	t_map		*map;
	t_key		*key;
	t_player	*player;
	t_texture	**texture;
	t_sprite	**sprites;
	t_sprite	**visibleSp;
	t_ray		**rays;

}	t_window;

// mapparsing.c
int		calculating_mapsize(char *filename, t_window *window);
int		transfer_line_to_mapdata(char *line, t_window *window);
int		write_mapfile(char *filename, t_window *window);
int		saving_mapfile(char *filename, t_window *window);
int		check_input_and_save_file(int argc, char **argv, t_window *window);

// mapparsing2.c
int		check_around_value(t_window *window, int x, int y);
int		save_mapdata(char *line, t_window *window);
int		check_valid_mapdata(t_window *window);

// mapparsing_utils.c
void	free_splited_lines(char **str);
int		get_resolution(char *line, t_window *window);
int		get_texture_dir(char *line, t_window *window);
int		get_color(char *line, t_window *window);

// mapparscing_utils2.c
int		ft_inter_c(char c, char *needle);
int		ft_inter(char *str, char *needle);
void	calculate_mapsize_spritenum(t_window *window, char *line);
int		check_mapfile_name(char *argv);
void	get_sprites_pos(t_window *window);

// alloc.c
int		alloc_texture(t_window **window);
int		alloc_mapdata(t_window **window);
int		alloc_rays(t_window **window);
int		alloc_sprite(t_window **window);
int		alloc_visible_sprite(t_window **window);
int		alloc_window(t_window **window);

// init.c
void	init_mapdata(t_window *window);
void	init_window(t_window *window);

// free.c
void	free_texture(t_window **window);
void	free_mapdata(t_window **window);
void	free_rays(t_window **window);
void	free_sprite(t_window **window);
void	free_window(t_window **window);

// gnl.c
int		get_next_line(int fd, char **line);

// initmlx.c
int		init_mlx(t_window *window);

// renderscreen.c
void	render_image(t_window *window);
int		loop_manager(t_window **window);
int		load_textures(t_window **window);

// drawminimap.c
void	draw_minimap(t_window **window);

// drawline.c
void	put_pixel(t_window **window, int x, int y, int color);
void	draw_line(t_window **window, int color);
void	draw_horz_line(t_window **window, double x1, double x2, double y);
void	draw_vert_line(t_window **window, double x, double y1, double y2);

// player.c
void	move_player(t_window **window);
void	draw_player(t_window **window, int color);

// keypress.c
int		key_press(int keycode, t_window **window);
int		key_release(int keycode, t_window **window);

// ray.c
void	cast_all_rays(t_window **window);
void	draw_rays(t_window **window);

// ray2.c
void	horizontal_ray(t_window **window, float rayangle);
void	vertical_ray(t_window **window, float rayangle);

// ray3.c
void	calculate_ray(t_window **window, float rayangle, int col);

// rayutils.c
bool	isRayFacingDown(float angle);
bool	isRayFacingUp(float angle);
bool	isRayFacingRight(float angle);
bool	isRayFacingLeft(float angle);
int		get_ray_texture(float rayangle, bool hitvert);

// wall.c
void	render_walls(t_window **window);

// drawsprites.c
void	draw_sprite(t_window **window);

// sprite.c
void	render_sprites(t_window **window);

// sprite2.c
void	render_visible_sprites(t_window **window, int i);

// renderutils.c
void	normalize_angle(float *angle);
bool	is_inside_map(t_window **window, float x, float y);
int		has_wall_at(t_window **window, float x, float y);
float	dis_between_p(float x1, float y1, float x2, float y2);

#endif
