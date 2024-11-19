/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:20:43 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/31 16:00:54 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_jump(t_game *game)
{
	if (game->keys.space == 1
		&& !game->keys.shift)
	{
		if (game->player.jump_coeff == -1)
			game->player.jump_coeff --;
		if (game->player.jump_coeff > 0 && (int)game->player.jump_coeff % 2)
		{
			game->player.jump_coeff -= 2;
			game->player.height += game->player.jump_coeff / 1000.;
		}
		else if (game->player.jump_coeff > -51 && !((int)game->player.jump_coeff % 2))
		{
			game->player.jump_coeff -= 2;
			game->player.height += game->player.jump_coeff / 1000.;
		}
		if (game->player.height <= NORMAL_HEIGHT)
		{
			game->player.height = NORMAL_HEIGHT;
			game->player.jump_coeff = 41;
			game->keys.space = 0;
		}
	}
}

void	cd_walk(t_game *game)
{
	if (game->keys.w == 1
		&& !game->keys.shift
		&& !game->keys.space)
	{
		if (game->player.jog_coeff == -1)
			game->player.jog_coeff --;
		if (game->player.jog_coeff > 0 && (int)game->player.jog_coeff % 2)
		{
			game->player.jog_coeff -= 2;
			game->player.height += game->player.jog_coeff / 1000.;
		}
		else if (game->player.jog_coeff > -51 && !((int)game->player.jog_coeff % 2))
		{
			game->player.jog_coeff -= 2;
			game->player.height += game->player.jog_coeff / 1000.;
		}
		if (game->player.height <= NORMAL_HEIGHT)
		{
			game->player.height = NORMAL_HEIGHT;
			game->player.jog_coeff = 2;
		}
	}
}
