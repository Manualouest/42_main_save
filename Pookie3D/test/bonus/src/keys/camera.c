/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:39:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:26:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_right(t_game *game, float amount)
{
	float	olddirx;
	float	oldplanex;

	olddirx = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(amount * game->mlx->delta_time)
		- game->player.diry * sin(amount * game->mlx->delta_time);
	game->player.diry = olddirx * sin(amount * game->mlx->delta_time)
		+ game->player.diry * cos(amount * game->mlx->delta_time);
	oldplanex = game->player.planex;
	game->player.planex = game->player.planex
		* cos(amount * game->mlx->delta_time)
		- game->player.planey * sin(amount * game->mlx->delta_time);
	game->player.planey = oldplanex * sin(amount * game->mlx->delta_time)
		+ game->player.planey * cos(amount * game->mlx->delta_time);
}

void	cd_left(t_game *game, float amount)
{
	float	olddirx;
	float	oldplanex;

	olddirx = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(amount * game->mlx->delta_time)
		- game->player.diry * sin(amount * game->mlx->delta_time);
	game->player.diry = olddirx * sin(amount * game->mlx->delta_time)
		+ game->player.diry * cos(amount * game->mlx->delta_time);
	oldplanex = game->player.planex;
	game->player.planex = game->player.planex
		* cos(amount * game->mlx->delta_time)
		- game->player.planey * sin(amount * game->mlx->delta_time);
	game->player.planey = oldplanex * sin(amount * game->mlx->delta_time)
		+ game->player.planey * cos(amount * game->mlx->delta_time);
}

void	cd_up(t_game *game, float amount)
{
	game->player.pitch = cd_clamp_two(game->player.pitch
			+ amount * game->mlx->delta_time, -0.75, 0.75);
}

void	cd_down(t_game *game, float amount)
{
	game->player.pitch = cd_clamp_two(game->player.pitch
			+ amount * game->mlx->delta_time, -0.75, 0.75);
}

void	cd_camera(t_game *game)
{
	if (game->keys.left == 1)
		cd_left(game, -1.F);
	if (game->keys.right == 1)
		cd_right(game, 1.F);
	if (game->keys.up == 1)
		cd_up(game, 1.F);
	if (game->keys.down == 1)
		cd_down(game, -1.F);
	if (game->keys.mouse)
	{
		game->keys.left = 0;
		game->keys.right = 0;
		game->keys.down = 0;
		game->keys.up = 0;
	}
}
