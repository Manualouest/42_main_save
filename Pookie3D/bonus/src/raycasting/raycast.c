/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:23:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:25:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_init_ray_vars(t_game *game, t_ray_info *ray, float cam_x)
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

void	cd_ray_loop(t_game *game, t_ray_info *ray)
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
			continue ;
		if (game->map.map[(int)ray->y][(int)ray->x] != 0)
			break ;
	}
}

void	cd_cast_ray(t_game *game, t_ray_info *ray, float x)
{
	cd_init_ray_vars(game, ray, 2.F * x / game->graphic.width);
	cd_ray_loop(game, ray);
	if (ray->side == 0)
		ray->distance = ray->side_dx - ray->delta_dx;
	else
		ray->distance = ray->side_dy - ray->delta_dy;
	if (ray->distance > 960)
		ray->distance = 960;
	ray->sprite_distances[(int)x] = ray->distance;
	ray->wall_height = game->graphic.height / ray->distance;
	if (x == (int)game->graphic.width >> 1)
	{
		ray->x_save = ray->x;
		if (game->keys.place && ray->side == 0)
			ray->x_save -= ray->step_x;
		ray->y_save = ray->y;
		if (game->keys.place && ray->side == 1)
			ray->y_save -= ray->step_y;
		ray->distance_save = ray->distance;
	}
}

void	cd_setup_vars(t_game *game)
{
	int	i;

	game->t_info.dx0 = game->player.dirx - game->player.planex;
	game->t_info.dy0 = game->player.diry - game->player.planey;
	game->t_info.dx1 = game->player.dirx + game->player.planex;
	game->t_info.dy1 = game->player.diry + game->player.planey;
	game->t_info.stepx = (game->t_info.dx1 - game->t_info.dx0)
		/ game->graphic.width;
	game->t_info.stepy = (game->t_info.dy1 - game->t_info.dy0)
		/ game->graphic.width;
	game->graphic.up_op = (int)(game->graphic.height
			+ game->graphic.height * game->player.pitch) >> 1;
	free(game->rays.sprite_distances);
	game->rays.sprite_distances = ft_calloc(sizeof(int), game->graphic.width);
	i = -1;
	while (game->graphic.sprites && game->graphic.sprites[++i])
	{
		game->graphic.sprites[i]->distance = cd_get_p_rsqrt(game,
				game->graphic.sprites[i]->x, game->graphic.sprites[i]->y);
		if (game->graphic.sprites[i]->distance >= 0.9)
			cd_remove_sprite(game, i);
	}
}

void	cd_render(t_game *game)
{
	struct timeval	time;
	int				x;

	gettimeofday(&time, NULL);
	if (game->fps)
		mlx_delete_image(game->mlx, game->fps);
	cd_modif_res(game, 0, 0);
	cd_setup_vars(game);
	x = -1;
	mlx_resize_image(game->screen, game->graphic.width, game->graphic.height);
	while (++x < ((int)game->graphic.width))
	{
		cd_cast_ray(game, &game->rays, x);
		cd_draw_walls(game, &game->rays, x);
	}
	cd_render_sprites(game, 1);
	cd_render_door_slice(game);
	cd_modif_res(game, 1, 0);
	mlx_resize_image(game->screen, game->graphic.width, game->graphic.height);
	cd_edit_wall(game, game->rays.x_save, game->rays.y_save);
	cd_moove(game);
	cd_show_block_inventory(game);
	cd_minimap(game);
	if (game->keys.fps)
		game->fps = cd_slow_raycast(game, time, 10000);
}
