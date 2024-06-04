/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_counter_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:00:45 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 02:36:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_redo_itoa(char **var, int num
	, int is_redo, int is_free_only)
{
	if (is_redo || is_free_only)
		free(*var);
	if (!is_free_only)
		*var = ft_itoa(num);
}

int	sl_num_len(int num)
{
	char	*itoa;
	int		len;

	itoa = NULL;
	sl_redo_itoa(&itoa, num, 0, 0);
	len = gnl_len_str_n(itoa, 0, 0);
	sl_redo_itoa(&itoa, num, 0, 1);
	return (len);
}

void	sl_update_moves(t_map_info *map_inf)
{
	if (map_inf->total_moves >= -1)
		map_inf->total_moves ++;
	if (map_inf->total_moves > 1953124 || map_inf->total_moves < 0)
		map_inf->counter->move = 444444444;
	else
		map_inf->counter->move = sl_base_change(map_inf->total_moves, "01234");
	map_inf->counter->collect = sl_base_change(map_inf->c_num, "01234");
	if (sl_num_len(map_inf->counter->collect) > map_inf->size.x * 2 - 1)
	{
		map_inf->counter->collect = 4;
		while (sl_num_len(map_inf->counter->collect) < map_inf->size.x * 2 - 1)
			map_inf->counter->collect = map_inf->counter->collect * 10 + 4;
	}
	if (sl_num_len(map_inf->counter->move)
		> (map_inf->size.x * 2 - sl_num_len(sl_base_change(
					map_inf->c_num, "01234"))) - 1)
	{
		map_inf->counter->move = 4;
		while (sl_num_len(map_inf->counter->move) < map_inf->size.x * 2
			- sl_num_len(sl_base_change(map_inf->c_num, "01234")) - 1
			&& map_inf->counter->move < 21474836)
			map_inf->counter->move = map_inf->counter->move * 10 + 4;
	}
	sl_redo_counter_collect(map_inf, sl_base_change(map_inf->c_num, "01234"));
	sl_redo_counter_move(map_inf, map_inf->counter->move);
}

void	sl_redo_counter_collect(t_map_info *map_info, int new_set)
{
	t_x_y	xy;
	int		i;
	char	*itoa;

	xy.x = (map_info->size.x - 1) * 42 + 16;
	xy.y = (map_info->size.y - 1) * 42 + 16;
	i = -1;
	itoa = NULL;
	sl_redo_itoa(&itoa, new_set, 0, 0);
	sl_lstclear(map_info->mlx, map_info->counter->counter_collect);
	while (++i < gnl_len_str_n(itoa, 0, 0))
	{
		sl_instant_add_png(map_info, map_info->counter->counter_collect,
			COUNTER_COLLECT, itoa[i] - '0');
		mlx_image_to_window(map_info->mlx, ft_lstlast
			(*map_info->counter->counter_collect)->img, xy.x, xy.y);
		ft_lstlast(*map_info->counter->counter_collect)->is_shown = 1;
		xy.x -= 42;
		if (xy.x == 16)
		{
			xy.x = (map_info->size.x - 1) * 42 + 16;
			xy.y = 16;
		}
	}
	sl_redo_itoa(&itoa, new_set, 0, 1);
}

void	sl_redo_counter_move(t_map_info *map_info, int new_set)
{
	t_x_y	xy;
	int		i;
	char	*itoa;

	xy.x = 16;
	xy.y = 16;
	i = -1;
	itoa = NULL;
	sl_redo_itoa(&itoa, new_set, 0, 0);
	sl_lstclear(map_info->mlx, map_info->counter->counter_move);
	while (++i < gnl_len_str_n(itoa, 0, 0))
	{
		sl_instant_add_png(map_info, map_info->counter->counter_move,
			COUNTER_MOVE, itoa[i] - '0');
		mlx_image_to_window(map_info->mlx, ft_lstlast
			(*map_info->counter->counter_move)->img, xy.x, xy.y);
		ft_lstlast(*map_info->counter->counter_move)->is_shown = 1;
		xy.x += 42;
		if ((xy.x - 16) / 42 == map_info->size.x)
		{
			xy.x = 16;
			xy.y = (map_info->size.y - 1) * 42 + 16;
		}
	}
	sl_redo_itoa(&itoa, new_set, 0, 1);
}
