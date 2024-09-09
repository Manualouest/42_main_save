/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:25:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/09 16:12:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAKER_H
# define MAP_MAKER_H

# include <stdio.h>

# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>

# include <MLX42/MLX42.h>
# include <libft.h>

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
	mlx_image_t	*img;
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
	mlx_t		*mlx;
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

// -----map_maker-----

// vars_setup.c
char		**setup_clear_map(void);
t_keys		cd_setup_keys(void);
t_img_info	cd_setup_frame(t_map_editor m_edit);
t_p_vars	cd_setup_p_vars(t_map_editor m_edit);

// input_handler.c
void		cd_key_handler(mlx_key_data_t keydata, void *m_edit);
void		cd_key_released(mlx_key_data_t keydata, void *keys);
void		cd_mouse_handler(mouse_key_t button, action_t action, modifier_key_t mods, void *m_edit);
void		cd_stop_maker(void *m_edit);

// map_editor.c
void		cd_map_printer(void *m_edit);


#endif