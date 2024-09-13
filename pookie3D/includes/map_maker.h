/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:25:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/13 20:51:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAKER_H
# define MAP_MAKER_H

# include <stdio.h>

# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>

# include <MLX42/MLX42.h>
# include "libft.h"

typedef struct	s_img_info
{
	mlx_image_t	*img;
}				t_img_info;

typedef struct	s_printer_vars
{
	int			left_gap;
	int			right_gap;
	int			up_gap;
	int			down_gap;
	int			nb_line;
	int			nb_col;
	int			offsetx;
	int			offsety;
	int			x;
	int			y;
	int			*table_mx;
	int			*table_my;
}				t_p_vars;

typedef struct	s_map_info
{
	int			step;
	int			try_step;
	int			revert;
	t_img_info	screen;
	mlx_image_t	**text;
	char		*map_name;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*input;
	char		player_dir;
	int			ceiling;
	int			floor;
}				t_map_info;

typedef struct	s_map_editor
{
	mlx_t		*mlx;
	float		w_width;
	float		w_height;
	float		m_width;
	float		m_height;
	int			origin_x;
	int			origin_y;
	char		**map;
	char		*filename;
	int			fd;
	t_img_info	frame;
	mlx_image_t	*fps;
	t_p_vars	p_vars;
	t_map_info	m_info;
}				t_map_editor;

// -----map_maker-----

// vars_setup.c
char		**setup_clear_map(int height, int width, int px, int py);
t_img_info	cd_setup_frame(t_map_editor m_edit, int width, int height);
t_p_vars	cd_setup_p_vars(t_map_editor m_edit);
t_map_info	cd_setup_m_info(t_map_editor m_edit);

// input_handler.c
void		cd_key_handler(mlx_key_data_t keydata, void *m_edit);
void		cd_mouse_handler(mouse_key_t button, action_t action,
				modifier_key_t mods, void *m_edit);
void		cd_input_handler(mlx_key_data_t keydata, void *vm_edit);

// map_editor.c
mlx_image_t	*cd_slow_down(t_map_editor *m_edit, struct timeval start_time,
				int target_fp, int do_return);
void		cd_map_printer(void *vm_edit);

// map_setup.c
void		cd_start_map_setup(t_map_editor *m_edit);

// setup_screens.c
void		cd_add_text(t_map_editor *m_edit, char *text, int x, int y);
void		cd_resizer(mlx_image_t *img, int width, int height);
void		cd_setup_screen_1(t_map_editor *m_edit);
void		cd_setup_screen_2(t_map_editor *m_edit, char *type);

// utils.c
char		*cd_append_char(char *src, char c);
int			cd_tab_len(mlx_image_t	**tab);
void		*cd_free_tab(mlx_image_t	**tab, t_map_editor *m_edit, int full_free);
mlx_image_t	**cd_append_img(mlx_image_t	**tab, mlx_image_t	*elem);
char		*cd_realloc(char *src, char *new, int need_dup);

#endif