/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:01 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:51:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_init_door_ray_vars(t_game *game, t_ray_info *ray, float cam_x)
{
	ray->x = (int)game->player.x;
	ray->y = (int)game->player.y;
	ray->dx = game->player.dirx + (game->player.planex
			* cam_x - game->player.planex) + 0.0000001;
	ray->dy = game->player.diry + (game->player.planey
			* cam_x - game->player.planey) + 0.0000001;
	ray->delta_dx = fabs(1.F / ray->dx);
	ray->delta_dy = fabs(1.F / ray->dy);
	ray->step_x = 1;
	ray->side_dx = (ray->x + 1.F - game->player.x) * ray->delta_dx;
	if (ray->dx < 0)
	{
		ray->step_x = -1;
		ray->side_dx = (game->player.x - ray->x) * ray->delta_dx;
	}
	ray->step_y = 1;
	ray->side_dy = (ray->y + 1.F - game->player.y) * ray->delta_dy;
	if (ray->dy < 0)
	{
		ray->step_y = -1;
		ray->side_dy = (game->player.y - ray->y) * ray->delta_dy;
	}
	ray->side = 0;
}

int	cd_door_ray_loop(t_game *game, t_ray_info *ray)
{
	while (((ray->side == 0 && ray->side_dx - ray->delta_dx < 920)
			|| (ray->side == 1 && ray->side_dy - ray->delta_dy < 920)))
	{
		if (ray->side_dx < ray->side_dy)
		{
			ray->side_dx += ray->delta_dx;
			ray->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dy += ray->delta_dy;
			ray->y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.map[(int)ray->y][(int)ray->x] == 2
			&& (fabs((float)((int)ray->y - (int)game->player.y)) == 1
				|| fabs((float)((int)ray->x - (int)game->player.x)) == 1)
			&& ((int)ray->y == (int)game->player.y
				|| (int)ray->x == (int)game->player.x))
			return (1);
		if (game->map.map[(int)ray->y][(int)ray->x] != 0)
			return (0);
	}
	return (0);
}

int	cd_cast_door_ray(t_game *game, t_ray_info *ray, float x)
{
	cd_init_door_ray_vars(game, ray, 2.F * x / game->graphic.width);
	if (!cd_door_ray_loop(game, ray))
		return (0);
	if (ray->side == 0)
		ray->distance = ray->side_dx - ray->delta_dx;
	else
		ray->distance = ray->side_dy - ray->delta_dy;
	if (ray->distance > 960)
		ray->distance = 960;
	ray->wall_height = game->graphic.height / ray->distance;
	return (1);
}

void	cd_draw_door(t_game *game, t_ray_info *ray, float x)
{
	int	**texture;
	int	y;

	texture = cd_get_texture(game, ray);
	game->graphic.up += ray->wall_height
		* (cd_get_p_rsqrt(game, (int)ray->x + 0.5, (int)ray->y + 0.5) - 0.6);
	if (game->graphic.up > game->graphic.down)
		return ;
	y = game->graphic.up - 1;
	if (y < -1)
		y = -1;
	game->graphic.dim = cd_start_dim(game);
	while (++y < game->graphic.down && y < game->graphic.height)
	{
		mlx_put_pixel(game->screen, x, y,
			texture[(int)ray->t_x + 1][(int)(
				(float)(y - game->graphic.up) * game->graphic.y_ratio)]);
		cd_dim_color(game, x, y, game->graphic.dim);
	}
}

void	cd_render_door_slice(t_game *game)
{
	int	x;

	x = -1;
	while (++x < ((int)game->graphic.width))
	{
		if (!cd_cast_door_ray(game, &game->rays, x))
			continue ;
		cd_draw_door(game, &game->rays, x);
	}
}
