/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bees_handler_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:24:45 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 19:20:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_anime_bees_main(t_hive *hive, t_map_info *map_info)
{
	t_bees		*bee;
	t_img_stack	*stk;

	bee = *hive->bees;
	while (bee != NULL)
	{
		sl_hide_bee(bee, map_info);
		if (!sl_is_pos_equal(hive->hive_pos, bee->bee_pos))
		{
			stk = sl_link_finder(*bee->img_stack,
					bee->way + bee->is_angry * 2);
			if (++bee->bee_frame > 3)
				bee->bee_frame = 0;
			if (bee->bee_frame - 2 >= 0)
				stk->img->instances->y -= 1;
			else
				stk->img->instances->y += 1;
		}
		if (bee->is_angry == 1
			&& sl_is_pos_equal(map_info->gifs->xy, bee->bee_pos))
			sl_win_stop(map_info, 1);
		bee = bee->next;
	}
}

void	sl_move_bees_main(t_map_info *map_info, t_hive *hive)
{
	t_bees		*bee;

	bee = *hive->bees;
	while (bee != NULL)
	{
		if (bee->is_angry == 1)
			sl_start_angry_mode(map_info, bee);
		if (sl_is_pos_equal(bee->bee_pos, bee->target))
		{
			if (sl_is_pos_equal(bee->bee_pos, hive->hive_pos))
			{
				if (bee->wait_frame-- < 1 && bee->wait_frame != -1)
					bee->wait_frame = bee->bee_frame + 2;
			}
			else
				sl_check_is_flower(bee, hive, map_info);
		}
		if (bee->wait_frame <= 0)
		{
			if (sl_is_pos_equal(bee->bee_pos, hive->hive_pos))
				sl_get_bee_target(map_info, bee);
			sl_move_bee(map_info, bee);
		}
		bee = bee->next;
	}
}

void	sl_move_bee(t_map_info *map_info, t_bees *bee)
{
	int	rand;

	rand = (bee->bee_frame + bee->num * (bee->bee_pos.x + bee->bee_pos.y)) % 6;
	if ((!sl_is_pos_equal(bee->bee_pos, bee->target) && rand != 0)
		|| sl_is_pos_equal(bee->bee_pos, map_info->hive->hive_pos))
	{
		rand = -1;
		if (bee->bee_frame % 2 == 0)
			rand = sl_move_bee_on_x(bee);
		if (rand == 0)
			sl_move_bee_on_y(bee);
		else if (rand == -1)
		{
			rand = sl_move_bee_on_y(bee);
			if (rand == 0)
				sl_move_bee_on_x(bee);
		}
	}
	if (sl_is_pos_equal(bee->bee_pos, map_info->hive->hive_pos)
		&& sl_is_pos_equal(bee->target, map_info->hive->hive_pos))
		map_info->hive->flowers_brought ++;
}

void	sl_get_bee_target(t_map_info *map_info, t_bees *bee)
{
	int			i;
	int			pos;
	t_img_stack	*stk;

	i = map_info->c_num - map_info->gifs->player_frame % (map_info->c_num + 1);
	stk = *map_info->img_stack;
	pos = -1;
	while (i >= 0 && ++pos >= 0 && bee->is_angry != 1)
	{
		while (stk != NULL && stk->type != 'C')
		{
			pos ++;
			stk = stk->next;
		}
		if (stk == NULL)
		{
			pos = 0;
			stk = *map_info->img_stack;
		}
		if (stk->type == 'C')
			i --;
		stk = stk->next;
	}
	bee->target.y = pos / map_info->size.x;
	bee->target.x = pos - bee->target.y * map_info->size.x;
}

void	sl_hide_bee(t_bees *bee, t_map_info *map_info)
{
	t_img_stack	*instances;
	int			i;

	instances = *(bee->img_stack);
	i = -1;
	while (instances != NULL && ++i < 5)
	{
		if (instances->is_shown == 0)
		{
			sl_show_png(instances, map_info, bee->bee_pos);
			instances->is_shown = 1;
		}
		if (sl_is_pos_equal(map_info->hive->hive_pos, bee->bee_pos)
			|| i != bee->way + bee->is_angry * 2)
			instances->img->enabled = 0;
		else
			instances->img->enabled = 1;
		instances->img->instances->x = bee->bee_pos.x * 42 + 2 + 20
			* (bee->num / 10);
		instances->img->instances->y = bee->bee_pos.y * 42 + 2 + 20
			* (bee->num % 10);
		instances = instances->next;
	}
}
