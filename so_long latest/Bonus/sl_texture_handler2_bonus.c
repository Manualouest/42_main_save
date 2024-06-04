/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:33:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 20:34:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder7(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y < ymax && mp[*y][*x - 1] < 0
		&& mp[*y][*x + 1] == 49 && mp[*y + 1][*x] == 49
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] != 49
		&& (*y == 0 || (*y > 0 && mp[*y - 1][*x] > 0)))
	{
		map_info->map_copy[*y][*x] = -19;
		return ("images/wall/19.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] > 0
		&& mp[*y][*x - 1] > 0 && mp[*y][*x + 1] != 49 && mp[*y + 1][*x] == 49)
	{
		map_info->map_copy[*y][*x] = -20;
		return ("images/wall/20.png");
	}
	return (NULL);
}

char	*sl_wall_finder8(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] > 0
		&& mp[*y][*x - 1] < 0 && mp[*y][*x + 1] != 49 && mp[*y + 1][*x] != 49)
	{
		map_info->map_copy[*y][*x] = -29;
		return ("images/wall/29.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] > 0 && mp[*y][*x + 1] != 49 && mp[*y + 1][*x] != 49)
	{
		map_info->map_copy[*y][*x] = -30;
		return ("images/wall/30.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] > 0
		&& mp[*y][*x - 1] > 0 && mp[*y][*x + 1] == 49 && mp[*y + 1][*x] != 49)
	{
		map_info->map_copy[*y][*x] = -31;
		return ("images/wall/31.png");
	}
	return (NULL);
}

char	*sl_wall_finder9(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -7;
		return ("images/wall/7.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -32;
		return ("images/wall/32.png");
	}
	return (NULL);
}

char	*sl_wall_finder10(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -33;
		return ("images/wall/33.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -34;
		return ("images/wall/34.png");
	}
	return (NULL);
}

char	*sl_wall_finder11(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -35;
		return ("images/wall/35.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -36;
		return ("images/wall/36.png");
	}
	return (NULL);
}
