/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proced.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:09:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 21:24:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCED_H
# define PROCED_H

# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <MLX42/MLX42.h>
# include <libft.h>

typedef	struct s_leg
{
	struct s_sphere	*anchor;
	float			side;
	struct s_sphere	*elbow;
	float			e_x;
	float			e_y;
	struct s_sphere	*hand;
	float			h_x;
	float			h_y;
}					t_leg;

typedef	struct s_sphere
{
	float	x;
	float	y;
	float	o;//orientation in rad
	int		r;//radius
	int		link_len;
	int		color;
	float	max_angle;
	t_leg	*r_leg;
	t_leg	*l_leg;
}			t_sphere;

typedef	struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	int			w_width;
	int			w_height;
	mlx_image_t	*fps;
}				t_mlx;

typedef	struct s_vars
{
	float	*cos;
	float	*sin;
	int		m_x;
	int		m_y;
	int		tracking;
	int		r_x;
	int		r_y;
}		t_vars;

typedef	struct s_data
{
	int			nb_sphere;
	int			*sizes;
	int			*link_lenghts;
	float		*max_angles;
	int			*leg_spots;
	t_sphere	**spheres;
	t_vars		vars;
	t_mlx		mlx;
}				t_data;

typedef	struct s_coord
{
	float	x;
	float	y;
}			t_coord;

//-----------------------------------------------------------------------------
//-----utils-----
// tab_utils.c
int			pr_tab_len(char **tab);
int			*pr_strtoi(char *str, t_data *data);
float		*pr_strtor(char *str, t_data *data);
int			*pr_extend_itab(int *tab);
float		*pr_extend_ftab(float *tab);

// math_utils.c
float		pr_f_clamp(float num, float min, float max);

//-----------------------------------------------------------------------------
//-----inits-----
// struct_inits.c
t_sphere	*pr_create_sphere(t_data *data, int id);
void		pr_init_data(int argc, char **argv, t_data *data);

//-----------------------------------------------------------------------------
//-----display-----
// display_main.c
void		pr_render(t_data *data);
void		pr_display_main(t_data *data);

// handle_body.c
void		pr_draw_circle(mlx_image_t *screen, t_data *data, t_sphere *sphere, int id);
void		pr_move_body(t_data *data, t_sphere **spheres);

// handle_legs.c
void		pr_draw_legs(mlx_image_t *screen, t_data *data, t_leg *leg);

// hooks.c
void	pr_constrain_angle(t_sphere *origin, t_sphere *anchor);
void		pr_close(mlx_key_data_t keydata, void *vdata);
void		pr_mouse_handler(double xpos, double ypos, void *vdata);
void		pr_click_handler(mouse_key_t button, action_t action,
				modifier_key_t mods, void *vdata);
void		pr_move_head(void *vdata);

// utils.c
t_sphere	**pr_add_sphere(t_sphere **spheres, t_data *data);
mlx_image_t	*pr_slow_down(struct timeval start_time, t_data *data,
				int target_fps, int do_return);
int			pr_rand_color(void);
void		pr_put_thick_pixel(mlx_image_t *screen, int x, int y,
				int thickness, int color);
float		pr_clamp(float num, float min, float max);

#endif