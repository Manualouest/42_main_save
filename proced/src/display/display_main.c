/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:13:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 20:15:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

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
		if (data->spheres[i]->x < 0 || data->spheres[i]->x >= data->mlx.w_width || data->spheres[i]->y < 0 || data->spheres[i]->y >= data->mlx.w_height)
			break;
		pr_draw_circle(data->mlx.screen, data, data->spheres[i], i);
		if (data->leg_spots[i] == 1)
		{
			pr_draw_legs(data->mlx.screen, data, data->spheres[i]->r_leg);
			pr_draw_legs(data->mlx.screen, data, data->spheres[i]->l_leg);
		}
	}
}

void	pr_preset_legs(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_sphere)
	{
		if (data->spheres[i]->x < data->mlx.w_width)
			continue;
		if (data->leg_spots[i] == 1)
		{
			data->spheres[i]->l_leg->hand->x = data->mlx.w_width;
			data->spheres[i]->l_leg->elbow->x = data->mlx.w_width;
			data->spheres[i]->r_leg->hand->x = data->mlx.w_width + 10;
			data->spheres[i]->r_leg->elbow->x = data->mlx.w_width;
		}
	}
}

void	pr_display_main(t_data *data)
{
	data->mlx.mlx = mlx_init(data->mlx.w_width, data->mlx.w_height, "proced", false);
	data->mlx.screen = mlx_new_image(data->mlx.mlx, data->mlx.w_width, data->mlx.w_height);
	pr_preset_legs(data);
	mlx_image_to_window(data->mlx.mlx, data->mlx.screen, 0, 0);
	pr_render(data);
	mlx_key_hook(data->mlx.mlx, pr_close, (void *)data);
	mlx_mouse_hook(data->mlx.mlx, pr_click_handler, (void *)data);
	// mlx_cursor_hook(data->mlx.mlx, pr_mouse_handler, (void *)data);
	mlx_loop_hook(data->mlx.mlx, pr_move_head, (void *)data);
	mlx_loop(data->mlx.mlx);
	mlx_delete_image(data->mlx.mlx, data->mlx.screen);
	if (data->mlx.fps)
		mlx_delete_image(data->mlx.mlx, data->mlx.fps);
	mlx_terminate(data->mlx.mlx);
}