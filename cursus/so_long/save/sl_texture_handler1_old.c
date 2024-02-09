/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_wall_handler1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/07 14:56:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

char	*sl_wall_finder5(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;

	mp = map_info->map_copy;
	if (!(y > 0 && mp[y - 1][x] / 1 < 0) && !(x > 0 && mp[y][x - 1] / 1 < 0)
		&& (x < xmax && mp[y][x + 1] == 49) && (y < map_info->size.y - 1
		&& mp[y + 1][x] == 49 && mp[y + 2][x] == 49))
	{
		map_info->map_copy[y][x] = -9;
		return ("images/wall/9.png");
	}
	if (!(y > 0 && mp[y - 1][x] / 1 < 0) && (x > 0 && mp[y][x - 1] / 1 < 0)
		&& !(x < xmax && mp[y][x + 1] == 49) && (y < map_info->size.y - 1
		&& mp[y + 1][x] == 49 && mp[y + 2][x] == 49))
	{
		map_info->map_copy[y][x] = -14;
		return ("images/wall/14.png");
	}
	if (y == map_info->size.y - 1 && (mp[y - 1][x] / 1 > 0
		&& mp[y - 1][x] != 49))
	{
		map_info->map_copy[y][x] = -3;
		return ("images/wall/3.png");
	}
	return (sl_wall_finder6(map_info, x, y, xmax));
}

char	*sl_wall_finder6(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;

	mp = map_info->map_copy;
	if ((y > 0 && mp[y - 1][x] == -13) && (x > 0 && mp[y][x - 1] / 1 < 0)
		&& ((x < xmax && mp[y][x + 1] == 49) || x == xmax)
		&& !(y < map_info->size.y - 1 && mp[y + 1][x] == 49))
	{
		map_info->map_copy[y][x] = -7;
		return ("images/wall/7.png");
	}
	if ((y > 0 && mp[y - 1][x] == -12) && ((x > 0 && mp[y][x - 1] / 1 < 0)
		|| x == 0) && (x < xmax && mp[y][x + 1] == 49)
		&& !(y < map_info->size.y - 1 && mp[y + 1][x] == 49))
	{
		map_info->map_copy[y][x] = -1;
		return ("images/wall/1.png");
	}
	if (x < xmax && y > 0 && y < map_info->size.y - 1 && (mp[y - 1][x] == -9
		|| mp[y - 1][x] == -12 || mp[y - 1][x] == -21) && mp[y][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -12;
		return ("images/wall/12.png");
	}
	return (sl_wall_finder7(map_info, x, y, xmax));
}

char	*sl_wall_finder7(t_map_info *map_info, int x, int y, int xmax)
{
	char	**mp;

	mp = map_info->map_copy;
	if (x > 0 && y > 0 && y < map_info->size.y - 1 && (mp[y - 1][x] == -14
		|| mp[y - 1][x] == -13 || mp[y - 1][x] == -20) && mp[y][x - 1] / 1 > 0)
	{
		map_info->map_copy[y][x] = -13;
		return ("images/wall/13.png");
	}
	if (x > 0 && y > 0 && y < map_info->size.y - 1 && (mp[y - 1][x] == -14
		|| mp[y - 1][x] == -13 || mp[y - 1][x] == -20) && mp[y][x - 1] / 1 < 0)
	{
		map_info->map_copy[y][x] = -20;
		return ("images/wall/20.png");
	}
	if (x < xmax && y > 0 && y < map_info->size.y - 1 && (mp[y - 1][x] == -9
		|| mp[y - 1][x] == -12 || mp[y - 1][x] == -21) && mp[y][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -21;
		return ("images/wall/21.png");
	}
	return ("images/player/player_win.png");
}

char	*sl_get_img_path(char type, t_map_info *map_info, t_x_y coord)
{
	if (type == 'P')
	{
		if (map_info->c_num > 0)
			return ("images/player/player_unwin.png");
		else
			return ("images/player/player_win.png");
	}
	if (type == 'E')
	{
		if (map_info->c_num > 0)
			return ("images/exit/exit_unwin.png");
		else
			return ("images/exit/exit_win.png");
	}
	if (type == 'C')
		return ("images/collectible/collectible.png");
	if (type == '0')
		return ("images/floor/floor.png");
	return (sl_wall_finder(map_info, coord));
}

void	sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type)
{
	t_x_y	player_pos;

	player_pos = map_info->player;
	mlx_delete_image(map_info->mlx, stk->img);
	mlx_delete_texture(stk->texture);
	stk->texture = mlx_load_png(sl_get_img_path(type, map_info, player_pos));
	stk->img = mlx_texture_to_image(map_info->mlx, stk->texture);
	stk->type = type;
}
