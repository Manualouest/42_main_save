/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:33:12 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 17:24:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder3(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x < xmax && y < ymax && (x == 0 || (x > 0 && mp[y][x - 1] > 0))
		&& mp[y][x + 1] == 49 && mp[y + 1][x + 1] != 49 && mp[y + 1][x] == 49
		&& (y == 0 || (y > 0 && mp[y - 1][x] > 0)))
	{
		map_info->map_copy[y][x] = -14;
		return ("images/wall/14.png");
	}
	if (x < xmax && y < ymax && (x == 0 || (x > 0
				&& mp[y][x - 1] > 0)) && mp[y][x + 1] == 49
		&& mp[y + 1][x + 1] == 49 && mp[y + 1][x] == 49 && (y == 0 || (y > 0
		&& mp[y - 1][x] > 0)))
	{
		map_info->map_copy[y][x] = -3;
		return ("images/wall/3.png");
	}
	return (sl_wall_finder4(map_info, x, y, xmax));
}

char	*sl_wall_finder4(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && y < ymax && mp[y][x - 1] < 0
		&& (x == xmax || (x < xmax && mp[y][x + 1] != 49))
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x] == 49 && (y == 0
		|| (y > 0 && mp[y - 1][x] > 0)))
	{
		map_info->map_copy[y][x] = -4;
		return ("images/wall/4.png");
	}
	if (y > 0 && x > 0 && (x == xmax || (x < xmax && mp[y][x + 1] != 49))
		&& (y == ymax || (y < ymax && mp[y + 1][x] != 49)) && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y - 1][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -5;
		return ("images/wall/5.png");
	}
	return (sl_wall_finder5(map_info, x, y, xmax));
}

char	*sl_wall_finder5(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (y > 0 && x < xmax && (y == ymax || (y < ymax && mp[y + 1][x] != 49))
		&& (x == 0 || (x > 0 && mp[y][x - 1] > 0)) && mp[y - 1][x] < 0
		&& mp[y][x + 1] == 49 && mp[y - 1][x + 1] < 0)
	{
		map_info->map_copy[y][x] = -6;
		return ("images/wall/6.png");
	}
	if (x > 0 && y > 0 && y < ymax && (x == xmax || (x < xmax
				&& mp[y][x + 1] != 49)) && mp[y + 1][x] == 49
		&& mp[y + 1][x - 1] != 49 && mp[y][x - 1] < 0 && mp[y - 1][x - 1] > 0)
	{
		map_info->map_copy[y][x] = -16;
		return ("images/wall/16.png");
	}
	return (sl_wall_finder6(map_info, x, y, xmax));
}

char	*sl_wall_finder6(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && y > 0 && x < xmax && (y == ymax || (y < ymax
				&& mp[y + 1][x] != 49)) && mp[y - 1][x] < 0
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] > 0
		&& mp[y][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -17;
		return ("images/wall/17.png");
	}
	if (y > 0 && y < ymax && x < xmax && (x == 0 || (x > 0
				&& mp[y][x - 1] > 0)) && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x + 1] != 49 && mp[y][x + 1] == 49 && mp[y + 1][x] == 49
		&& (mp[y - 1][x] < 0))
	{
		map_info->map_copy[y][x] = -18;
		return ("images/wall/18.png");
	}
	return (sl_wall_finder7(map_info, x, y, xmax));
}

char	*sl_wall_finder7(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y < ymax && mp[y][x - 1] < 0
		&& mp[y][x + 1] == 49 && mp[y + 1][x] == 49 && mp[y + 1][x - 1] != 49
		&& mp[y + 1][x + 1] != 49 && (y == 0 || (y > 0
		&& mp[y - 1][x] > 0)))
	{
		map_info->map_copy[y][x] = -19;
		return ("images/wall/19.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] > 0
		&& mp[y][x - 1] > 0 && mp[y][x + 1] != 49 && mp[y + 1][x] == 49)
	{
		map_info->map_copy[y][x] = -20;
		return ("images/wall/20.png");
	}
	return (sl_wall_finder8(map_info, x, y, xmax));
}
