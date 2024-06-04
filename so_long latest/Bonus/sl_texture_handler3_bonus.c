/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:04:50 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 20:35:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder12(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -37;
		return ("images/wall/37.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -38;
		return ("images/wall/38.png");
	}
	return (NULL);
}

char	*sl_wall_finder13(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -39;
		return ("images/wall/39.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] > 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -40;
		return ("images/wall/40.png");
	}
	return (NULL);
}

char	*sl_wall_finder14(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -41;
		return ("images/wall/41.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y][*x - 1] < 0 && mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x - 1] < 0 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x - 1] == 49 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -42;
		return ("images/wall/42.png");
	}
	return (NULL);
}

char	*sl_wall_finder15(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x < xmax && *y < ymax && *y > 0 && (*x == 0 || (*x > 0
				&& mp[*y][*x - 1] > 0)) && mp[*y - 1][*x] < 0
		&& mp[*y + 1][*x] == 49 && mp[*y][*x + 1] == 49
		&& mp[*y - 1][*x + 1] < 0 && mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -21;
		return ("images/wall/21.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && (*y == ymax || (*y < ymax
				&& mp[*y + 1][*x] != 49)) && mp[*y][*x - 1] < 0
		&& mp[*y][*x + 1] == 49 && mp[*y - 1][*x] < 0 && mp[*y - 1][*x - 1] < 0
		&& mp[*y - 1][*x + 1] > 0)
	{
		map_info->map_copy[*y][*x] = -22;
		return ("images/wall/22.png");
	}
	return (NULL);
}

char	*sl_wall_finder16(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *y < ymax && *y > 0 && (*x == xmax || (*x < xmax
				&& mp[*y][*x + 1] != 49)) && mp[*y - 1][*x] < 0
		&& mp[*y + 1][*x] == 49 && mp[*y][*x - 1] < 0 && mp[*y - 1][*x - 1] > 0
		&& mp[*y + 1][*x - 1] == 49)
	{
		map_info->map_copy[*y][*x] = -23;
		return ("images/wall/23.png");
	}
	if (*x > 0 && *x < xmax && *y < ymax && (*y == 0
			|| (*y > 0 && mp[*y - 1][*x] > 0)) && mp[*y][*x - 1] < 0
		&& mp[*y][*x + 1] == 49 && mp[*y + 1][*x] == 49
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -24;
		return ("images/wall/24.png");
	}
	return (NULL);
}
