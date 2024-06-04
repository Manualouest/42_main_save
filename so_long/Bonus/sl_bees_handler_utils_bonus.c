/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bees_handler_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:10:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 19:11:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

int	sl_move_bee_on_x(t_bees *bee)
{
	if (bee->bee_pos.x == bee->target.x)
		return (0);
	if (bee->bee_pos.x < bee->target.x)
	{
		if (bee->way % 2 != 0)
		{
			sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
			->img->enabled = 0;
			bee->way --;
		}
		bee->bee_pos.x ++;
		sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
		->img->enabled = 1;
		return (1);
	}
	if (bee->way % 2 == 0)
	{
		sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
		->img->enabled = 0;
		bee->way ++;
	}
	bee->bee_pos.x --;
	sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
	->img->enabled = 1;
	return (1);
}

int	sl_move_bee_on_y(t_bees *bee)
{
	if (bee->bee_pos.y == bee->target.y)
		return (0);
	if (bee->bee_pos.y < bee->target.y)
	{
		bee->bee_pos.y ++;
		sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
		->img->enabled = 1;
		return (1);
	}
	bee->bee_pos.y --;
	sl_link_finder(*bee->img_stack, bee->way + bee->is_angry * 2)
	->img->enabled = 1;
	return (1);
}

void	sl_start_angry_mode(t_map_info *map_info, t_bees *bee)
{
	bee->is_angry = 1;
	bee->target = map_info->gifs->xy;
	bee->wait_frame = -1;
	sl_transfer_angry_mode(*map_info->hive->bees, bee);
}

void	sl_check_is_flower(t_bees *bee, t_hive *hive, t_map_info *map_info)
{
	if (map_info->map[bee->bee_pos.y][bee->bee_pos.x] == 'C')
		bee->target = hive->hive_pos;
	else
		bee->is_angry = 1;
}

void	sl_transfer_angry_mode(t_bees *bees, t_bees *angry_bee)
{
	int		ax;
	int		ay;
	int		bx;
	int		by;

	ax = angry_bee->bee_pos.x;
	ay = angry_bee->bee_pos.y;
	while (bees != NULL)
	{
		if (bees->num != angry_bee->num && bees->is_angry != 1)
		{
			bx = bees->bee_pos.x;
			by = bees->bee_pos.y;
			if (((by - 1 <= ay && by + 1 >= ay) && (bx - (1 / 2) <= ax
						&& bx + (1 / 2) >= ax)) || ((by - (1 / 2) <= ay
						&& by + (1 / 2) >= ay)
					&& (bx - 1 <= ax && bx + 1 >= ax))
				|| ((by - (1 - 1) <= ay && by + (1 - 1) >= ay)
					&& (bx - ((1 / 2) + 1) <= ax && bx + ((1 / 2) + 1) >= ax))
				|| ((by - ((1 / 2) + 1) <= ay && by + ((1 / 2) + 1) >= ay)
					&& (bx - (1 - 1) <= ax && bx + (1 - 1) >= ax)))
				bees->is_angry = 1;
		}
		bees = bees->next;
	}
}
