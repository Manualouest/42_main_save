/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:55:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/21 20:09:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

void	pr_draw_circle(mlx_image_t *screen, t_data *data, t_sphere *sphere, int id)
{
	int	i;
	int	x;
	int	y;
	
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
			dst = sqrt(pow(spheres[i - 1]->x - spheres[i]->x, 2) + pow(spheres[i - 1]->y - spheres[i]->y, 2));
			dst = spheres[i - 1]->link_len / dst;
			spheres[i]->x = ((1 - dst) * spheres[i - 1]->x + dst * spheres[i]->x);
			spheres[i]->y = ((1 - dst) * spheres[i - 1]->y + dst * spheres[i]->y);
		}
	}
}
