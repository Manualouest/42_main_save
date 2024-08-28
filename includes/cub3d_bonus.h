/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:50:50 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:43:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

typedef struct s_pos
{
	float	x;
	float	y;
	float	orientation; // N = 0, E = 0.5*PI, S = PI, W = 1.5*PI
	float	pitch;
	float	height;
}			t_pos;

typedef struct s_img_info
{
	void	*img;
	int		height;
	int		width;
}			t_img_info;

typedef struct s_frame_info
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				height;
	int				width;
	unsigned int	**tab;
}			t_frame_info;

typedef struct s_mlx_info
{
	void			*mlx;
	void			*mlx_win;
	float			w_width;
	float			w_height;
	float			s_width;
	float			s_height;
	float			fov;
	t_frame_info	*main_frame;
	t_frame_info	*refresh_frame;
	t_frame_info	*north;
	t_frame_info	*south;
	t_frame_info	*west;
	t_frame_info	*east;
	int				floor;
	int				roof;
}					t_mlx_info;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	straf_left;
	int	straf_right;
	int	left;
	int	right;
	int	up;
	int	down;
	int	rise;
	int	lower;
	int	minimap;
	int	sprint;
}		t_keys;

typedef struct s_info
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
	int			m_height;
	int			m_width;
	char		**map;
	t_pos		*p_pos;
	t_mlx_info	*mlx_info;
	t_keys		*keys;
	int			current_display;
}				t_info;

typedef struct s_ray_info
{
	float	p_x;
	float	p_y;
	float	x;
	float	y;
	int		side;
	float	t_x;
	float	angle;
	float	distance;
	float	wall_height;
}			t_ray_info;

typedef struct s_minimap_info
{
	t_pos	p;
	t_pos	p1;
	t_pos	p2;
	t_pos	p3;
	int		m_height;
	int		m_width;
	int		gap;
}			t_mm_info;

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>

# include "libft.h"
# include "get_next_line_bonus.h"

# include <mlx.h>

//______src/struct_setup______
// struct_setup_main.c
int				cd_setup_info(t_info *info, char *filename);

// struct_setup_utils.c
char			*cd_re_malloc(char *src, char *new);
int				cd_tab_len(char **tab);
void			cd_free_tab_content(char **tab);
void			cd_dup_tab(char **dest, char **src);
char			**cd_tab_append(char **src, char *elem);

// mlx_setup.c
void			cd_change_pixel_color(t_frame_info *frame, int x, int y, int color);
void			cd_setup_mlx_main(t_info *info);

// clean_map.c
int				cd_check_map_holes(char **map, int width, int height);
int				cd_clean_map(t_info *info);

//____________________________

//______src/frees______
// free_struct.c
void			cd_free_tab(char **tab);
void			cd_free_info(t_info *info);

//_____________________

//______src/math_utils______
// color_utils.C
int				cd_get_hex(int t, int r, int g, int b);
float			cd_basic_f_clamp(float num, float min, float max);
float			cd_f_abs(float num);
float			cd_get_dist(float x1, float y1, float x2, float y2);
float			cd_round(float num, float round);
//__________________________

//______src/hooks______
// hook_setup.c
void			cd_hook_init(t_info *info);
int				cd_move_player(t_info *info);
int				key_tests(int keycode, t_info *info);

// handle_background.c
void			cd_switch_display(t_info *info, int target_display);
int				cd_update_frame(t_info *info);

// raycast.c
t_ray_info		cd_cast_ray(t_info *info, t_ray_info ray_info);
void			cd_raycast(t_info *info);

// minimap.c
int				cd_is_in_triangle(t_pos p, t_pos p1, t_pos p2, t_pos p3);
t_mm_info		cd_setup_minimap_struct(t_info *info);
void			cd_add_minimap(t_info *info);

// handle_mouse.c
unsigned int	cd_get_color(t_frame_info *frame, int x, int y);
int				cd_invert_color(unsigned int color);
void			cd_put_mouse(t_info *info);

// handle_mining.c
char			**cd_add_map_line(t_info *info, int pos);
void			cd_add_map_row(t_info *info, int pos);
void			cd_mine_block(t_info *info);
void			cd_place_block(t_info *info);
int				cd_mouse_hook(int button, int x, int y, t_info *info);

// minimap_editor.c
void			cd_edit_map(t_info *info, int mode);
void			cd_minimap_editor(t_info *info);

//_____________________

#endif