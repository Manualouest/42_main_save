/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:01 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/02 15:32:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

static int	sl_ct_util(t_map_info *m_inf, t_parse_util *parse_ut, int x, int y)
{
	if (m_inf->map[y][x] == 'E')
		parse_ut->e_num += 1;
	else if (m_inf->map[y][x] == 'P')
	{
		parse_ut->p_num += 1;
		m_inf->player.x = x;
		m_inf->player.y = y;
	}
	else if (m_inf->map[y][x] == 'C')
		m_inf->c_num ++;
	else if (m_inf->map[y][x] != '0' && m_inf->map[y][x] != '1')
		return (0);
	return (1);
}

static int	sl_chk_tiles(t_map_info *m_inf)
{
	int				i;
	int				ii;
	t_parse_util	parse_util;

	parse_util.e_num = 0;
	parse_util.p_num = 0;
	m_inf->c_num = 0;
	i = -1;
	while (m_inf->map[++i] != 0)
	{
		ii = -1;
		while (m_inf->map[i][++ii] != 0)
		{
			if ((i % (m_inf->size.y - 1) == 0 || ii % (m_inf->size.x - 1) == 0)
				&& (m_inf->map[i][ii] != '1'))
				return (2);
			if (sl_ct_util(m_inf, &parse_util, ii, i) != 1)
				return (3);
		}
		if (m_inf->size.x != ii)
			return (4);
	}
	if (parse_util.e_num != 1 || parse_util.p_num != 1 || m_inf->c_num == 0)
		return (5);
	return (1);
}

static void	sl_path_check_utils(t_map_info *map_info, int x, int y)
{
	map_info->map_copy[y][x] = '1';
	if (y > 0 && map_info->map_copy[y - 1][x] != '1')
		sl_path_check_utils(map_info, x, y - 1);
	if (x < map_info->size.x - 1 && map_info->map_copy[y][x + 1] != '1')
		sl_path_check_utils(map_info, x + 1, y);
	if (y < map_info->size.y - 1 && map_info->map_copy[y + 1][x] != '1')
		sl_path_check_utils(map_info, x, y + 1);
	if (x > 0 && map_info->map_copy[y][x - 1] != '1')
		sl_path_check_utils(map_info, x - 1, y);
	return ;
}

static int	sl_path_check(t_map_info *map_info, char *original_map)
{
	int	y;
	int	x;

	y = -1;
	sl_path_check_utils(map_info, map_info->player.x, map_info->player.x);
	while (map_info->map_copy[++y] != 0)
	{
		x = -1;
		while (map_info->map_copy[y][++x] != 0)
		{
			if (map_info->map_copy[y][x] == 'E'
				|| map_info->map_copy[y][x] == 'P'
				|| map_info->map_copy[y][x] == 'C')
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

	map_full = NULL;
	sl_get_map(map_file, &map_full, &tpint);
	close(tpint);
	if (map_full == NULL)
		return (sl_parsing_error(4, map_info, &map_full, 0));
	map_info->map = ft_split(map_full, '\n', &tpint);
	map_info->map_copy = ft_split(map_full, '\n', &tpint);
	map_info->size.y = tpint;
	map_info->size.x = gnl_len_str_n(map_info->map[0], 0, 0);
	tpint = sl_chk_tiles(map_info);
	if (tpint != 1)
		return (sl_parsing_error(tpint, map_info, &map_full, 1));
	if (sl_path_check(map_info, map_full) != 1)
		return (sl_parsing_error(6, map_info, &map_full, 1));
	free(map_full);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_map_info	map_info;
// 	int			pars_test;

// 	(void)argc;
// 	pars_test = sl_parse_main(argv[1], &map_info);
// 	if (pars_test == 1)
// 		free_t_map_info(&map_info);
// 	return (0);
// }
