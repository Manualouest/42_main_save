/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_counter_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:00:45 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 09:33:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_redo_counter_collect(t_map_info *map_info, int new_set);
void	sl_redo_counter_move(t_map_info *map_info, int new_set);

void	sl_update_moves(t_map_info *map_inf)
{
	map_inf->total_moves ++;
	map_inf->counter->move = sl_base_change(map_inf->total_moves, "01234");
	map_inf->counter->collect = sl_base_change(map_inf->c_num, "01234");
	if (gnl_len_str_n(ft_itoa(map_inf->counter->collect), 0, 0)
		> map_inf->size.x * 2 - 1)
	{
		map_inf->counter->collect = 4;
		while (gnl_len_str_n(ft_itoa(map_inf->counter->collect), 0, 0)
			< map_inf->size.x * 2 - 1)
			map_inf->counter->collect = map_inf->counter->collect * 10 + 4;
	}
	if (gnl_len_str_n(ft_itoa(map_inf->counter->move), 0, 0)
		> (map_inf->size.x * 2 - gnl_len_str_n(ft_itoa(sl_base_change
					(map_inf->c_num, "01234")), 0, 0)) - 1)
	{
		map_inf->counter->move = 4;
		while (gnl_len_str_n(ft_itoa(map_inf->counter->move), 0, 0)
			< map_inf->size.x * 2 - gnl_len_str_n(ft_itoa(sl_base_change
					(map_inf->c_num, "01234")), 0, 0) - 1)
			map_inf->counter->move = map_inf->counter->move * 10 + 4;
	}
	sl_redo_counter_collect(map_inf, sl_base_change(map_inf->c_num, "01234"));
	sl_redo_counter_move(map_inf, map_inf->counter->move);
}

void	sl_redo_counter_collect(t_map_info *map_info, int new_set)
{
	int	x;
	int	y;
	int	i;

	x = (map_info->size.x - 1) * 42 + 16;
	y = (map_info->size.y - 1) * 42 + 16;
	i = 0;
	sl_lstclear(map_info->mlx, map_info->counter->counter_collect);
	while (i < gnl_len_str_n(ft_itoa(new_set), 0, 0))
	{
		sl_instant_add_png(map_info, map_info->counter->counter_collect,
			COUNTER_COLLECT, (ft_itoa(new_set)[i]) - '0');
		mlx_image_to_window(map_info->mlx, ft_lstlast
			(*map_info->counter->counter_collect)->img, x, y);
		ft_lstlast(*map_info->counter->counter_collect)->is_shown = 1;
		x -= 42;
		if (x == 16)
		{
			x = (map_info->size.x - 1) * 42 + 16;
			y = 16;
		}
		i ++;
	}
}

void	sl_redo_counter_move(t_map_info *map_info, int new_set)
{
	int	x;
	int	y;
	int	i;

	x = 16;
	y = 16;
	i = 0;
	sl_lstclear(map_info->mlx, map_info->counter->counter_move);
	while (i < gnl_len_str_n(ft_itoa(new_set), 0, 0))
	{
		sl_instant_add_png(map_info, map_info->counter->counter_move,
			COUNTER_MOVE, (ft_itoa(new_set)[i]) - '0');
		mlx_image_to_window(map_info->mlx, ft_lstlast
			(*map_info->counter->counter_move)->img, x, y);
		ft_lstlast(*map_info->counter->counter_move)->is_shown = 1;
		x += 42;
		if ((x - 16) / 42 == map_info->size.x)
		{
			x = 16;
			y = (map_info->size.y - 1) * 42 + 16;
		}
		i ++;
	}
}
