/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_te*xture_handler3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:34:26 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 11:34:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

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
				&& mp[*y][*x - 1] > 0)) && mp[*y - 1][*x] < 0 && mp[*y + 1][*x] == 49
		&& mp[*y][*x + 1] == 49 && mp[*y - 1][*x + 1] < 0
		&& mp[*y + 1][*x + 1] != 49)
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
		&& mp[*y][*x + 1] == 49 && mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] != 49
		&& mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -24;
		return ("images/wall/24.png");
	}
	return (NULL);
}

char	*sl_wall_finder17(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x < xmax && *y > 0 && *y < ymax && (*x == 0 || (*x > 0
				&& mp[*y][*x - 1] > 0)) && mp[*y - 1][*x] < 0 && mp[*y + 1][*x] == 49
		&& mp[*y][*x + 1] == 49 && mp[*y - 1][*x + 1] > 0
		&& mp[*y + 1][*x + 1] == 49)
	{
		map_info->map_copy[*y][*x] = -25;
		return ("images/wall/25.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && (*y == ymax
			|| (*y < ymax && mp[*y + 1][*x] != 49)) && mp[*y][*x - 1] < 0
		&& mp[*y][*x + 1] == 49 && mp[*y - 1][*x] < 0 && mp[*y - 1][*x - 1] > 0
		&& mp[*y - 1][*x + 1] < 0)
	{
		map_info->map_copy[*y][*x] = -26;
		return ("images/wall/26.png");
	}
	return (NULL);
}
