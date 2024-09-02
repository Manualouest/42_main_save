/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:25:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 00:16:15 by mbirou           ###   ########.fr       */
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

typedef struct	s_map_editor
{
	void		*mlx;
	void		*mlx_win;
	float		w_width;
	float		w_height;
	float		m_width;
	float		m_height;
	char		**map;
	t_keys		*keys;
	t_img_info	*frame;
}				t_map_editor;

# include <fcntl.h>
# include <math.h>

# include <mlx.h>
# include "libft.h"

// -----map_maker-----
// map_maker_main.c
char	*cd_map_maker(void);


#endif