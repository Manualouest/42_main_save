/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:29:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:31:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	player_speed_controller(t_game *game)
{
	if (game->keys.shift == 1)
		game->player.speed = CROUCH_SPEED;
	if (game->keys.ctrl == 1)
		game->player.speed = RUNNING_SPEED;
	if (game->keys.shift == 0 && game->player.speed != WALKING_SPEED
		&& game->keys.ctrl == 0)
		game->player.speed = WALKING_SPEED;
}

void	player_height_controller(t_game *game)
{
	if (game->keys.shift == 1 && !game->keys.space)
		game->player.height = CROUCH_HEIGHT;
	if (game->keys.shift == 0 && game->player.height != NORMAL_HEIGHT
		&& !game->keys.space)
		game->player.height = NORMAL_HEIGHT;
}

void	mouse_controller(t_game *game)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;

	if (!game->keys.mouse)
		return ;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(game->mlx, &x, &y);
	delta_x = x - 960;
	delta_y = y - 508;
	cd_modif_res(game, 0, 1);
	if (delta_x > 1)
		cd_right(game, ((delta_x) >> 5) + 1);
	else if (delta_x < -1)
		cd_left(game, ((delta_x) >> 5));
	if (delta_y > 1)
		cd_down(game, (-delta_y >> 3));
	else if (delta_y < -1)
		cd_up(game, -delta_y >> 3);
	if (delta_y == 0 && delta_x == 0)
		cd_modif_res(game, 1, 0);
	mlx_set_mouse_pos(game->mlx, 960, 508);
}
