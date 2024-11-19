/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:35:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/14 18:42:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_add_sprite(t_game *game, float x, float y)
{
	int			i;
	t_sprite	**n_list;

	i = -1;
	while (game->graphic.sprites[++i])
		;
	n_list = malloc(sizeof(*n_list) * (i + 2));
	n_list[i + 1] = NULL;
	i = -1;
	while (game->graphic.sprites[++i])
		n_list[i] = game->graphic.sprites[i];
	n_list[i] = malloc(sizeof(*n_list[i]));
	n_list[i]->x = (int)x + 0.5;
	n_list[i]->y = (int)y + 0.5;
	n_list[i]->tile = game->graphic.tmap[(int)y][(int)x];
	n_list[i]->txt = game->graphic.txts[n_list[i]->tile];
	n_list[i]->wall_type = game->map.map[(int)y][(int)x];
	n_list[i]->height = 0;
	n_list[i]->direction = 1;
	free(game->graphic.sprites);
	game->graphic.sprites = n_list;
}

void	cd_remove_sprite(t_game *game, int target_i)
{
	int					i;
	struct t_inventory	*n_inv;
	t_sprite			*tp_sprite;

	i = -1;
	while (game->graphic.sprites[++i] && i != target_i)
		;
	n_inv = malloc(sizeof(*n_inv));
	n_inv->tile = game->graphic.sprites[i]->tile;
	n_inv->wall_type = game->graphic.sprites[i]->wall_type;
	tp_sprite = game->graphic.sprites[i];
	if (!game->player.inventory)
		n_inv->next = NULL;
	else
		n_inv->next = game->player.inventory;
	game->player.inventory = n_inv;
	i --;
	while (game->graphic.sprites[++i])
		game->graphic.sprites[i] = game->graphic.sprites[i + 1];
	free(tp_sprite);
}
