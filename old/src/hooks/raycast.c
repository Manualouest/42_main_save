/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:04:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/18 14:38:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#include <stdio.h>

t_ray_info	cd_cast_ray(t_info *info, t_ray_info ray_info)
{
	double	dx;
	double	dy;
	double	ddx;
	double	ddy;
	int		step_x;
	int		step_y;
	double	side_dx;
	double	side_dy;

	dx = cos(ray_info.angle);
	dy = sin(ray_info.angle);

	ray_info.x = (int)info->p_pos->x;
	ray_info.y = (int)info->p_pos->y;

	ddx = fabs(1 / dx);
	ddy = fabs(1 / dy);

	if (dx < 0)
	{
		step_x = -1;
		side_dx = (info->p_pos->x - ray_info.x) * ddx;
	}
	else
	{
		step_x = 1;
		side_dx = (ray_info.x + 1 - info->p_pos->x) * ddx;
	}
	if (dy < 0)
	{
		step_y = -1;
		side_dy = (info->p_pos->y - ray_info.y) * ddy;
	}
	else
	{
		step_y = 1;
		side_dy = (ray_info.y + 1 - info->p_pos->y) * ddy;
	}
	ray_info.side = 0;
	while (info->map[(int)ray_info.y][(int)ray_info.x])
	{
		if (side_dx < side_dy)
		{
			side_dx += ddx;
			ray_info.x += step_x;
			ray_info.side = 0;
		}
		else
		{
			side_dy += ddy;
			ray_info.y += step_y;
			ray_info.side = 1;
		}
		if (info->map[(int)ray_info.y][(int)ray_info.x] == '1'
			|| side_dx - ddx > 200 || side_dy - ddy > 200)
			break;
	}
	if (ray_info.side == 0)
		ray_info.distance = side_dx - ddx;
	else
		ray_info.distance = side_dy - ddy;
	ray_info.wall_height = ((float)info->mlx_info->w_height) / cd_round(ray_info.distance * cos(cd_basic_f_clamp(info->p_pos->orientation - ray_info.angle , 0.0, 2.0 * M_PI)), 100000);
	return (ray_info);
}

int	cd_get_texture(t_frame_info *texture, t_ray_info ray_info, int y, int max_y)
{
	if ((ray_info.side == 0 && cos(ray_info.angle) < 0)
		|| (ray_info.side == 1 && sin(ray_info.angle) > 0))
		ray_info.t_x = ((float)texture->width) - ray_info.t_x - 1.0;
	y = (float)y * (((float)texture->height - 1.0) / (float)max_y);
	// dst = texture->addr + (y * texture->line_size + (int)floor(ray_info.t_x) *
	// 	(texture->bits_per_pixel / 8));
	// return (*(unsigned int *)dst);
	// color = texture->tab[y][(int)floor(ray_info.t_x)];
	return (texture->tab[y][(int)floor(ray_info.t_x)]);
}

t_frame_info	*cd_get_texture_side(t_mlx_info *mlx_info, t_ray_info *ray_info)
{
	t_frame_info	*texture;

	if (ray_info->side == 0 && cos(ray_info->angle) > 0)
		texture = mlx_info->east;
	else if (ray_info->side == 0 && cos(ray_info->angle) <= 0)
		texture = mlx_info->west;
	else if (ray_info->side == 1 && sin(ray_info->angle) > 0)
		texture = mlx_info->south;
	else
		texture = mlx_info->north;
	if (ray_info->side == 0)
		ray_info->t_x = ray_info->p_y + ray_info->distance * sin(ray_info->angle);
	else
		ray_info->t_x = ray_info->p_x + ray_info->distance * cos(ray_info->angle);
	ray_info->t_x = ray_info->t_x - floor(ray_info->t_x);
	ray_info->t_x = ray_info->t_x * (float)(texture->width - 1.0);
	return (texture);
}

void	cd_draw_wall(t_info *info, t_mlx_info *mlx_info, int i,
	t_ray_info ray_info)
{
	int	up;
	int	end;
	int	n;
	int	color;
	t_frame_info	*texture;

	up = floor(-ray_info.wall_height / 2.0 +
		cd_round(((float)mlx_info->w_height / 2.0) +
		((float)mlx_info->w_height / 2.0) * info->p_pos->pitch +
		ray_info.wall_height * info->p_pos->height, 1000));
	end = floor(ray_info.wall_height / 2.0 +
		cd_round(((float)mlx_info->w_height / 2.0) +
		((float)mlx_info->w_height / 2.0) * info->p_pos->pitch +
		ray_info.wall_height * info->p_pos->height, 1000));
	n = -1;
	while (++n < up && up >= 0)
		cd_change_pixel_color(mlx_info->main_frame, i, n, mlx_info->roof);
	n --;
	if (n + 1 < end && n + 1 < mlx_info->w_height)
		texture = cd_get_texture_side(mlx_info, &ray_info);
	while (++n < end && n < mlx_info->w_height)
	{
		color = cd_get_texture(texture, ray_info, n - up, end - up - 1);
		// color = 0x007F7F7F;
		cd_change_pixel_color(mlx_info->main_frame, i, n, color);
	}
	n --;
	while (++n < mlx_info->w_height)
		cd_change_pixel_color(mlx_info->main_frame, i, n, mlx_info->floor);
}

void	cd_raycast(t_info *info)
{
	float		rays;
	float		i;
	t_ray_info	ray_info;

	rays = info->mlx_info->w_width; //info->mlx_info->w_width;
	i = 0;
	// printf("start\n");
	ray_info.p_x = info->p_pos->x;
	ray_info.p_y = info->p_pos->y;
	info->p_pos->orientation = cd_round(info->p_pos->orientation, 1000);
	while (i < rays)
	{
		ray_info.angle = (info->p_pos->orientation - (info->mlx_info->fov / 2.0) + i * (info->mlx_info->fov / rays)); //(M_PI / 4.0) is the fov
		ray_info.angle = cd_basic_f_clamp(ray_info.angle, 0, 2.0 * M_PI);
		ray_info = cd_cast_ray(info, ray_info);
		// printf("ray_angle: %f, wall_height: %f\n", ray_angle, wall_height);
		cd_draw_wall(info, info->mlx_info, (int)floor(i * (rays / info->mlx_info->w_width)), ray_info);
		i ++;
	}

	// printf("end\n");
}
