/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:57:40 by malbrech          #+#    #+#             */
/*   Updated: 2024/11/17 00:07:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cd_init_player(t_map *map)
{
	t_position	player;

	player.x = -1;
	player.y = -1;
	player.view = -1;
	player.height = 0.5;
	player.pitch = 0;
	map->player = player;
}

void	cd_init_keys(t_game *game)
{
	t_keys	keys;

	keys.w = 0;
	keys.s = 0;
	keys.a = 0;
	keys.d = 0;
	keys.up = 0;
	keys.down = 0;
	keys.left = 0;
	keys.right = 0;
	game->keys = keys;
}

void	cd_init_map(t_game *game, char *map_file)
{
	t_map	map;

	map.map = NULL;
	map.path = map_file;
	map.fd = 0;
	map.height = 0;
	map.width = 0;
	map.fov = M_PI / 3.;
	cd_init_player(&map);
	game->map = map;
}

void	cd_init_rays(t_game *game)
{
	t_ray_info	rays;

	rays.x = 0;
	rays.y = 0;
	rays.t_x = 0;
	rays.angle = 0;
	rays.distance = 0;
	rays.wall_height = 0;
	rays.dx = 0;
	rays.dy = 0;
	rays.delta_dx = 0;
	rays.delta_dy = 0;
	rays.side_dx = 0;
	rays.side_dy = 0;
	rays.side = 0;
	rays.step_x = 0;
	rays.step_y = 0;
	rays.effect = 0;
	game->rays = rays;
}

t_game	cd_init_structs(char *map_file)
{
	t_game	game;

	cd_init_map(&game, map_file);
	cd_init_rays(&game);
	cd_init_graphic(&game);
	cd_init_keys(&game);
	game.mlx = NULL;
	game.screen = NULL;
	game.fps = NULL;
	return (game);
}
