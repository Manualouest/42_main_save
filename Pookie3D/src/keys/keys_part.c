/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:08:13 by malbrech          #+#    #+#             */
/*   Updated: 2024/11/17 00:09:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cd_moove_forward(t_game *game)
{
	if (game->keys.w == 1)
	{
		game->map.player.x += cos(game->map.player.view) * 0.1;
		game->map.player.y += sin(game->map.player.view) * 0.1;
	}
}

void	cd_moove_backward(t_game *game)
{
	if (game->keys.s == 1)
	{
		game->map.player.x -= cos(game->map.player.view) * 0.1;
		game->map.player.y -= sin(game->map.player.view) * 0.1;
	}
}

void	cd_moove_left(t_game *game)
{
	if (game->keys.a == 1)
	{
		game->map.player.x -= cos(game->map.player.view + 0.5 * M_PI) * 0.1;
		game->map.player.y -= sin(game->map.player.view + 0.5 * M_PI) * 0.1;
	}
}

void	cd_moove_right(t_game *game)
{
	if (game->keys.d == 1)
	{
		game->map.player.x += cos(game->map.player.view + 0.5 * M_PI) * 0.1;
		game->map.player.y += sin(game->map.player.view + 0.5 * M_PI) * 0.1;
	}
}

void	cd_camera(t_game *game)
{
	if (game->keys.left == 1)
		game->map.player.view = cd_clamp(game->map.player.view - 0.03, 0.,
				2. * M_PI);
	if (game->keys.right == 1)
		game->map.player.view = cd_clamp(game->map.player.view + 0.03, 0.,
				2. * M_PI);
	if (game->keys.up == 1)
		game->map.player.pitch = cd_clamp_two(game->map.player.pitch + 0.03,
				-0.75, 0.75);
	if (game->keys.down == 1)
		game->map.player.pitch = cd_clamp_two(game->map.player.pitch - 0.03,
				-0.75, 0.75);
}
