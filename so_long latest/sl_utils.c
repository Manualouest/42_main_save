/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:12:20 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 00:46:00 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

int	sl_is_in_circle(t_map_info map_info, int rad, int ex, int ey)
{
	int			px;
	int			py;

	px = map_info.player.x;
	py = map_info.player.y;
	if (((ey - rad <= py && ey + rad >= py) && (ex - (rad / 2) <= px
				&& ex + (rad / 2) >= px)) || ((ey - (rad / 2) <= py
				&& ey + (rad / 2) >= py) && (ex - rad <= px && ex + rad >= px))
		|| ((ey - (rad - 1) <= py && ey + (rad - 1) >= py)
			&& (ex - ((rad / 2) + 1) <= px && ex + ((rad / 2) + 1) >= px))
		|| ((ey - ((rad / 2) + 1) <= py && ey + ((rad / 2) + 1) >= py)
			&& (ex - (rad - 1) <= px && ex + (rad - 1) >= px)))
		return (1);
	return (0);
}

int	sl_has_empty_lines(char *map_full)
{
	int	i;

	i = -1;
	while (map_full[++i] != 0)
		if (i > 0 && map_full[i] == '\n' && map_full[i - 1] == '\n')
			return (1);
	return (0);
}

int	check_file_type(char *map_file)
{
	int	len;

	len = gnl_len_str_n(map_file, 0, 0);
	if (map_file[len - 1] == 'r'
		&& map_file[len - 2] == 'e'
		&& map_file[len - 3] == 'b'
		&& map_file[len - 4] == '.')
		return (1);
	return (0);
}
