/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hive_setup_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:39:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/06 14:02:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

t_x_y	sl_get_hive_pos(t_map_info *map_info)
{
	int		x_sum;
	int		y_sum;
	t_x_y	pos;

	pos.y = 0;
	x_sum = 0;
	y_sum = 0;
	while (++pos.y < map_info->size.y)
	{
		pos.x = 0;
		while (++pos.x < map_info->size.x)
		{
			if (map_info->map[pos.y][pos.x] == 'C')
			{
				x_sum += pos.x;
				y_sum += pos.y;
			}
		}
	}
	pos.x = x_sum / map_info->c_num;
	pos.y = y_sum / map_info->c_num;
	return (pos);
}

t_x_y	sl_scanner_horizontal(t_hive *hive, t_map_info *map_info, int rad)
{
	int		i;
	int		len;
	t_x_y	pos;

	i = -1;
	len = rad * 2 + 1;
	while (++i < len)
	{
		pos.x = hive->hive_pos.x - (rad - i);
		pos.y = hive->hive_pos.y - rad;
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && map_info->map[pos.y][pos.x] == '0')
			return (pos);
		pos.x = hive->hive_pos.x - (rad - i);
		pos.y = hive->hive_pos.y + rad;
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && map_info->map[pos.y][pos.x] == '0')
			return (pos);
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_x_y	sl_scanner_vertical(t_hive *hive, t_map_info *map_info, int rad)
{
	int		i;
	int		len;
	t_x_y	pos;

	i = -1;
	len = rad * 2 + 1;
	while (++i < len)
	{
		pos.x = hive->hive_pos.x - rad;
		pos.y = hive->hive_pos.y - (rad - i);
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && map_info->map[pos.y][pos.x] == '0')
			return (pos);
		pos.x = hive->hive_pos.x + rad;
		pos.y = hive->hive_pos.y - (rad - i);
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && map_info->map[pos.y][pos.x] == '0')
			return (pos);
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

void	sl_redo_map_copy(t_map_info *map_info)
{
	int	i;
	int	ii;

	i = -1;
	ii = 0;
	map_info->map_copy = malloc(sizeof(char *) * (map_info->size.y + 1));
	map_info->map_copy[map_info->size.y] = 0;
	while (++i == 0 || (i < map_info->size.y && map_info->map[i][ii] != 0))
	{
		ii = -1;
		map_info->map_copy[i] = malloc(sizeof(char) * (map_info->size.x + 1));
		map_info->map_copy[i][map_info->size.x] = 0;
		while (++ii < map_info->size.x && map_info->map[i][ii] != 0)
			map_info->map_copy[i][ii] = map_info->map[i][ii];
		ii = 0;
	}
}

int	sl_get_bee_num(int num)
{
	if (num == 0)
		return (0);
	else if (num == 1)
		return (10);
	else if (num == 2)
		return (1);
	else
		return (11);
}
