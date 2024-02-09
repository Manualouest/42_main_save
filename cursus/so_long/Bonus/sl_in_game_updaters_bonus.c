/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updaters_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 19:21:50 by mbirou           ###   ########.fr       */
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
		sl_change_exit(map_info, map_info->exits.exit_type,
			map_info->exits.exit.x, map_info->exits.exit.y);
		sl_change_player(map_info, 0);
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

void	sl_change_exit(t_map_info *mp_info, int old_type, int ex, int ey)
{
	if (sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 0
		&& mp_info->c_num != 0)
		mp_info->exits.exit_type = 1;
	else if (!sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 1
		&& mp_info->c_num != 0)
		mp_info->exits.exit_type = 0;
	if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type - 1 <= 0)
		mp_info->exits.exit_type = 2;
	else if (sl_is_in_circle(*mp_info, 2, ex, ey) && mp_info->c_num == 0)
		mp_info->exits.exit_type = 3;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 3)
		mp_info->exits.exit_type = 4;
	else if (!sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& old_type != 0 && old_type != 1)
		mp_info->exits.exit_type = 5;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 5)
		mp_info->exits.exit_type = 6;
	if (mp_info->exits.exit_type != old_type)
	{
		sl_switch_exit(mp_info, ex, ey);
	}
}

void	sl_change_player(t_map_info *map_info, int way)
{
	int	x;
	int	y;

	(void)way;
	x = map_info->players.xy.x * 42 + 16;
	y = map_info->players.xy.y * 42 + 16;
	sl_redo_link(*map_info->players.win, map_info, 'P');
	mlx_image_to_window(map_info->mlx, (*map_info->players.win)->img, x, y);
	map_info->c_num = -2;
}

void	sl_move_player_frames(t_map_info *map_info)
{
	int			x;
	int			y;
	t_img_stack	**tp1;
	t_img_stack	**tp2;
	
	x = map_info->players.xy.x;
	y = map_info->players.xy.y;
	tp1 = map_info->players.nowin;
	tp2 = map_info->players.win;
	while((*tp1)->next || (*tp2)->next)
	{
		(*tp1)->img->instances->x = x;
		(*tp1)->img->instances->y = y;
		(*tp2)->img->instances->x = x;
		(*tp2)->img->instances->y = y;
		if ((*tp2)->next)
			(*tp2) = (*tp2)->next;
		if ((*tp1)->next)
			(*tp1) = (*tp1)->next;
	}
	(*tp1)->img->instances->x = x;
	(*tp1)->img->instances->y = y;
	(*tp2)->img->instances->x = x;
	(*tp2)->img->instances->y = y;
}

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack	*tp_link;
	int			index;

	mp_inf->players.xy.x += way % 10;
	mp_inf->players.xy.y += way / 10;
	sl_move_player_frames(mp_inf);
	index = (mp_inf->players.xy.y * mp_inf->size.x) + mp_inf->players.xy.x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
		tp_link->img->instances->enabled = 0;
	if (tp_link->type == 'E')
		index = -1;
	sl_change_exit(mp_inf, mp_inf->exits.exit_type,
		mp_inf->exits.exit.x, mp_inf->exits.exit.y);
	if (mp_inf->c_num == 0)
		sl_change_player(mp_inf, way);
	sl_update_c_num(mp_inf);
	sl_update_moves(mp_inf);
	if (index == -1)
		sl_win_stop(mp_inf);
}
