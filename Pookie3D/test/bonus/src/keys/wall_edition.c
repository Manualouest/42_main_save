/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:33:48 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/14 12:24:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_mouse_input(mouse_key_t button, action_t action,
	modifier_key_t mods, t_game *game)
{
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS
		&& !game->keys.place)
		game->keys.destroy = 1;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS
		&& !game->keys.destroy)
		game->keys.place = 1;
}

void	cd_inventory_switch(double xdelta, double ydelta, t_game *game)
{
	t_inventory	*last_inv;

	(void)xdelta;
	if (!game->player.inventory || !game->player.inventory->next)
		return ;
	last_inv = game->player.inventory;
	if (ydelta > 0)
	{
		while (last_inv->next)
			last_inv = last_inv->next;
		last_inv->next = game->player.inventory;
		game->player.inventory = game->player.inventory->next;
		last_inv->next->next = NULL;
	}
	else if (ydelta < 0)
	{
		while (last_inv->next->next)
			last_inv = last_inv->next;
		last_inv->next->next = game->player.inventory;
		game->player.inventory = last_inv->next;
		last_inv->next = NULL;
	}
}

void	cd_place_wall(t_game *game, float x, float y, float distance)
{
	t_inventory	*tp_inv;

	if (distance > 5 * (1 - fabs(game->player.pitch)))
	{
		x = game->player.x + game->player.dirx
			* (5 * (1 - fabs(game->player.pitch)));
		y = game->player.y + game->player.diry
			* (5 * (1 - fabs(game->player.pitch)));
	}
	game->graphic.tmap[(int)y][(int)x] = game->player.inventory->tile;
	game->map.map[(int)y][(int)x] = game->player.inventory->wall_type;
	tp_inv = game->player.inventory;
	game->player.inventory = tp_inv->next;
	free(tp_inv);
}

void	cd_edit_wall(t_game *game, float x, float y)
{
	float	distance;

	distance = game->rays.distance_save;
	if (game->keys.destroy && (int)x != 0 && (int)x != game->map.width - 1
		&& (int)y != 0 && (int)y != game->map.height - 1 && distance < 5
		* (1 - fabs(game->player.pitch)))
	{
		cd_add_sprite(game, x, y);
		game->map.map[(int)y][(int)x] = 0;
	}
	if (game->keys.place && game->player.inventory
		&& !((int)x == (int)game->player.x && (int)y == (int)game->player.y))
		cd_place_wall(game, x, y, distance);
	game->keys.place = 0;
	game->keys.destroy = 0;
}
