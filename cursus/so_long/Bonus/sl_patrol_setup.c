/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_patrol_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:48:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/02 23:02:43 by mbirou           ###   ########.fr       */
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

void	sl_place_hive(t_hive *hive, t_map_info *map_info)
{
	int		rad;
	t_x_y	pos;

	rad = 0;
	while (++rad < (hive->size.x + hive->size.y)
		&& map_info->map[hive->hive_pos.y][hive->hive_pos.x] != '0')
	{
		pos = sl_scanner_vertical(hive, map_info, rad);
		if (pos.x != 0 && pos.y != 0)
			break ;
		pos = sl_scanner_horizontal(hive, map_info, rad);
		if (pos.x != 0 && pos.y != 0)
			break ;
	}
	if (map_info->map[hive->hive_pos.y][hive->hive_pos.x] != '0' && pos.x != 0)
	{
		map_info->map[pos.y][pos.x] = 'H';
		map_info->map_copy[pos.y][pos.x] = 'H';
	}
	else if (map_info->map[hive->hive_pos.y][hive->hive_pos.x] == '0')
	{
		map_info->map[hive->hive_pos.y][hive->hive_pos.x] = 'H';
		map_info->map_copy[hive->hive_pos.y][hive->hive_pos.x] = 'H';
	}
}

void	sl_hive_init(t_map_info *map_info, t_hive *hive)
{
	if (map_info->c_num <= 8)
		hive->bee_count = (int)((float)map_info->c_num / 2 + 0.5);
	else
		hive->bee_count = 4;
	hive->hive_pos = sl_get_hive_pos(map_info);
	hive->size = map_info->size;
	sl_place_hive(hive, map_info);
	map_info->hive = hive;
}
