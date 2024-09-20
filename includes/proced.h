/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proced.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:09:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 19:54:17 by mbirou           ###   ########.fr       */
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
	struct s_sphere	*hand;
}					t_leg;

typedef	struct s_sphere
{
	float	x;
	float	y;
	float	o;//orientation in rad
	int		r;//radius
	int		link_len;
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

//-----utils-----
// tab_utils.c
int		pr_tab_len(char **tab);
int		*pr_strtoi(char *str);
float	*pr_strtor(char *str);
// math_utils.c
float	pr_f_clamp(float num, float min, float max);

//-----inits-----
// struct_inits.c
void	pr_init_data(int argc, char **argv, t_data *data);

//-----display-----
// display_main.c
void	pr_display_main(t_data *data);

#endif