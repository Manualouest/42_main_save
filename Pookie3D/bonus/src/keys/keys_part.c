/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:34:01 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:27:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_moove_forward(t_game *game)
{
	float	testx;
	float	testy;

	if (game->keys.w != 0)
	{
		testx = game->player.x + game->player.dirx
			* game->player.speed * game->mlx->delta_time;
		testy = game->player.y + game->player.diry
			* game->player.speed * game->mlx->delta_time;
		if (game->map.map[(int)testy][(int)game->player.x] == 1)
		{
			if (game->map.map[(int)game->player.y][(int)testx] == 1)
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == 1)
			return ;
		game->player.x = testx;
	}
}

void	cd_moove_backward(t_game *game)
{
	float	testx;
	float	testy;

	if (game->keys.s != 0)
	{
		testx = game->player.x - game->player.dirx
			* game->player.speed * game->mlx->delta_time;
		testy = game->player.y - game->player.diry
			* game->player.speed * game->mlx->delta_time;
		if (game->map.map[(int)testy][(int)game->player.x] == 1)
		{
			if (game->map.map[(int)game->player.y][(int)testx] == 1)
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == 1)
			return ;
		game->player.x = testx;
	}
}

void	cd_moove_left(t_game *game)
{
	float	testx;
	float	testy;

	if (game->keys.a == 1)
	{
		testx = game->player.x - game->player.planex
			* game->player.speed * game->mlx->delta_time;
		testy = game->player.y - game->player.planey
			* game->player.speed * game->mlx->delta_time;
		if (game->map.map[(int)testy][(int)game->player.x] == 1)
		{
			if (game->map.map[(int)game->player.y][(int)testx] == 1)
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == 1)
			return ;
		game->player.x = testx;
	}
}

void	cd_moove_right(t_game *game)
{
	float	testx;
	float	testy;

	if (game->keys.d == 1)
	{
		testx = game->player.x + game->player.planex
			* game->player.speed * game->mlx->delta_time;
		testy = game->player.y + game->player.planey
			* game->player.speed * game->mlx->delta_time;
		if (game->map.map[(int)testy][(int)game->player.x] == 1)
		{
			if (game->map.map[(int)game->player.y][(int)testx] == 1)
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == 1)
			return ;
		game->player.x = testx;
	}
}
