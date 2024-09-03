/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:25:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 19:59:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAKER_H
# define MAP_MAKER_H

typedef struct	s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			remove;
	int			place;
	int			teleport;
	int			stopper;
}				t_keys;

typedef struct	s_img_info
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_img_info;

typedef struct	s_printer_vars
{
	int			left_gap;
	int			right_gap;
	int			up_gap;
	int			down_gap;
	int			nb_line;
	int			nb_row;
	int			offsetx;
	int			offsety;
	int			*x;
	int			*y;
	int			*table_mx;
	int			*table_my;
}				t_p_vars;


typedef struct	s_map_editor
{
	void		*mlx;
	void		*mlx_win;
	float		w_width;
	float		w_height;
	float		m_width;
	float		m_height;
	char		**map;
	char		*filename;
	int			fd;
	t_keys		keys;
	t_img_info	frame;
	t_p_vars	p_vars;
}				t_map_editor;

# include <stdio.h>

# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>

# include <mlx.h>
# include "libft.h"

// -----map_maker-----

// input_handler.c
int		cd_key_pressed(int keycode, t_map_editor *m_edit);
int		cd_key_released(int keycode, t_keys *keys);
int		cd_mouse_handler(int button, int x, int y, t_map_editor *m_edit);
int		cd_stop_maker(t_map_editor *m_edit);

// map_editor.c
int		cd_map_printer(t_map_editor *m_edit);


#endif