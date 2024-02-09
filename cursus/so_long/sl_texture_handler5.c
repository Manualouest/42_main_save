/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:51 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 04:21:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

char	*sl_wall_finder23(t_map_info *map_info, int x, int y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (x > 0 && x < xmax && y > 0 && y < ymax && mp[y - 1][x] > 0
		&& mp[y][x + 1] != 49 && mp[y + 1][x] != 49 && mp[y][x - 1] > 0)
	{
		map_info->map_copy[y][x] = -47;
		return ("images/wall/47.png");
	}
	return ("images/player/player_win.png");
}

char	*sl_exit_finder(t_map_info *map_info)
{
	if (map_info->exit_type == 0)
		return ("images/exit/exit_idle.png");
	else if (map_info->exit_type == 1)
		return ("images/exit/exit_angry.png");
	else if (map_info->exit_type == 2)
		return ("images/exit/exit_happy.png");
	else if (map_info->exit_type == 3)
		return ("images/exit/exit_shy.png");
	else if (map_info->exit_type == 4)
		return ("images/exit/exit_ok.png");
	else if (map_info->exit_type == 5)
		return ("images/exit/exit_cry.png");
	return ("images/exit/exit_sus.png");
}

void	sl_switch_exit(t_map_info *map_info, int ex, int ey)
{
	sl_redo_link(sl_link_finder(*map_info->img_stack,
			(ey * map_info->size.x) + ex), map_info, 'E');
	mlx_image_to_window(map_info->mlx, sl_link_finder(*map_info->img_stack,
			(ey * map_info->size.x) + ex)->img, ex * 42 + 16, ey * 42 + 16);
}
