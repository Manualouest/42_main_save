/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing_main_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:01 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/21 13:44:54 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

static int	sl_ct_util(t_map_info *m_inf, t_parse_util *parse_ut,
	t_x_y xy, t_x_y *pxy)
{
	t_x_y	new_xy;

	new_xy.x = 0;
	new_xy.y = 0;
	if (m_inf->map[xy.y][xy.x] == 'E')
		parse_ut->e_num += 1;
	else if (m_inf->map[xy.y][xy.x] == 'P')
	{
		parse_ut->p_num += 1;
		new_xy.x = xy.x;
		new_xy.y = xy.y;
		(*pxy) = new_xy;
	}
	else if (m_inf->map[xy.y][xy.x] == 'C')
		m_inf->c_num ++;
	else if (m_inf->map[xy.y][xy.x] != '0' && m_inf->map[xy.y][xy.x] != '1')
	{
		(*pxy) = new_xy;
		return (0);
	}
	return (1);
}

static int	sl_chk_tiles(t_map_info *m_inf, t_x_y *pxy)
{
	t_x_y			xy;
	t_parse_util	parse_util;

	parse_util.e_num = 0;
	parse_util.p_num = 0;
	m_inf->c_num = 0;
	xy.y = -1;
	while (m_inf->map[++xy.y] != 0)
	{
		xy.x = -1;
		while (m_inf->map[xy.y][++xy.x] != 0)
		{
			if ((xy.y % (m_inf->size.y - 1) == 0
					|| xy.x % (m_inf->size.x - 1) == 0)
				&& (m_inf->map[xy.y][xy.x] != '1'))
				return (2);
			if (sl_ct_util(m_inf, &parse_util, xy, pxy) != 1)
				return (3);
		}
		if (m_inf->size.x != xy.x)
			return (4);
	}
	if (parse_util.e_num != 1 || parse_util.p_num != 1 || m_inf->c_num == 0)
		return (5);
	return (1);
}

static void	sl_path_check_utils(t_map_info *map_info, int x, int y)
{
	char	**map_cpy;
	int		width;
	int		height;

	map_cpy = map_info->map_copy;
	width = map_info->size.x;
	height = map_info->size.y;
	if (map_info->map_copy[y][x] == 'E')
	{
		map_info->map_copy[y][x] = '1';
		return ;
	}
	map_info->map_copy[y][x] = '1';
	if (y > 1 && map_cpy[y - 1][x] != '1')
		sl_path_check_utils(map_info, x, y - 1);
	if (x < width - 1 && map_cpy[y][x + 1] != '1')
		sl_path_check_utils(map_info, x + 1, y);
	if (y < height - 1 && map_cpy[y + 1][x] != '1')
		sl_path_check_utils(map_info, x, y + 1);
	if (x > 1 && map_cpy[y][x - 1] != '1')
		sl_path_check_utils(map_info, x - 1, y);
}

static int	sl_path_check(t_map_info *map_info, char *original_map, t_x_y xy)
{
	int	y;
	int	x;

	y = -1;
	sl_path_check_utils(map_info, xy.x, xy.y);
	while (map_info->map_copy[++y] != 0)
	{
		x = -1;
		while (map_info->map_copy[y][++x] != 0)
		{
			if (map_info->map_copy[y][x] == 'P'
				|| map_info->map_copy[y][x] == 'C'
				|| map_info->map_copy[y][x] == 'E')
				return (0);
		}
	}
	y = -1;
	while (map_info->map_copy[++y] != 0)
		free(map_info->map_copy[y]);
	free(map_info->map_copy[y]);
	free(map_info->map_copy);
	map_info->map_copy = ft_split(original_map, '\n', &y);
	return (1);
}

int	sl_parse_main(char *map_file, t_map_info *map_info)
{
	char	*map_full;
	int		tpint;
	t_x_y	xy;

	map_full = NULL;
	sl_get_map(map_file, &map_full, &tpint);
	close(tpint);
	if (map_full == NULL)
		return (sl_parsing_error(4, map_info, &map_full, 0));
	map_info->map = ft_split(map_full, '\n', &tpint);
	map_info->map_copy = ft_split(map_full, '\n', &tpint);
	map_info->size.y = tpint;
	map_info->size.x = gnl_len_str_n(map_info->map[0], 0, 0);
	tpint = sl_chk_tiles(map_info, &xy);
	if (tpint != 1)
		return (sl_parsing_error(tpint, map_info, &map_full, 1));
	if (sl_path_check(map_info, map_full, xy) != 1)
		return (sl_parsing_error(6, map_info, &map_full, 1));
	free(map_full);
	return (1);
}
