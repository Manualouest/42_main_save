/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_wall_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:51:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/07 14:57:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

// 1; E_N_in
// 2; E_N_out
// 3; O_E_bot
// 4; OE_N
// 5; OE_S
// 6; O_E_top
// 7; O_N_in
// 8; O_N_out
// 9; S_E_in
// 10;S_E_out
// 11;S_N_center
// 12;S_N_left
// 13;S_N_right
// 14;S_O_in
// 15;S_O_out
// 16;O_S_C
// 17;E_S_C
// 18;E_N_C
// 19;O_N_C
// 20;S_N_right+push
// 21;S_N_left+push
// 22;S_N_center_stop

static char	*sl_wall_finder1(t_map_info *map_info, int x, int y, int xmax);
static char	*sl_wall_finder2(t_map_info *map_info, int x, int y, int xmax);
static char	*sl_wall_finder3(t_map_info *map_info, int x, int y, int xmax);
static char	*sl_wall_finder4(t_map_info *map_info, int x, int y, int xmax);

char	*sl_wall_finder(t_map_info *map_info, t_x_y coord)
{
	int		x;
	int		y;
	int		xmax;
	int		ymax;
	char	**mp;

	x = coord.x;
	y = coord.y;
	xmax = map_info->size.x - 1;
	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if ((y > 0 && y < ymax && (mp[y - 1][x] / 1 > 0 || mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17))
		&& (x > 0 && mp[y][x - 1] / 1 > 0) && (x < xmax && mp[y][x + 1] != 49)
		&& mp[y + 1][x] == 49)
	{
		map_info->map_copy[y][x] = -11;
		return ("images/wall/11.png");
	}
	return (sl_wall_finder1(map_info, x, y, xmax));
}

static char	*sl_wall_finder1(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;
	int		ymax;

	mp = map_info->map_copy;
	ymax = map_info->size.y - 1;
	if ((y > 0 && (mp[y - 1][x] / 1 > 0 || mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17))
		&& (x > 0 && mp[y][x - 1] / 1 > 0) && (x < xmax && mp[y][x + 1] != 49)
		&& mp[y + 1][x] != 49)
	{
		map_info->map_copy[y][x] = -22;
		return ("images/wall/22.png");
	}
	if (x > 0 && x < xmax && y < ymax && ((mp[y][x - 1] / 1 < 0
			&& mp[y + 1][x] == 49 && mp[y][x + 1] == 49)))
	{
		map_info->map_copy[y][x] = -5;
		return ("images/wall/5.png");
	}
	return (sl_wall_finder2(map_info, x, y, xmax));
}

static char	*sl_wall_finder2(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;
	int		ymax;

	mp = map_info->map_copy;
	ymax = map_info->size.y - 1;
	if ((x > 0 && x < xmax && y < ymax && y > 0 && ((mp[y][x - 1] == -6
				&& mp[y + 1][x] != 49 && mp[y - 1][x] != -16
		&& mp[y - 1][x] != -17 && mp[y - 1][x] != -5) || (mp[y + 1][x] != 49
		&& mp[y - 1][x] != 49 && ((mp[y][x - 1] / 1 < 0 && mp[y][x + 1] == 49)
		|| ((mp[y][x - 1] / 1 > 0 && mp[y][x + 1] != 49))))))
		|| (y == 0 && mp[y + 1][x] != 49))
	{
		map_info->map_copy[y][x] = -6;
		return ("images/wall/6.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < ymax && (((mp[y - 1][x] == -17
				|| mp[y - 1][x] == -16 || mp[y - 1][x] == -5)
		&& mp[y][x + 1] == 49 && mp[y][x - 1] / 1 > 0 && mp[y + 1][x] != 49)
		|| (mp[y - 1][x] / 1 > 0 && mp[y][x - 1] / 1 > 0 && mp[y + 1][x] != 49
		&& mp[y][x + 1] == 49)))
	{
		map_info->map_copy[y][x] = -18;
		return ("images/wall/18.png");
	}
	return (sl_wall_finder3(map_info, x, y, xmax));
}

static char	*sl_wall_finder3(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;

	mp = map_info->map_copy;
	if (y > 0 && x > 0 && x < xmax && y < map_info->size.y - 1
		&& (((mp[y - 1][x] == -16 || mp[y - 1][x] == -17 || mp[y - 1][x] == -5)
		&& mp[y][x - 1] / 1 < 0 && mp[y][x + 1] != 49 && mp[y + 1][x] != 49)
		|| (mp[y - 1][x] / 1 > 0 && mp[y][x - 1] / 1 < 0 && mp[y + 1][x] != 49
		&& mp[y][x + 1] != 49)))
	{
		map_info->map_copy[y][x] = -19;
		return ("images/wall/19.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < map_info->size.y - 1
		&& (((mp[y - 1][x] == -11 || mp[y - 1][x] == -5 || mp[y - 1][x] == -6
		|| mp[y - 1][x] == -17) && mp[y][x - 1] / 1 < 0 && mp[y + 1][x] == 49
		&& (mp[y][x + 1] != 49)) || (mp[y + 1][x] == 49 && mp[y + 1][x] == 49
		&& mp[y][x + 1] != 49)))
	{
		map_info->map_copy[y][x] = -16;
		return ("images/wall/16.png");
	}
	return (sl_wall_finder4(map_info, x, y, xmax));
}

static char	*sl_wall_finder4(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;

	mp = map_info->map_copy;
	if (y > 0 && x > 0 && x < xmax && y < map_info->size.y - 1
		&& (((mp[y - 1][x] == -11 || mp[y - 1][x] == -5 || mp[y - 1][x] == -16)
		&& !(mp[y][x - 1] / 1 < 0) && mp[y][x + 1] == 49 && mp[y + 1][x] == 49)
		|| (mp[y + 1][x] == 49 && mp[y + 1][x] == 49 && mp[y][x - 1] != -17)))
	{
		map_info->map_copy[y][x] = -17;
		return ("images/wall/17.png");
	}
	if (y > 0 && x > 0 && x < xmax && (mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17)
		&& (mp[y][x - 1] == -3 || mp[y][x - 1] == -1 || mp[y][x - 1] == -7
		|| mp[y][x - 1] == -4) && (mp[y][x + 1] == 49))
	{
		map_info->map_copy[y][x] = -4;
		return ("images/wall/4.png");
	}
	return (sl_wall_finder5(map_info, x, y, xmax));
}
