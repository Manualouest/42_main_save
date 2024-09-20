/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:34:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 20:25:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

t_sphere	*pr_create_sphere(t_data *data, int id)
{
	t_sphere	*sphere;

	sphere = ft_calloc(sizeof(*sphere), 1);
	if (id == 0)
		sphere->x = data->mlx.w_width / 2;
	else
		sphere->x = data->spheres[id - 1]->x + data->spheres[id - 1]->link_len;
	sphere->y = data->mlx.w_height / 2;
	sphere->o = M_PI;
	sphere->r = data->sizes[id];
	sphere->link_len = data->link_lenghts[id];
	sphere->max_angle = data->max_angles[id];
	sphere->r_leg = NULL;
	sphere->l_leg = NULL;
	return (sphere);
}

t_leg	*pr_create_leg(t_data *data, t_sphere *anchor, float side, int id)
{
	t_leg	*leg;

	leg = ft_calloc(sizeof(*leg), 1);
	leg->anchor = anchor;
	leg->side = side;
	leg->elbow = pr_create_sphere(data, id);
	leg->hand = pr_create_sphere(data, id);
	leg->elbow->link_len *= 1.5;
	leg->elbow->r *= 0.25;
	leg->elbow->y = data->vars.sin[(int)((anchor->o - side) * 100.)] * leg->elbow->link_len + anchor->y + anchor->r * (side / 1000000.);
	leg->hand->link_len *= 1.5;
	leg->hand->r *= 0.25;
	leg->hand->y = data->vars.sin[(int)((anchor->o - side) * 100.)] * leg->hand->link_len + leg->elbow->y;
	return (leg);
}

void	pr_setup_spheres(t_data *data)
{
	int			i;

	data->spheres = ft_calloc(sizeof(*data->spheres), data->nb_sphere + 1);
	data->spheres[data->nb_sphere] = NULL;
	i = -1;
	while (++i < data->nb_sphere)
	{
		data->spheres[i] = pr_create_sphere(data, i);
		if (data->leg_spots[i] == 1)
		{
			data->spheres[i]->r_leg = pr_create_leg(data, data->spheres[i], 0.5 * M_PI, i);
			data->spheres[i]->l_leg = pr_create_leg(data, data->spheres[i], -0.5 * M_PI, i);
		}
	}
}

void	pr_setup_vars(t_data *data)
{
	t_vars	vars;
	int		i;

	vars.cos = ft_calloc(sizeof(*vars.cos), 629);
	vars.sin = ft_calloc(sizeof(*vars.sin), 629);
	vars.cos[628] = -1;
	vars.sin[628] = -1;
	i = -1;
	while (++i < 628)
	{
		vars.cos[i] = cos((float)i / 100.);
		vars.sin[i] = sin((float)i / 100.);
	}
	data->vars = vars;
}

void	pr_init_data(int argc, char **argv, t_data *data)
{
	t_mlx	mlx;

	if (argc <= 1)
		data->nb_sphere = 6;
	else
		data->nb_sphere = ft_atoi(argv[1]);
	if (argc <= 2)
		data->sizes = pr_strtoi("60 40 40 40 40 40 40");
	else
		data->sizes = pr_strtoi(argv[2]);
	if (argc <= 3)
		data->link_lenghts = pr_strtoi("40 40 40 40 40 40");
	else
		data->link_lenghts = pr_strtoi(argv[3]);
	if (argc <= 4)
		data->max_angles = pr_strtor("13 13 13 13 13 13");
	else
		data->max_angles = pr_strtor(argv[4]);
	if (argc <= 5)
		data->leg_spots = pr_strtoi("0 0 1 0 1 0 0");
	else
		data->leg_spots = pr_strtoi(argv[5]);
	mlx.w_width = 1920;
	mlx.w_height = 1080;
	mlx.mlx = NULL;
	mlx.screen = NULL;
	mlx.fps = NULL;
	data->mlx = mlx;
	pr_setup_vars(data);
	pr_setup_spheres(data);
}
