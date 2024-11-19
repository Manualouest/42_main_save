/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:08:13 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/15 14:32:15 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_moove_forward(t_game *game)
{
	float	testx;
	float	testy;
	if (game->keys.w == 1)
	{
		testx = game->player.x + cos(game->player.view)
			* game->player.speed;
		testy = game->player.y + sin(game->player.view)
			* game->player.speed;
		if (game->map.map[(int)testy][(int)game->player.x] == '1')
		{
			if (game->map.map[(int)game->player.y][(int)testx] == '1')
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == '1')
			return ;
		game->player.x = testx;
	}
}
void	cd_moove_backward(t_game *game)
{
	float	testx;
	float	testy;
	if (game->keys.s == 1)
	{
		testx = game->player.x - cos(game->player.view)
			* game->player.speed;
		testy = game->player.y - sin(game->player.view)
			* game->player.speed;
		if (game->map.map[(int)testy][(int)game->player.x] == '1')
		{
			if (game->map.map[(int)game->player.y][(int)testx] == '1')
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == '1')
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
		testx = game->player.x - cos(game->player.view + 0.5 * M_PI)
			* game->player.speed;
		testy = game->player.y - sin(game->player.view + 0.5 * M_PI)
			* game->player.speed;
		if (game->map.map[(int)testy][(int)game->player.x] == '1')
		{
			if (game->map.map[(int)game->player.y][(int)testx] == '1')
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == '1')
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
		testx = game->player.x + cos(game->player.view + 0.5 * M_PI)
			* game->player.speed;
		testy = game->player.y + sin(game->player.view + 0.5 * M_PI)
			* game->player.speed;
		if (game->map.map[(int)testy][(int)game->player.x] == '1')
		{
			if (game->map.map[(int)game->player.y][(int)testx] == '1')
				return ;
			game->player.x = testx;
			return ;
		}
		game->player.y = testy;
		if (game->map.map[(int)game->player.y][(int)testx] == '1')
			return ;
		game->player.x = testx;
	}
}

void	cd_camera(t_game *game)
{
	if (game->keys.left == 1)
		game->player.view = cd_clamp(game->player.view - CAMERA_SPEED, 0., 2. * M_PI);
	if (game->keys.right == 1)
		game->player.view = cd_clamp(game->player.view + CAMERA_SPEED, 0., 2. * M_PI);
	if (game->keys.up == 1)
		game->player.pitch = cd_clamp_two(game->player.pitch + CAMERA_SPEED, -0.75, 0.75);
	if (game->keys.down == 1)
		game->player.pitch = cd_clamp_two(game->player.pitch - CAMERA_SPEED, -0.75, 0.75);
}
