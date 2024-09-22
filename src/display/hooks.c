/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:05:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 21:24:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

void	pr_close(mlx_key_data_t keydata, void *vdata)
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

void	pr_click_handler(mouse_key_t button, action_t action,
			modifier_key_t mods, void *vdata)
{
	t_data	*data;

	data = (t_data *)vdata;
	(void)mods;
	if (action != MLX_RELEASE && button == MLX_MOUSE_BUTTON_LEFT)
		data->vars.tracking = 1;
	else if (button == MLX_MOUSE_BUTTON_LEFT)
		data->vars.tracking = 0;
}

void	pr_constrain_angle(t_sphere *origin, t_sphere *anchor)
{
	if (fabs(M_PI - pr_clamp(origin->o + M_PI - anchor->o, 0, M_PI * 2.)) <= origin->max_angle)
		return ;
	if ((pr_clamp(anchor->o - origin->max_angle, 0, M_PI * 2.)) > origin->max_angle)
		origin->o = pr_clamp(anchor->o - origin->max_angle, 0, M_PI * 2.);
	else
		origin->o = pr_clamp(anchor->o + origin->max_angle, 0, M_PI * 2.);

}

void	pr_move_head(void *vdata)
{
	t_data			*data;
	t_sphere		**spheres;
	// float			dst;
	struct timeval	time;

	gettimeofday(&time, NULL);
	data = (t_data *)vdata;
	if (data->mlx.fps)
	{
		mlx_delete_image(data->mlx.mlx, data->mlx.fps);
		data->mlx.fps = NULL;
	}
	spheres = data->spheres;
	if (data->vars.tracking)
		mlx_get_mouse_pos(data->mlx.mlx, &data->vars.m_x, &data->vars.m_y);
	if (data->vars.tracking &&
		((data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x < data->vars.m_x - 5 || data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x > data->vars.m_x + 5)
		|| (data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y < data->vars.m_y - 5 || data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y > data->vars.m_y + 5)))
	{
		spheres[0]->o = pr_clamp((atan2(data->vars.m_y - spheres[0]->y, data->vars.m_x - spheres[0]->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
		
		// pr_constrain_angle(spheres[0], spheres[2]);
		
		// if (fabs(spheres[0]->o - spheres[1]->o) > spheres[0]->max_angle)
		// 	spheres[0]->o = pr_clamp(spheres[0]->o - fabs(spheres[0]->o - spheres[1]->o - spheres[0]->max_angle), 0, 2. * M_PI);
		// dst = sqrt(pow(data->mlx.w_width, 2) + pow(data->mlx.w_height, 2)) - sqrt(pow(data->spheres[0]->x - data->vars.m_x, 2) + pow(data->spheres[0]->y - data->vars.m_y, 2));
		data->spheres[0]->x += data->vars.cos[(int)(100. * data->spheres[0]->o)] * 2.; // * (sqrt(pow(data->mlx.w_width, 2) + pow(data->mlx.w_height, 2)) / dst) 
		data->spheres[0]->y += data->vars.sin[(int)(100. * data->spheres[0]->o)] * 2.; // * (sqrt(pow(data->mlx.w_width, 2) + pow(data->mlx.w_height, 2)) / dst) 
		// data->spheres = pr_add_sphere(data->spheres, data);
		pr_render(data);
	}
	else if (!data->vars.tracking &&
		((data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x < data->vars.r_x - 5 || data->vars.cos[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->x > data->vars.r_x + 5)
		|| (data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y < data->vars.r_y - 5 || data->vars.sin[(int)(spheres[0]->o * 100.)] * (spheres[0]->r * 1.2) + spheres[0]->y > data->vars.r_y + 5)))
	{
		if (sqrt(pow(spheres[0]->x - data->vars.r_x, 2) + pow(spheres[0]->y - data->vars.r_y, 2)) <= spheres[0]->r + 20)
		{
			data->vars.r_x = abs(rand()) * ((float)(data->mlx.w_width - 1) / (float)INT32_MAX);
			data->vars.r_y = abs(rand()) * ((float)(data->mlx.w_height - 1) / (float)INT32_MAX);
		}
		spheres[0]->o = pr_clamp((atan2(data->vars.r_y - spheres[0]->y, data->vars.r_x - spheres[0]->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
		// if (fabs(spheres[0]->o - spheres[1]->o) > spheres[0]->max_angle)
		// 	spheres[0]->o = pr_clamp(spheres[0]->o - fabs(spheres[0]->o - spheres[1]->o - spheres[0]->max_angle), 0, 2. * M_PI);
		data->spheres[0]->x += data->vars.cos[(int)(100. * data->spheres[0]->o)] * 2.;
		data->spheres[0]->y += data->vars.sin[(int)(100. * data->spheres[0]->o)] * 2.;
		// data->spheres = pr_add_sphere(data->spheres, data);
		pr_render(data);
	}
	data->mlx.fps = pr_slow_down(time, data, 60, 1);
}
