/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updaters_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/10 12:50:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_update_c_num(t_map_info *map_info)
{
	int			i;
	int			ii;
	int			total;
	t_img_stack	*tp_stk;

	i = -1;
	total = 0;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			tp_stk = sl_link_finder(*map_info->img_stack,
					(i * map_info->size.x) + ii);
			if (tp_stk->type == 'C' && tp_stk->img->instances->enabled == 1)
				total ++;
		}
	}
	map_info->c_num = total;
	if (map_info->c_num == 0)
	{
		sl_change_exit(map_info, map_info->exits->exit_type,
			map_info->exits->exit.x, map_info->exits->exit.y);
	}
}

void	sl_update_moves(t_map_info *map_info)
{
	if (map_info->total_moves > 0)
		write(1, "\E[H\E[2J", 7);
	map_info->total_moves ++;
	write(1, "Moves played: ", 14);
	ft_putnbr(map_info->total_moves);
	write(1, "\n", 1);
	if (map_info->c_num > 0)
	{
		write(1, "Flowers left: ", 14);
		ft_putnbr(map_info->c_num);
	}
	else
		write(1, "GO GIVE THEM NOW!", 17);
	write(1, "\n", 1);
}

void	sl_switch_exit(t_map_info *map_info, int old_type)
{
	t_img_stack	*stk;

	if (old_type == 0)
		stk = *map_info->exits->idle;
	else if (old_type == 1)
		stk = *map_info->exits->angry;
	else if (old_type == 2)
		stk = *map_info->exits->happy;
	else if (old_type == 3)
		stk = *map_info->exits->shy;
	else if (old_type == 4)
		stk = *map_info->exits->ok;
	else if (old_type == 5)
		stk = *map_info->exits->cry;
	else
		stk = *map_info->exits->sus;
	while (stk)
	{
		stk->img->instances->enabled = 0;
		stk = stk->next;
	}
}

void	sl_change_exit(t_map_info *mp_info, int old_type, int ex, int ey)
{
	if (sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 0
		&& mp_info->c_num != 0)
		mp_info->exits->exit_type = 1;
	else if (!sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 1
		&& mp_info->c_num != 0)
		mp_info->exits->exit_type = 0;
	if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type - 1 <= 0)
		mp_info->exits->exit_type = 2;
	else if (sl_is_in_circle(*mp_info, 2, ex, ey) && mp_info->c_num == 0)
		mp_info->exits->exit_type = 3;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 3)
		mp_info->exits->exit_type = 4;
	else if (!sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& old_type != 0 && old_type != 1)
		mp_info->exits->exit_type = 5;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 5)
		mp_info->exits->exit_type = 6;
	if (mp_info->exits->exit_type != old_type)
	{
		sl_switch_exit(mp_info, old_type);
	}
}

void	sl_change_player_pos(t_map_info *map_info)
{
	t_img_stack	*stk;

	stk = *map_info->players->nowin;
	while (stk)
	{
		stk->img->instances->x = map_info->players->xy.x * 42 + 16;
		stk->img->instances->y = map_info->players->xy.y * 42 + 16;
		stk = stk->next;
	}
	stk = *map_info->players->win;
	while (stk)
	{
		stk->img->instances->x = map_info->players->xy.x * 42 + 16;
		stk->img->instances->y = map_info->players->xy.y * 42 + 16;
		stk = stk->next;
	}
}

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack	*tp_link;
	int			index;

	mp_inf->players->xy.x += way % 10;
	mp_inf->players->xy.y += way / 10;
	sl_change_player_pos(mp_inf);
	index = (mp_inf->players->xy.y * mp_inf->size.x) + mp_inf->players->xy.x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
		tp_link->img->instances->enabled = 0;
	if (mp_inf->map[mp_inf->players->xy.y][mp_inf->players->xy.x] == 'E')
		index = -1;
	sl_change_exit(mp_inf, mp_inf->exits->exit_type,
		mp_inf->exits->exit.x, mp_inf->exits->exit.y);
	sl_update_c_num(mp_inf);
	sl_update_moves(mp_inf);
	if (index == -1)
		sl_win_stop(mp_inf);
}
