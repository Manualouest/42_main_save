/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:30:12 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 00:30:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_get_img_path(char type, t_map_info *map_info, t_x_y coord)
{
	if (type == 'C')
		return ("images/collectible/collectible.png");
	if (type == '0')
		return ("images/floor/floor.png");
	if (type == '1')
		return (sl_wall_finder_main(map_info, coord));
	return ("images/player/player_win.png");
}

void	sl_init_func_list(void **funcs)
{
	funcs[0] = sl_wall_finder;
	funcs[1] = sl_wall_finder1;
	funcs[2] = sl_wall_finder2;
	funcs[3] = sl_wall_finder3;
	funcs[4] = sl_wall_finder4;
	funcs[5] = sl_wall_finder5;
	funcs[6] = sl_wall_finder6;
	funcs[7] = sl_wall_finder7;
	funcs[8] = sl_wall_finder8;
	funcs[9] = sl_wall_finder9;
	funcs[10] = sl_wall_finder10;
	funcs[11] = sl_wall_finder11;
	funcs[12] = sl_wall_finder12;
	funcs[13] = sl_wall_finder13;
	funcs[14] = sl_wall_finder14;
	funcs[15] = sl_wall_finder15;
	funcs[16] = sl_wall_finder16;
	funcs[17] = sl_wall_finder17;
	funcs[18] = sl_wall_finder18;
	funcs[19] = sl_wall_finder19;
	funcs[20] = sl_wall_finder20;
	funcs[21] = sl_wall_finder21;
	funcs[22] = sl_wall_finder22;
	funcs[23] = sl_wall_finder23;
	funcs[24] = NULL;
}

char	*sl_wall_finder_main(t_map_info *map_info, t_x_y coord)
{
	int		i;
	char	*tp;
	void	**funcs;

	funcs = malloc(sizeof(void *) * 25);
	funcs[2] = 0;
	sl_init_func_list(funcs);
	i = -1;
	while (funcs[++i] != NULL)
	{
		tp = ((char *(*)(t_map_info *, int *, int *, int))funcs[i])
			(map_info, &coord.x, &coord.y, map_info->size.x - 1);
		if (tp != NULL)
		{
			free(funcs);
			return (tp);
		}
	}
	free(funcs);
	return ("images/player/player_win.png");
}

char	*sl_wall_finder(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && ((mp[*y][*x - 1] < 0
			&& mp[*y][*x + 1] == 49 && (*y == 0
			|| (*y > 0 && mp[*y - 1][*x] > 0))
		&& (*y == ymax || (*y < ymax && mp[*y + 1][*x] != 49)))))
	{
		map_info->map_copy[*y][*x] = -8;
		return ("images/wall/8.png");
	}
	return (NULL);
}

char	*sl_wall_finder1(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*y > 0 && *y < ymax && (*x == 0 || (*x > 0 && mp[*y][*x - 1] > 0))
		&& (*x == xmax || (*x < xmax && mp[*y][*x + 1] != 49))
		&& mp[*y + 1][*x] == 49 && mp[*y - 1][*x] < 0)
	{
		map_info->map_copy[*y][*x] = -15;
		return ("images/wall/15.png");
	}
	if (*x > 0 && *y < ymax && mp[*y][*x - 1] < 0
		&& (*x == xmax || (*x < xmax && mp[*y][*x + 1] != 49))
		&& mp[*y + 1][*x - 1] != 49 && mp[*y + 1][*x] == 49 && (*y == 0
		|| (*y > 0 && mp[*y - 1][*x] > 0)))
	{
		map_info->map_copy[*y][*x] = -11;
		return ("images/wall/11.png");
	}
	return (NULL);
}
