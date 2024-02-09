/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/08 05:14:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

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
	{
		if (map_info->exit_type == 0)
			return ("images/exit/exit_unwin.png");
		else if (map_info->exit_type == 1)
			return ("images/exit/exit_win.png");
		else if (map_info->exit_type == 2)
			return ("images/exit/exit_win_shy.png");
		else if (map_info->exit_type == 3)
			return ("images/exit/exit_win_sad.png");
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
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] != 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -39;
		return ("images/wall/39.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] > 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -40;
		return ("images/wall/40.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -41;
		return ("images/wall/41.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y][x - 1] < 0 && mp[y + 1][x] == 49 && mp[y][x + 1] == 49
		&& mp[y - 1][x - 1] < 0 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x - 1] == 49 && mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -42;
		return ("images/wall/42.png");
	}
	if (x < xmax && y < ymax && y > 0 && (x == 0 || (x > 0
				&& mp[y][x - 1] > 0)) && mp[y - 1][x] < 0 && mp[y + 1][x] == 49
		&& mp[y][x + 1] == 49 && mp[y - 1][x + 1] < 0
		&& mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -21;
		return ("images/wall/21.png");
	}
	if (x > 0 && x < xmax && y > 0 && (y == ymax || (y < ymax
				&& mp[y + 1][x] != 49)) && mp[y][x - 1] < 0
		&& mp[y][x + 1] == 49 && mp[y - 1][x] < 0 && mp[y - 1][x - 1] < 0
		&& mp[y - 1][x + 1] > 0)
	{
		map_info->map_copy[y][x] = -22;
		return ("images/wall/22.png");
	}
	if (x > 0 && y < ymax && y > 0 && (x == xmax || (x < xmax
				&& mp[y][x + 1] != 49)) && mp[y - 1][x] < 0
		&& mp[y + 1][x] == 49 && mp[y][x - 1] < 0 && mp[y - 1][x - 1] > 0
		&& mp[y + 1][x - 1] == 49)
	{
		map_info->map_copy[y][x] = -23;
		return ("images/wall/23.png");
	}
	if (x > 0 && x < xmax && y < ymax && (y == 0
			|| (y > 0 && mp[y - 1][x] > 0)) && mp[y][x - 1] < 0
		&& mp[y][x + 1] == 49 && mp[y + 1][x] == 49 && mp[y + 1][x - 1] != 49
		&& mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -24;
		return ("images/wall/24.png");
	}
	if (x < xmax && y > 0 && y < ymax && (x == 0 || (x > 0
				&& mp[y][x - 1] > 0)) && mp[y - 1][x] < 0 && mp[y + 1][x] == 49
		&& mp[y][x + 1] == 49 && mp[y - 1][x + 1] > 0
		&& mp[y + 1][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -25;
		return ("images/wall/25.png");
	}
	if (x > 0 && x < xmax && y > 0 && (y == ymax
			|| (y < ymax && mp[y + 1][x] != 49)) && mp[y][x - 1] < 0
		&& mp[y][x + 1] == 49 && mp[y - 1][x] < 0 && mp[y - 1][x - 1] > 0
		&& mp[y - 1][x + 1] < 0)
	{
		map_info->map_copy[y][x] = -26;
		return ("images/wall/26.png");
	}
	if (x > 0 && y > 0 && y < ymax && (x == xmax || (x < xmax
				&& mp[y][x + 1] != 49)) && mp[y - 1][x] < 0
		&& mp[y + 1][x] == 49 && mp[y][x - 1] < 0 && mp[y - 1][x - 1] < 0
		&& mp[y + 1][x - 1] != 49)
	{
		map_info->map_copy[y][x] = -27;
		return ("images/wall/27.png");
	}
	if (x < xmax && x > 0 && y < ymax && (y == 0 || (y > 0
				&& mp[y - 1][x] > 0)) && mp[y][x - 1] < 0 && mp[y][x + 1] == 49
		&& mp[y + 1][x] == 49 && mp[y + 1][x - 1] == 49
		&& mp[y + 1][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -28;
		return ("images/wall/28.png");
	}
	if (x > 0 && y > 0 && y < ymax && (x == xmax || (x < xmax
				&& mp[y][x + 1] != 49)) && mp[y - 1][x] < 0
		&& mp[y + 1][x] == 49 && mp[y][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -1;
		return ("images/wall/1.png");
	}
	if (x < xmax && y > 0 && y < ymax && (x == 0 || (x > 0
				&& mp[y][x - 1] > 0)) && mp[y - 1][x] < 0 && mp[y][x + 1] == 49
		&& mp[y + 1][x] == 49)
	{
		map_info->map_copy[y][x] = -2;
		return ("images/wall/2.png");
	}
	if (x > 0 && x < xmax && y > 0 && (y == ymax || (y < ymax
				&& mp[y + 1][x] != 49)) && mp [y][x - 1] < 0
		&& mp[y][x + 1] == 49 && mp[y - 1][x] < 0)
	{
		map_info->map_copy[y][x] = -9;
		return ("images/wall/9.png");
	}
	if (x > 0 && x < xmax && y < ymax && (y == 0 || (y > 0
				&& mp[y - 1][x] > 0)) && mp[y][x - 1] < 0 && mp[y][x + 1] == 49
		&& mp[y + 1][x] == 49)
	{
		map_info->map_copy[y][x] = -10;
		return ("images/wall/10.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y - 1][x + 1] < 0 && mp[y][x + 1] == 49 && mp[y + 1][x + 1] == 49
		&& mp[y + 1][x] == 49 && mp[y + 1][x - 1] != 49 && mp[y][x - 1] < 0
		&& mp[y - 1][x - 1] > 0)
	{
		map_info->map_copy[y][x] = -43;
		return ("images/wall/43.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y - 1][x + 1] > 0 && mp[y][x + 1] == 49 && mp[y + 1][x + 1] == 49
		&& mp[y + 1][x] == 49 && mp[y + 1][x - 1] == 49 && mp[y][x - 1] < 0
		&& mp[y - 1][x - 1] > 0)
	{
		map_info->map_copy[y][x] = -44;
		return ("images/wall/44.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y - 1][x + 1] > 0 && mp[y][x + 1] == 49 && mp[y + 1][x + 1] != 49
		&& mp[y + 1][x] == 49 && mp[y + 1][x - 1] == 49 && mp[y][x - 1] < 0
		&& mp[y - 1][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -45;
		return ("images/wall/45.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] < 0
		&& mp[y - 1][x + 1] < 0 && mp[y][x + 1] == 49 && mp[y + 1][x + 1] != 49
		&& mp[y + 1][x] == 49 && mp[y + 1][x - 1] != 49 && mp[y][x - 1] < 0
		&& mp[y - 1][x - 1] < 0)
	{
		map_info->map_copy[y][x] = -46;
		return ("images/wall/46.png");
	}
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] > 0
		&& mp[y][x + 1] != 49 && mp[y + 1][x] != 49 && mp[y][x - 1] > 0)
	{
		map_info->map_copy[y][x] = -47;
		return ("images/wall/47.png");
	}
	return ("images/player/player_win.png");
}
