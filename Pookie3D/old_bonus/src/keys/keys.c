/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:02 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/31 15:11:44 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

// Fonction qui gère les mouvements
void	cd_keys(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	cd_directions_conditions(keydata, game);
	cd_actions_conditions(keydata, game);
	cd_camera_conditions(keydata, game);
	player_speed_controller(game);
	player_height_controller(game);
}

void	cd_moove(t_game *game)
{
	cd_moove_forward(game);
	cd_moove_backward(game);
	cd_moove_left(game);
	cd_moove_right(game);
	cd_jump(game);
	cd_walk(game);
	cd_camera(game);
	mouse_controller(game);
}

void	cd_directions_conditions(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->keys.w = 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game->keys.w = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->keys.s = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game->keys.s = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->keys.a = 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		game->keys.a = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->keys.d = 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		game->keys.d = 0;
}

void	cd_actions_conditions(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		game->keys.space = 1;
	if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_PRESS
		&& game->keys.shift == 0)
		game->keys.ctrl = 1;
	if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_RELEASE)
		game->keys.ctrl = 0;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS
		&& game->keys.ctrl == 0)
		game->keys.shift = 1;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		game->keys.shift = 0;
}

void	cd_camera_conditions(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		game->keys.up = 1;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		game->keys.up = 0;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		game->keys.down = 1;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		game->keys.down = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->keys.left = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->keys.left = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->keys.right = 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->keys.right = 0;
}
