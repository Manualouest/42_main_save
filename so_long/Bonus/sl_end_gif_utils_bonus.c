/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_gif_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:17:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 21:14:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_coord_changer(t_img_stack *stk)
{
	while (stk != NULL)
	{
		if (stk && stk->img && stk->img->instances)
		{
			stk->img->instances->x = -44;
			stk->img->instances->y = -44;
		}
		stk = stk->next;
	}
}

void	sl_hide_everything(t_map_info *map_info, t_bees *bees)
{
	map_info->gifs->exit.x = -44;
	map_info->gifs->xy.x = -44;
	map_info->gifs->xy.y = -400;
	map_info->hive->hive_pos.x = -44;
	sl_coord_changer(*map_info->img_stack);
	sl_coord_changer(*map_info->hive->hive_bot);
	sl_coord_changer(*map_info->hive->hive_top);
	while (bees != NULL)
	{
		sl_coord_changer(*bees->img_stack);
		bees->bee_pos.x = -400;
		bees = bees->next;
	}
	sl_coord_changer(*map_info->gifs->nowin);
	sl_coord_changer(*map_info->gifs->win);
	sl_coord_changer(*map_info->gifs->idle);
	sl_coord_changer(*map_info->gifs->shy);
	sl_coord_changer(*map_info->gifs->ok);
	sl_coord_changer(*map_info->gifs->sus);
	sl_coord_changer(*map_info->gifs->angry);
	sl_coord_changer(*map_info->gifs->happy);
	sl_coord_changer(*map_info->gifs->cry);
	sl_coord_changer(*map_info->floor);
	sl_coord_changer(*map_info->counter->counter_move);
	sl_coord_changer(*map_info->counter->counter_collect);
}

t_x_y	sl_get_rand_pos(t_map_info *map_info)
{
	t_x_y	new_pos;

	new_pos.x = random() % (map_info->mlx->width - 384);
	new_pos.y = random() % (map_info->mlx->height - 380);
	return (new_pos);
}

void	sl_redo_end_song(t_end_gif *end_gif)
{
	if (end_gif->path[11] == 'w' && end_gif->sound_frame > 0)
	{
		system("paplay --volume=23000 sounds/11.wav &");
		end_gif->sound_frame = 480;
	}
	else if (end_gif->sound_frame > 0)
	{
		system("paplay --volume=25000 sounds/10.wav &");
		end_gif->sound_frame = 210;
	}
	write(1, "\E[H\E[2J", 7);
}

int	sl_is_pos_equal(t_x_y pos1, t_x_y pos2)
{
	if (pos1.x == pos2.x && pos1.y == pos2.y)
		return (1);
	else
		return (0);
}
