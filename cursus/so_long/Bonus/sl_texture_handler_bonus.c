/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:21:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 17:24:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder(t_map_info *map_info, t_x_y coord);

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
		return (sl_exit_finder(map_info));
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
	if (x > 0 && x < xmax && ((mp[y][x - 1] < 0
			&& mp[y][x + 1] == 49 && (y == 0 || (y > 0 && mp[y - 1][x] > 0))
		&& (y == ymax || (y < ymax && mp[y + 1][x] != 49)))))
	{
		map_info->map_copy[y][x] = -8;
		return ("images/wall/8.png");
	}
	return (sl_wall_finder1(map_info, x, y, xmax));
}

char	*sl_wall_finder1(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (y > 0 && y < ymax && (x == 0 || (x > 0 && mp[y][x - 1] > 0))
		&& (x == xmax || (x < xmax && mp[y][x + 1] != 49))
		&& mp[y + 1][x] == 49 && mp[y - 1][x] < 0)
	{
		map_info->map_copy[y][x] = -15;
		return ("images/wall/15.png");
	}
	if (x > 0 && y < ymax && mp[y][x - 1] < 0
		&& (x == xmax || (x < xmax && mp[y][x + 1] != 49))
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x] == 49 && (y == 0
		|| (y > 0 && mp[y - 1][x] > 0)))
	{
		map_info->map_copy[y][x] = -11;
		return ("images/wall/11.png");
	}
	return (sl_wall_finder2(map_info, x, y, xmax));
}

char	*sl_wall_finder2(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && y > 0 && (x == xmax || (x < xmax && mp[y][x + 1] != 49))
		&& (y == ymax || (y < ymax && mp[y + 1][x] != 49))
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -12;
		return ("images/wall/12.png");
	}
	if (x < xmax && y > 0 && mp[y - 1][x] < 0 && (y == ymax
		|| (y < ymax && mp[y + 1][x] != 49)) && (x == 0 || (x > 0
		&& mp[y][x - 1] > 0)) && mp[y][x + 1] == 49 && mp[y - 1][x + 1] > 0)
	{
		map_info->map_copy[y][x] = -13;
		return ("images/wall/13.png");
	}
	return (sl_wall_finder3(map_info, x, y, xmax));
}
