/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updaters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 04:35:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

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
		sl_change_exit(map_info, map_info->exit_type,
			map_info->exit.x, map_info->exit.y);
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
		write(1, "Collectibles left: ", 19);
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
		mp_info->exit_type = 1;
	else if (!sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 1
		&& mp_info->c_num != 0)
		mp_info->exit_type = 0;
	if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type - 1 <= 0)
		mp_info->exit_type = 2;
	else if (sl_is_in_circle(*mp_info, 2, ex, ey) && mp_info->c_num == 0)
		mp_info->exit_type = 3;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 3)
		mp_info->exit_type = 4;
	else if (!sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& old_type != 0 && old_type != 1)
		mp_info->exit_type = 5;
	else if (sl_is_in_circle(*mp_info, 5, ex, ey) && mp_info->c_num == 0
		&& !sl_is_in_circle(*mp_info, 2, ex, ey) && old_type == 5)
		mp_info->exit_type = 6;
	if (mp_info->exit_type != old_type)
	{
		sl_switch_exit(mp_info, ex, ey);
	}
}

void	sl_change_player(t_map_info *map_info, int way)
{
	int	x;
	int	y;

	(void)way;
	x = map_info->player.x * 42 + 16;
	y = map_info->player.y * 42 + 16;
	sl_redo_link(*map_info->player_img, map_info, 'P');
	mlx_image_to_window(map_info->mlx, (*map_info->player_img)->img, x, y);
	map_info->c_num = -2;
}

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack	*tp_link;
	int			index;

	mp_inf->player.x += way % 10;
	mp_inf->player.y += way / 10;
	(*mp_inf->player_img)->img->instances->x = mp_inf->player.x * 42 + 16;
	(*mp_inf->player_img)->img->instances->y = mp_inf->player.y * 42 + 16;
	index = (mp_inf->player.y * mp_inf->size.x) + mp_inf->player.x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
		tp_link->img->instances->enabled = 0;
	if (tp_link->type == 'E')
		index = -1;
	sl_change_exit(mp_inf, mp_inf->exit_type, mp_inf->exit.x, mp_inf->exit.y);
	if (mp_inf->c_num == 0)
		sl_change_player(mp_inf, way);
	sl_update_c_num(mp_inf);
	sl_update_moves(mp_inf);
	if (index == -1)
		sl_win_stop(mp_inf);
}
