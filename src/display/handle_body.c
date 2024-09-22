/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:55:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 21:24:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

void	pr_draw_body_link(t_data * data, t_sphere *sorigin, t_sphere *starget)
{
	int		i;
	t_coord	d;
	t_coord	pos;
	t_coord	origin;
	t_coord	target;

	origin.x =data->vars.cos[(int)pr_clamp((sorigin->o * 100.) + 157, 0, 629)] * sorigin->r + sorigin->x;
	origin.y =data->vars.sin[(int)pr_clamp((sorigin->o * 100.) + 157, 0, 629)] * sorigin->r + sorigin->y;
	target.x =data->vars.cos[(int)pr_clamp((starget->o * 100.) + 157, 0, 629)] * starget->r + starget->x;
	target.y =data->vars.sin[(int)pr_clamp((starget->o * 100.) + 157, 0, 629)] * starget->r + starget->y;
	d.x = pr_clamp((atan2(target.y - origin.y, target.x - origin.x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	d.y = data->vars.sin[(int)(d.x * 100.)];
	d.x = data->vars.cos[(int)(d.x * 100.)];
	pos.x = origin.x;
	pos.y = origin.y;
	i = 0;
	while ((floor(pos.x) < floor(target.x) - 2 || floor(pos.x) > floor(target.x) + 2
		|| floor(pos.y) < floor(target.y) - 2 || floor(pos.y) > floor(target.y) + 2)
		&& ++i < 100)
	{
		printf("%f, %f\n", d.x, d.y);
		pos.x += d.x;
		pos.y += d.y;
		pr_put_thick_pixel(data->mlx.screen, (int)pos.x, (int)pos.y, 2, sorigin->color);
	}

	origin.x =data->vars.cos[(int)pr_clamp((sorigin->o * 100.) - 157, 0, 629)] * sorigin->r + sorigin->x;
	origin.y =data->vars.sin[(int)pr_clamp((sorigin->o * 100.) - 157, 0, 629)] * sorigin->r + sorigin->y;
	target.x =data->vars.cos[(int)pr_clamp((starget->o * 100.) - 157, 0, 629)] * starget->r + starget->x;
	target.y =data->vars.sin[(int)pr_clamp((starget->o * 100.) - 157, 0, 629)] * starget->r + starget->y;
	d.x = pr_clamp((atan2(target.y - origin.y, target.x - origin.x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	d.y = data->vars.sin[(int)(d.x * 100.)];
	d.x = data->vars.cos[(int)(d.x * 100.)];
	pos.x = origin.x;
	pos.y = origin.y;
	i = 0;
	while ((floor(pos.x) < floor(target.x) - 2 || floor(pos.x) > floor(target.x) + 2
		|| floor(pos.y) < floor(target.y) - 2 || floor(pos.y) > floor(target.y) + 2)
		&& ++i < 100)
	{
		pos.x += d.x;
		pos.y += d.y;
		pr_put_thick_pixel(data->mlx.screen, (int)pos.x, (int)pos.y, 2, sorigin->color);
	}
}

void	pr_draw_circle(mlx_image_t *screen, t_data *data, t_sphere *sphere, int id)
{
	int		i;
	int		x;
	int		y;
	
	i = -1;
	if (id == 0)
	{
		x = data->vars.cos[(int)(pr_clamp(sphere->o + 0.25 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r * 0.6) + sphere->x;
		y = data->vars.sin[(int)(pr_clamp(sphere->o + 0.25 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r * 0.6) + sphere->y;
		pr_put_thick_pixel(screen, x, y, 2, sphere->color);
		x = data->vars.cos[(int)(pr_clamp(sphere->o - 0.25 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r * 0.6) + sphere->x;
		y = data->vars.sin[(int)(pr_clamp(sphere->o - 0.25 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r * 0.6) + sphere->y;
		pr_put_thick_pixel(screen, x, y, 2, sphere->color);
	}
	while ((id == 0 || id == data->nb_sphere - 1) && ++i < sphere->r * 2)
	{
		y = data->vars.sin[(int)pr_clamp(((float)i * (315. / (float)(sphere->r * 2))) + floor(sphere->o * 100.) + 157 * (1 - 2 * (id == 0)), 0, 628)] * sphere->r + sphere->y;
		x = data->vars.cos[(int)pr_clamp(((float)i * (315. / (float)(sphere->r * 2))) + floor(sphere->o * 100.) + 157 * (1 - 2 * (id == 0)), 0, 628)] * sphere->r + sphere->x;
		pr_put_thick_pixel(screen, x, y, 2, sphere->color);
	}
	
	if (id != 0)
		pr_draw_body_link(data, data->spheres[id - 1], sphere);

	x = data->vars.cos[(int)(pr_clamp(sphere->o + 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r) + sphere->x;
	y = data->vars.sin[(int)(pr_clamp(sphere->o + 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r) + sphere->y;
	pr_put_thick_pixel(screen, x, y, 2, sphere->color);
	x = data->vars.cos[(int)(pr_clamp(sphere->o - 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r) + sphere->x;
	y = data->vars.sin[(int)(pr_clamp(sphere->o - 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r) + sphere->y;
	pr_put_thick_pixel(screen, x, y, 2, sphere->color);
}

void	pr_move_body(t_data *data, t_sphere **spheres)
{
	int		i;
	float	dst;

	i = 0;
	while (++i < data->nb_sphere)
	{
		if (data->spheres[i - 1]->x < 0 || data->spheres[i - 1]->x >= data->mlx.w_width || data->spheres[i - 1]->y < 0 || data->spheres[i - 1]->y >= data->mlx.w_height)
			break;
		if (sqrt(pow(spheres[i - 1]->x - spheres[i]->x, 2) + pow(spheres[i - 1]->y - spheres[i]->y, 2)) > spheres[i - 1]->link_len)
		{
			spheres[i]->o = pr_clamp((atan2(spheres[i - 1]->y - spheres[i]->y, spheres[i - 1]->x - spheres[i]->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
			pr_constrain_angle(spheres[i], spheres[i - 1]);
			dst = sqrt(pow(spheres[i - 1]->x - spheres[i]->x, 2) + pow(spheres[i - 1]->y - spheres[i]->y, 2));
			dst = spheres[i - 1]->link_len / dst;
			spheres[i]->x = ((1 - dst) * spheres[i - 1]->x + dst * spheres[i]->x);
			spheres[i]->y = ((1 - dst) * spheres[i - 1]->y + dst * spheres[i]->y);
		}
	}
}
