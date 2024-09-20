/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:13:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 20:27:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

void	pr_put_thick_pixel(mlx_image_t *screen, int x, int y, int thickness, int color)
{
	int	i;
	int	ii;

	i = y - thickness;
	while (++i < y + thickness)
	{
		ii = x - thickness;
		while (++ii < x + thickness)
			mlx_put_pixel(screen, ii, i, color);
	}
}

float	pr_clamp(float num, float min, float max)
{
	if (num < min)
		return (max + num);
	if (num > max)
		return (num - max);
	return (num);
}

void	pr_draw_circle(mlx_image_t *screen, t_data *data, t_sphere *sphere)
{
	int	i;
	int	x;
	int	y;
	
	i = -1;
	pr_put_thick_pixel(screen, sphere->x, sphere->y, 2, 0x0000FFFF);
	pr_put_thick_pixel(screen, data->vars.cos[(int)(sphere->o * 100.)] * (sphere->r * 0.8) + sphere->x, data->vars.sin[(int)(sphere->o * 100.)] * (sphere->r * 0.8) + sphere->y, 2, 0x00FF00FF);
	while (++i < sphere->r * 4)
	{
		x = data->vars.cos[(int)((float)i * (628. / (float)(sphere->r * 4)))] * sphere->r + sphere->x;
		y = data->vars.sin[(int)((float)i * (628. / (float)(sphere->r * 4)))] * sphere->r + sphere->y;
		mlx_put_pixel(screen, x, y, 0xFFFFFFFF);
	}
	x = data->vars.cos[(int)(pr_clamp(sphere->o + 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r + 2) + sphere->x;
	y = data->vars.sin[(int)(pr_clamp(sphere->o + 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r + 2) + sphere->y;
	pr_put_thick_pixel(screen, x, y, 2, 0xFF0000FF);
	x = data->vars.cos[(int)(pr_clamp(sphere->o - 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r + 2) + sphere->x;
	y = data->vars.sin[(int)(pr_clamp(sphere->o - 0.5 * M_PI, 0, 2. * M_PI) * 100)] * (sphere->r + 2) + sphere->y;
	pr_put_thick_pixel(screen, x, y, 2, 0xFF0000FF);
}

void	pr_move_body(t_data *data, t_sphere **spheres)
{
	int		i;
	float	dst;

	i = 0;
	while (++i < data->nb_sphere)
	{
		if (sqrt(pow(spheres[i - 1]->x - spheres[i]->x, 2) + pow(spheres[i - 1]->y - spheres[i]->y, 2)) > spheres[i - 1]->link_len)
		{
			spheres[i]->o = pr_clamp((atan2(spheres[i - 1]->y - spheres[i]->y, spheres[i - 1]->x - spheres[i]->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
			// if (fabs(spheres[i - 1]->o - spheres[i]->o) > spheres[i - 1]->max_angle)
			// 	spheres[i]->o = pr_clamp(spheres[i]->o - (spheres[i - 1]->o - spheres[i]->o), 0, 2. * M_PI);
			dst = sqrt(pow(spheres[i - 1]->x - spheres[i]->x, 2) + pow(spheres[i - 1]->y - spheres[i]->y, 2));
			dst = spheres[i - 1]->link_len / dst;
			spheres[i]->x = ((1 - dst) * spheres[i - 1]->x + dst * spheres[i]->x);
			spheres[i]->y = ((1 - dst) * spheres[i - 1]->y + dst * spheres[i]->y);
		}
	}
}

void	pr_draw_legs(mlx_image_t *screen, t_data *data, t_leg *leg)
{
	int		i;
	float	dir_x;
	float	dir_y;

	pr_draw_circle(screen, data, leg->elbow);
	pr_draw_circle(screen, data, leg->hand);
	i = -1;
	dir_x = atan2(leg->anchor->y - leg->elbow->y, leg->anchor->x - leg->elbow->x);
	dir_y = data->vars.sin[(int)(dir_x * 100.)];
	dir_x = data->vars.cos[(int)(dir_x * 100.)];
	while (++i < leg->elbow->link_len * 0.5)
	{
		printf("x: %f, y: %f\n", dir_x * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->x, dir_y * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->y);
		pr_put_thick_pixel(screen, dir_x * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->x, dir_y * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->y, 1, 0xFF0000FF);
	}
}

void	pr_render(t_data *data)
{
	int	i;

	mlx_resize_image(data->mlx.screen, 1, 1);
	mlx_put_pixel(data->mlx.screen, 0, 0, 0x000000FF);
	mlx_resize_image(data->mlx.screen, data->mlx.w_width, data->mlx.w_height);
	pr_move_body(data, data->spheres);
	i = -1;
	while (++i < data->nb_sphere)
	{
		pr_draw_circle(data->mlx.screen, data, data->spheres[i]);
		// if (data->leg_spots[i] == 1)
		// {
		// 	pr_draw_legs(data->mlx.screen, data, data->spheres[i]->r_leg);
		// 	pr_draw_legs(data->mlx.screen, data, data->spheres[i]->l_leg);
		// }
	}
}

void	pr_move(mlx_key_data_t keydata, void *vdata)
{
	t_data	*data;

	data = (t_data *)vdata;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx.mlx);
		return ;
	}
}

void	pr_mouse_handler(double xpos, double ypos, void *vdata)
{
	t_data	*data;

	data = (t_data *)vdata;
	data->vars.m_x = xpos;
	data->vars.m_y = ypos;
}

void	pr_move_head(void *vdata)
{
	t_data		*data;
	t_sphere	**spheres;

	data = (t_data *)vdata;
	spheres = data->spheres;
	if ((data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x < data->vars.m_x - 5 || data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x > data->vars.m_x + 5)
		|| (data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y < data->vars.m_y - 5 || data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y > data->vars.m_y + 5))
	{
		spheres[0]->o = pr_clamp((atan2(data->vars.m_y - spheres[0]->y, data->vars.m_x - spheres[0]->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
		// if (fabs(spheres[0]->o - spheres[1]->o) > spheres[0]->max_angle)
		// 	spheres[0]->o = pr_clamp(spheres[0]->o - fabs(spheres[0]->o - spheres[1]->o - spheres[0]->max_angle), 0, 2. * M_PI);
		data->spheres[0]->x += data->vars.cos[(int)(100. * data->spheres[0]->o)];
		data->spheres[0]->y += data->vars.sin[(int)(100. * data->spheres[0]->o)];
		pr_render(data);
	}
	// usleep(16666);
}

void	pr_display_main(t_data *data)
{
	data->mlx.mlx = mlx_init(data->mlx.w_width, data->mlx.w_height, "proced", false);
	data->mlx.screen = mlx_new_image(data->mlx.mlx, data->mlx.w_width, data->mlx.w_height);
	mlx_image_to_window(data->mlx.mlx, data->mlx.screen, 0, 0);
	pr_render(data);
	mlx_key_hook(data->mlx.mlx, pr_move, (void *)data);
	mlx_cursor_hook(data->mlx.mlx, pr_mouse_handler, (void *)data);
	mlx_loop_hook(data->mlx.mlx, pr_move_head, (void *)data);
	mlx_loop(data->mlx.mlx);
	mlx_terminate(data->mlx.mlx);
}