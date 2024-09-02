/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:25:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/02 17:54:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAKER_H
# define MAP_MAKER_H

typedef struct s_map_editor
{
	void	*mlx;
	void	*mlx_win;
	float	w_width;
	float	w_height;
	float	m_width;
	float	m_height;
	char	**map;
}			t_map_editor;

# include <cub3d.h>

// -----map_maker-----
// map_maker_main.c
char	*cd_map_maker(void);

#endif