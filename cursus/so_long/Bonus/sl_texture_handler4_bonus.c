/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler4_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:01 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 11:35:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder18(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *y > 0 && *y < ymax && (*x == xmax || (*x < xmax
				&& mp[*y][*x + 1] != 49)) && mp[*y - 1][*x] < 0
		&& mp[*y + 1][*x] == 49 && mp[*y][*x - 1] < 0 && mp[*y - 1][*x - 1] < 0
		&& mp[*y + 1][*x - 1] != 49)
	{
		map_info->map_copy[*y][*x] = -27;
		return ("images/wall/27.png");
	}
	if (*x < xmax && *x > 0 && *y < ymax && (*y == 0 || (*y > 0
				&& mp[*y - 1][*x] > 0)) && mp[*y][*x - 1] < 0 && mp[*y][*x + 1] == 49
		&& mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] == 49
		&& mp[*y + 1][*x + 1] != 49)
	{
		map_info->map_copy[*y][*x] = -28;
		return ("images/wall/28.png");
	}
	return (NULL);
}

char	*sl_wall_finder19(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *y > 0 && *y < ymax && (*x == xmax || (*x < xmax
				&& mp[*y][*x + 1] != 49)) && mp[*y - 1][*x] < 0
		&& mp[*y + 1][*x] == 49 && mp[*y][*x - 1] < 0)
	{
		map_info->map_copy[*y][*x] = -1;
		return ("images/wall/1.png");
	}
	if (*x < xmax && *y > 0 && *y < ymax && (*x == 0 || (*x > 0
				&& mp[*y][*x - 1] > 0)) && mp[*y - 1][*x] < 0 && mp[*y][*x + 1] == 49
		&& mp[*y + 1][*x] == 49)
	{
		map_info->map_copy[*y][*x] = -2;
		return ("images/wall/2.png");
	}
	return (NULL);
}

char	*sl_wall_finder20(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && (*y == ymax || (*y < ymax
				&& mp[*y + 1][*x] != 49)) && mp [*y][*x - 1] < 0
		&& mp[*y][*x + 1] == 49 && mp[*y - 1][*x] < 0)
	{
		map_info->map_copy[*y][*x] = -9;
		return ("images/wall/9.png");
	}
	if (*x > 0 && *x < xmax && *y < ymax && (*y == 0 || (*y > 0
				&& mp[*y - 1][*x] > 0)) && mp[*y][*x - 1] < 0 && mp[*y][*x + 1] == 49
		&& mp[*y + 1][*x] == 49)
	{
		map_info->map_copy[*y][*x] = -10;
		return ("images/wall/10.png");
	}
	return (NULL);
}

char	*sl_wall_finder21(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y - 1][*x + 1] < 0 && mp[*y][*x + 1] == 49 && mp[*y + 1][*x + 1] == 49
		&& mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] != 49 && mp[*y][*x - 1] < 0
		&& mp[*y - 1][*x - 1] > 0)
	{
		map_info->map_copy[*y][*x] = -43;
		return ("images/wall/43.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y - 1][*x + 1] > 0 && mp[*y][*x + 1] == 49 && mp[*y + 1][*x + 1] == 49
		&& mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] == 49 && mp[*y][*x - 1] < 0
		&& mp[*y - 1][*x - 1] > 0)
	{
		map_info->map_copy[*y][*x] = -44;
		return ("images/wall/44.png");
	}
	return (NULL);
}

char	*sl_wall_finder22(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y - 1][*x + 1] > 0 && mp[*y][*x + 1] == 49 && mp[*y + 1][*x + 1] != 49
		&& mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] == 49 && mp[*y][*x - 1] < 0
		&& mp[*y - 1][*x - 1] < 0)
	{
		map_info->map_copy[*y][*x] = -45;
		return ("images/wall/45.png");
	}
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] < 0
		&& mp[*y - 1][*x + 1] < 0 && mp[*y][*x + 1] == 49 && mp[*y + 1][*x + 1] != 49
		&& mp[*y + 1][*x] == 49 && mp[*y + 1][*x - 1] != 49 && mp[*y][*x - 1] < 0
		&& mp[*y - 1][*x - 1] < 0)
	{
		map_info->map_copy[*y][*x] = -46;
		return ("images/wall/46.png");
	}
	return (NULL);
}
