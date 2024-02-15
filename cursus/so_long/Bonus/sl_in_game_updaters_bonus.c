/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updaters_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/15 23:02:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

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
	sl_link_finder(stk,
		map_info->gifs->exit_frame / 4)->img->instances->enabled = 0;
	sl_link_finder(stk,
		(map_info->gifs->exit_frame / 4) + 1)->img->instances->enabled = 0;
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

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack	*tp_link;
	int			index;

	mp_inf->gifs->xy.x += way % 10;
	mp_inf->gifs->xy.y += way / 10;
	index = (mp_inf->gifs->xy.y * mp_inf->size.x) + mp_inf->gifs->xy.x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
	{
		mp_inf->c_num --;
		tp_link->img->instances->enabled = 0;
	}
	sl_change_exit(mp_inf, mp_inf->gifs->exit_type,
		mp_inf->gifs->exit.x, mp_inf->gifs->exit.y);
	if(mp_inf->c_num == 0 && mp_inf->gifs->player_type == 0)
	{
		mp_inf->gifs->player_type = 1;
		sl_link_finder(*mp_inf->gifs->nowin,
			mp_inf->gifs->player_frame / 4)->img->instances->enabled = 0;
		sl_link_finder(*mp_inf->gifs->nowin,
			(mp_inf->gifs->player_frame / 4) + 1)->img->instances->enabled = 0;
	}
	sl_update_moves(mp_inf);
	if (mp_inf->map[mp_inf->gifs->xy.y][mp_inf->gifs->xy.x] == 'E')
		sl_win_stop(mp_inf);
}
