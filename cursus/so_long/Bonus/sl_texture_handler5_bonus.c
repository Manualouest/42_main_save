/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_texture_handler5_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:51 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 11:36:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

char	*sl_wall_finder23(t_map_info *map_info, int *x, int *y, int xmax)
{
	int		ymax;
	char	**mp;

	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if (*x > 0 && *x < xmax && *y > 0 && *y < ymax && mp[*y - 1][*x] > 0
		&& mp[*y][*x + 1] != 49 && mp[*y + 1][*x] != 49 && mp[*y][*x - 1] > 0)
	{
		map_info->map_copy[*y][*x] = -47;
		return ("images/wall/47.png");
	}
	return (NULL);
}
