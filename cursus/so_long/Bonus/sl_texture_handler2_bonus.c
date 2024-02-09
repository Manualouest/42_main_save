/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:33:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 17:24:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder8(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] > 0
		&& mp[y][x - 1] < 0 && mp[y][x + 1] != 49 && mp[y + 1][x] != 49)
	{
		map_info->map_copy[y][x] = -29;
		return ("images/wall/29.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] > 0 && mp[y][x + 1] != 49 && mp[y + 1][x] != 49)
	{
		map_info->map_copy[y][x] = -30;
		return ("images/wall/30.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] > 0
		&& mp[y][x - 1] > 0 && mp[y][x + 1] == 49 && mp[y + 1][x] != 49)
	{
		map_info->map_copy[y][x] = -31;
		return ("images/wall/31.png");
	}
	return (sl_wall_finder9(map_info, x, y, xmax));
}

char	*sl_wall_finder9(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -7;
		return ("images/wall/7.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -32;
		return ("images/wall/32.png");
	}
	return (sl_wall_finder10(map_info, x, y, xmax));
}

char	*sl_wall_finder10(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -33;
		return ("images/wall/33.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -34;
		return ("images/wall/34.png");
	}
	return (sl_wall_finder11(map_info, x, y, xmax));
}

char	*sl_wall_finder11(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -35;
		return ("images/wall/35.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -36;
		return ("images/wall/36.png");
	}
	return (sl_wall_finder12(map_info, x, y, xmax));
}

char	*sl_wall_finder12(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -37;
		return ("images/wall/37.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -38;
		return ("images/wall/38.png");
	}
	return (sl_wall_finder13(map_info, x, y, xmax));
}
