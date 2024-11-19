/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus_strucs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:45:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:48:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_STRUCS_H
# define CUB3D_BONUS_STRUCS_H

# include <cub3d_bonus.h>

typedef struct s_position
{
	float	x;
	float	y;
}		t_position;

typedef struct s_sprite_vars
{
	float	trsx;
	float	trsy;
	int		screenx;
	int		sp_height;
	int		sp_width;
	int		txty;
	int		txtx;
	int		y_op;
	float	x;
	float	y;
	float	stry;
	float	endy;
	float	strx;
	float	endx;
}			t_sprite_vars;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
	float	height;
	int		direction;
	int		tile;
	int		wall_type;
	int		**txt;
}			t_sprite;

typedef struct t_inventory
{
	int					tile;
	int					wall_type;
	struct t_inventory	*next;
}						t_inventory;

typedef struct s_textures
{
	int			**txts[94];
	int			**tmap;
	int			**fmap;
	int			**rmap;
	int			***pickaxe;
	float		pic_frame;
	char		*p[94];
	char		slots[94];
	t_sprite	**sprites;
	float		width;
	float		width_mod;
	float		height;
	float		up_op;
	int			tp_h;
	int			up;
	int			down;
	float		y_ratio;
	float		incr;
	float		dim;
}				t_textures;

typedef struct s_data_player
{
	float		x;
	float		y;
	float		view;
	float		height;
	float		pitch;
	float		speed;
	float		jump_coeff;
	float		jog_coeff;
	float		planex;
	float		planey;
	float		dirx;
	float		diry;
	t_inventory	*inventory;
}				t_data_player;

typedef struct s_map
{
	int			**map;
	char		*path;
	int			height;
	int			width;
	int			fd;
	float		fov;
}	t_map;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	up;
	int	down;
	int	left;
	int	right;
	int	space;
	int	shift;
	int	ctrl;
	int	fps;
	int	destroy;
	int	place;
	int	mouse;
}	t_keys;

typedef struct s_ray_info
{
	float	x;
	float	y;
	float	x_save;
	float	y_save;
	float	distance_save;
	float	t_x;
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
	int		*sprite_distances;
}			t_ray_info;

typedef struct s_t_info
{
	float				dx0;
	float				dy0;
	float				dx1;
	float				dy1;
	float				mx;
	float				my;
	float				stepx;
	float				stepy;
	float				row_dst;
	float				mid;
	float				height;
	float				width;
	float				pos_x;
	float				pos_y;
	int					x;
	int					y;
	int					**floor_t;
	int					**roof_t;
}						t_t_info;

typedef struct s_game
{
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*screen;
	mlx_image_t		*fps;
	mlx_image_t		*gui;
	t_ray_info		rays;
	t_t_info		t_info;
	t_keys			keys;
	t_data_player	player;
	t_textures		graphic;
}	t_game;

/*------------------- ENUM ----------------------*/

typedef enum e_ids
{
	NO,
	SO,
	WE,
	EA,
	C,
	F
}				t_ids;

#endif