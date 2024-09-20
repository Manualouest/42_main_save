/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:27:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/17 14:43:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*------------------- INCLUDES ----------------------*/

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>
# include <MLX42/MLX42.h>
# include "libft.h"
# include "get_next_line_bonus.h"

/*------------------ STRUCTURES --------------------*/

typedef struct	s_textures
{
	int		**so;
	int		**no;
	int		**we;
	int		**ea;
	int		c;
	int 	f;
	char	**paths;
}		t_textures;

typedef struct s_position
{
	float	x;
	float	y;
	float	view;
	float	height;
	float	pitch;
}	t_position;

typedef struct s_map
{
	char		**map;
	char		**color;
	char		*path;
	int			fd;
	t_position	player;
}	t_map;

typedef struct s_ray_info
{
	float	x;
	float	y;
	float	t_x;
	float	angle;
	float	distance;
	float	wall_height;
	double	dx;
	double	dy;
	double	delta_dx;
	double	delta_dy;
	double	side_dx;
	double	side_dy;
	int		side;
	int		step_x;
	int		step_y;
}            t_ray_info;

typedef struct s_game
{
	t_map			map;
	mlx_t			*mlx;
	t_ray_info		rays;
	int				error;
	t_textures		graphic;
}	t_game;

/*------------------- ENUM ----------------------*/

typedef enum e_err
{
	CUB_ERR
}				t_err;

# define CUB_ERR "The map must be a .cub file darling"

/*----------------- FONCTIONS -------------------*/

// -----map_maker-----
// map_maker_main.c
char	*cd_map_maker(void);


void	error_handler(char *ERR_MSG);
t_game	cd_init_structs(void);

#endif