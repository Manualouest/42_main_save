/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updaters_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 09:35:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_switch_exit(t_map_info *map_info, int old_type)
{
	t_img_stack	*stk;

	if (old_type == 0)
		stk = *map_info->gifs->idle;
	else if (old_type == 1)
		stk = *map_info->gifs->angry;
	else if (old_type == 2)
		stk = *map_info->gifs->happy;
	else if (old_type == 3)
		stk = *map_info->gifs->shy;
	else if (old_type == 4)
		stk = *map_info->gifs->ok;
	else if (old_type == 5)
		stk = *map_info->gifs->cry;
	else
		stk = *map_info->gifs->sus;
	while (stk)
	{
		if (stk->is_shown == 1)
			stk->img->instances->enabled = 0;
		stk = stk->next;
	}
	map_info->gifs->exit_frame = 0;
}

void	sl_change_exit(t_map_info *mp_info, int old_type, int ex, int ey)
{
	int	inc2;
	int	inc5;

	inc2 = sl_is_in_circle(*mp_info, 2, ex, ey);
	inc5 = sl_is_in_circle(*mp_info, 5, ex, ey);
	if (inc2 && old_type == 0 && mp_info->c_num > 0)
		mp_info->gifs->exit_type = 1;
	else if (!inc2 && old_type == 1 && mp_info->c_num > 0)
		mp_info->gifs->exit_type = 0;
	if (inc5 && mp_info->c_num <= 0 && !inc2 && old_type - 1 <= 0)
		mp_info->gifs->exit_type = 2;
	else if (inc2 && mp_info->c_num <= 0)
		mp_info->gifs->exit_type = 3;
	else if (inc5 && mp_info->c_num <= 0 && !inc2 && old_type == 3)
		mp_info->gifs->exit_type = 4;
	else if (!inc5 && mp_info->c_num <= 0 && old_type != 0 && old_type != 1)
		mp_info->gifs->exit_type = 5;
	else if (inc5 && mp_info->c_num <= 0 && !inc2 && old_type == 5)
		mp_info->gifs->exit_type = 6;
	if (mp_info->gifs->exit_type != old_type)
		sl_switch_exit(mp_info, old_type);
}

void	sl_switch_player(t_gifs *gifs)
{
	t_img_stack	*stk;

	stk = *gifs->nowin;
	gifs->player_type = 1;
	while (stk)
	{
		if (stk->is_shown == 1)
			stk->img->instances->enabled = 0;
		stk = stk->next;
	}
	gifs->player_frame = 0;
}

void	sl_update_c_num(t_map_info *map_info)
{
	int	i;
	int	ii;

	i = -1;
	map_info->c_num = 0;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			if (map_info->map[i][ii] == 'C')
				map_info->c_num ++;
		}
	}
}

void	sl_secure_player(t_map_info *map_info)
{
	t_img_stack	*stk;

	if (map_info->gifs->player_type == 0)
	{
		stk = sl_link_finder(*map_info->gifs->nowin,
				map_info->gifs->player_frame);
		if (stk->is_shown == 1)
		{
			stk->img->instances->x = map_info->gifs->xy.x * 42 + 16;
			stk->img->instances->y = map_info->gifs->xy.y * 42 + 16;
		}
	}
	else
	{
		stk = sl_link_finder(*map_info->gifs->win,
				map_info->gifs->player_frame);
		if (stk->is_shown == 1)
		{
			stk->img->instances->x = map_info->gifs->xy.x * 42 + 16;
			stk->img->instances->y = map_info->gifs->xy.y * 42 + 16;
		}
	}
}

void	sl_move_player(t_map_info *mp_inf, int way, int rep)
{
	t_img_stack	*tp_link;
	int			index;

	(void)rep;
	if (!sl_next(mp_inf, way))
		return ;
	mp_inf->gifs->xy.x += way % 10;
	mp_inf->gifs->xy.y += way / 10;
	index = (mp_inf->gifs->xy.y * mp_inf->size.x) + mp_inf->gifs->xy.x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
	{
		mp_inf->map[mp_inf->gifs->xy.y][mp_inf->gifs->xy.x] = '0';
		tp_link->img->instances->enabled = 0;
	}
	sl_update_c_num(mp_inf);
	sl_change_exit(mp_inf, mp_inf->gifs->exit_type,
		mp_inf->gifs->exit.x, mp_inf->gifs->exit.y);
	if (mp_inf->c_num == 0 && mp_inf->gifs->player_type == 0)
		sl_switch_player(mp_inf->gifs);
	sl_update_moves(mp_inf);
	if (mp_inf->map[mp_inf->gifs->xy.y][mp_inf->gifs->xy.x] == 'E')
		sl_win_stop(mp_inf);
	sl_secure_player(mp_inf);
	index = 0;
}
