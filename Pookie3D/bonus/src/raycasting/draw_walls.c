/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:23:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:23:03 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	**cd_get_texture(t_game *game, t_ray_info *ray)
{
	int	**texture;

	texture = game->graphic.txts[game->graphic.tmap[(int)ray->y][(int)ray->x]];
	if (ray->side == 0)
		ray->t_x = game->player.y + ray->distance * ray->dy;
	else
		ray->t_x = game->player.x + ray->distance * ray->dx;
	ray->t_x = (int)((ray->t_x - floor(ray->t_x)) * ((float)texture[0][0]));
	game->graphic.up = game->graphic.up_op - ((int)ray->wall_height >> 1)
		+ ray->wall_height * game->player.height;
	game->graphic.down = game->graphic.up + ray->wall_height;
	game->graphic.y_ratio = (((float)texture[0][1])
			/ (float)(game->graphic.down - game->graphic.up));
	return (texture);
}

void	cd_dim_color(t_game *game, int x, int y, float effect)
{
	int	pos;

	pos = (int)(y * game->graphic.width + x) << 2;
	if (effect > 0.02)
		effect += 0.02;
	if (effect > 0.05)
		effect += 0.02;
	if (effect > 0.1)
		effect += 0.02;
	if (effect > 0.3)
		effect += 0.02;
	if (effect > 0.5)
		effect += 0.02;
	if (effect > 1)
		effect = 1;
	game->screen->pixels[pos] *= effect;
	game->screen->pixels[pos + 1] *= effect;
	game->screen->pixels[pos + 2] *= effect;
}

float	cd_start_dim(t_game *game)
{
	float	effect;

	effect = 1.F / (game->rays.distance + 1.);
	return (effect);
}

void	cd_draw_walls(t_game *game, t_ray_info *ray, int x)
{
	int	**texture;
	int	y;

	texture = cd_get_texture(game, ray);
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
	cd_draw_tiles(game, x);
}

void	cd_draw_c_f(t_game *game, int x)
{
	int	y;

	y = -1;
	game->graphic.up = game->graphic.up_op - 2
		+ 4 * game->player.height;
	game->graphic.down = game->graphic.up + 4;
	game->graphic.dim = 0;
	y = game->graphic.up - 1;
	if (y < -1)
		y = -1;
	while (++y < game->graphic.down && y < (int)game->graphic.height)
		mlx_put_pixel(game->screen, x, y, 0x000000FF);
	cd_draw_tiles(game, x);
}
