/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:00:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/16 09:30:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	**cd_get_texture(t_game *game, t_ray_info *ray)
{
	int	**texture;

	if (ray->side == 0 && ray->dx > 0)
		texture = game->graphic.ea;
	else if (ray->side == 0 && ray->dx <= 0)
		texture = game->graphic.we;
	else if (ray->side == 1 && ray->dy > 0)
		texture = game->graphic.so;
	else
		texture = game->graphic.no;
	if (ray->side == 0)
		ray->t_x = game->player.y + ray->distance * ray->dy;
	else
		ray->t_x = game->player.x + ray->distance * ray->dx;
	ray->t_x = (int)((ray->t_x - floor(ray->t_x)) * ((float)texture[0][0]));
	return (texture);
}

void	cd_draw_walls(t_game *game, t_ray_info *ray, int x)
{
	int		**texture;
	int		up;
	int		down;
	int		y;
	float	y_ratio;

	texture = cd_get_texture(game, ray);
	up = ((float)game->screen->height - 1.) / 2. - ray->wall_height / 2.
		+ (((float)game->screen->height - 1.) / 2.) * game->player.pitch
		+ ray->wall_height * game->player.height;
	down = ((float)game->screen->height - 1.) / 2. + ray->wall_height / 2.
		+ (((float)game->screen->height - 1.) / 2.) * game->player.pitch
		+ ray->wall_height * game->player.height; 
	y_ratio = (((float)texture[0][1]) / (float)(down - up));
	y = -1;
	while (++y < up && y < down)
		mlx_put_pixel(game->screen, x, y, game->graphic.c);
	y --;
	while (++y < down && y < (int)game->screen->height - 1)
		mlx_put_pixel(game->screen, x, y,
			texture[(int)((float)(y - up + 1) * y_ratio)][(int)ray->t_x]);
	y --;
	while (++y < (int)game->screen->height - 1)
		mlx_put_pixel(game->screen, x, y, game->graphic.f);
}

void	cd_draw_c_f(t_game *game, int x)
{
	int	y;
	int	mid;

	y = -1;
	mid = (game->graphic.height ) / 2.
		+ ((game->graphic.height - 1.) / 2.) * game->player.pitch;
	while (++y < mid)
		mlx_put_pixel(game->screen, x, y, game->graphic.c);
	y --;
	while (++y < game->graphic.height)
		mlx_put_pixel(game->screen, x, y, game->graphic.f);
}

