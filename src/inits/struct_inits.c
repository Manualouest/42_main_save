/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:34:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/21 20:02:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

void	pr_set_sphere_color(t_sphere *sphere, int color)
{
	sphere->color = color;
	if (sphere->l_leg)
	{
		sphere->l_leg->elbow->color = color;
		sphere->l_leg->hand->color = color;
	}
	if (sphere->r_leg)
	{
		sphere->r_leg->elbow->color = color;
		sphere->r_leg->hand->color = color;
	}
}

void	pr_set_color(t_data *data)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = -1;
	while (i < data->nb_sphere)
	{
		r = 255;
		g = 0;
		b = 0;
		while (++g < 255 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
		while (--r > 0 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
		while (++b < 255 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
		while (--g > 0 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
		while (++r < 255 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
		while (--b > 0 && ++i < data->nb_sphere)
			pr_set_sphere_color(data->spheres[i], (r << 24 | g << 16 | b << 8 | 0xFF));
	}
}

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
	sphere->color = 0;
	return (sphere);
}

void	pr_init_leg_coord(t_leg *leg, t_data *data, t_sphere *elbow, t_sphere *hand)
{
	hand->x = data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7 + hand->link_len * 0.7) + leg->anchor->x;
	hand->y = data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7 + hand->link_len * 0.7) + leg->anchor->y;
	hand->x += data->vars.cos[(int)(hand->o * 100.)] * (hand->link_len + elbow->link_len * 0.8);
	hand->y += data->vars.sin[(int)(hand->o * 100.)] * (hand->link_len + elbow->link_len * 0.8);
	elbow->x = data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7) + leg->anchor->x;
	elbow->y = data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7) + leg->anchor->y;
	elbow->x += data->vars.cos[(int)pr_clamp((elbow->o * 100.), 0, 628)] * elbow->link_len * -0.1;
	elbow->y += data->vars.sin[(int)pr_clamp((elbow->o * 100.), 0, 628)] * elbow->link_len * -0.1;
}

t_leg	*pr_create_leg(t_data *data, t_sphere *anchor, float side, int id)
{
	t_leg	*leg;

	leg = ft_calloc(sizeof(*leg), 1);
	leg->anchor = anchor;
	leg->side = side;
	leg->elbow = pr_create_sphere(data, id);
	leg->hand = pr_create_sphere(data, id);
	leg->elbow->link_len = anchor->r * 1.5;
	if (leg->elbow->link_len < 10)
		leg->elbow->link_len = 10;
	leg->elbow->r = 0;
	pr_init_leg_coord(leg, data, leg->elbow, leg->hand);
	leg->e_x = leg->elbow->x;
	leg->e_y = leg->elbow->y;
	leg->hand->link_len = anchor->r * 1.5;
	if (leg->hand->link_len < 10)
		leg->hand->link_len = 10;
	leg->hand->r = 0;
	leg->h_x = leg->hand->x;
	leg->h_y = leg->hand->y;
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
			data->spheres[i]->r_leg = pr_create_leg(data, data->spheres[i], -1, i);
			data->spheres[i]->l_leg = pr_create_leg(data, data->spheres[i], 1, i);
		}
	}
	pr_set_color(data);
}

void	pr_setup_vars(t_data *data)
{
	t_vars			vars;
	int				i;
	struct timeval	time;

	vars.cos = ft_calloc(sizeof(*vars.cos), 630);
	vars.sin = ft_calloc(sizeof(*vars.sin), 630);
	vars.cos[629] = -1;
	vars.sin[629] = -1;
	i = -1;
	while (++i < 629)
	{
		vars.cos[i] = cos((float)i / 100.);
		vars.sin[i] = sin((float)i / 100.);
	}
	vars.m_x = 0;
	vars.m_y = 0;
	vars.tracking = 0;
	gettimeofday(&time, NULL);
	srand(time.tv_usec + time.tv_sec);
	vars.r_x = abs(rand()) * ((float)(data->mlx.w_width - 1) / (float)INT32_MAX);
	vars.r_y = abs(rand()) * ((float)(data->mlx.w_height - 1) / (float)INT32_MAX);
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
		data->sizes = pr_strtoi("40", data);
	else
		data->sizes = pr_strtoi(argv[2], data);
	if (argc <= 3)
		data->link_lenghts = pr_strtoi("40", data);
	else
		data->link_lenghts = pr_strtoi(argv[3], data);
	if (argc <= 4)
		data->max_angles = pr_strtor("13", data);
	else
		data->max_angles = pr_strtor(argv[4], data);
	if (argc <= 5)
		data->leg_spots = pr_strtoi("0", data);
	else
		data->leg_spots = pr_strtoi(argv[5], data);
	mlx.w_width = 1920;
	mlx.w_height = 1016;
	mlx.mlx = NULL;
	mlx.screen = NULL;
	mlx.fps = NULL;
	data->mlx = mlx;
	pr_setup_vars(data);
	pr_setup_spheres(data);
}
