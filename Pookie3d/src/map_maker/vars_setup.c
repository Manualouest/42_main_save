/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/12 17:58:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	**setup_clear_map(int height, int width, int px, int py)
{
	char	**map;
	int		y;
	int		x;

	map = ft_calloc(sizeof(char *), height + 1);
	if (!map)
		return (NULL);
	map[height] = NULL;
	y = -1;
	while (++y < height)
	{
		x = -1;
		map[y] = ft_calloc(sizeof(char), width + 1);
		if (y % 2 == 0)
		{
			while (++x < width)
				map[y][x] = '1';
		}
		else
		{
			while (++x < width)
				map[y][x] = '0';
		}
	}
	map[py - 1][px - 1] = '0';
	return (map);
}

t_img_info	cd_setup_frame(t_map_editor m_edit)
{
	t_img_info	frame;

	frame.img = mlx_new_image(m_edit.mlx, m_edit.w_width, m_edit.w_height);
	return (frame);
}

t_p_vars	cd_setup_p_vars(t_map_editor m_edit)
{
	t_p_vars	p_vars;
	int		i;

	p_vars.left_gap = ((int)m_edit.w_width % 25) / 2;
	p_vars.right_gap = m_edit.w_width - p_vars.left_gap;
	p_vars.up_gap = ((int)m_edit.w_height % 25) / 2;
	p_vars.down_gap = m_edit.w_height - p_vars.up_gap;
	p_vars.nb_line = m_edit.w_height / 25;
	p_vars.nb_col = m_edit.w_width / 25;
	p_vars.offsetx = p_vars.nb_col / 2;
	p_vars.offsety = p_vars.nb_line / 2;
	p_vars.x = m_edit.origin_x;
	p_vars.y = m_edit.origin_y;
	p_vars.table_mx = ft_calloc(sizeof(int), (m_edit.w_width - p_vars.left_gap * 2.0) + 1);
	p_vars.table_my = ft_calloc(sizeof(int), (m_edit.w_height - p_vars.up_gap * 2.0) + 1);
	i = -1;
	while (++i < (m_edit.w_width - p_vars.left_gap * 2.0) + 1)
		p_vars.table_mx[i] = (int)floor((i)
				* (p_vars.nb_col / (m_edit.w_width - p_vars.left_gap * 2.0)));
	i = -1;
	while (++i < (m_edit.w_height - p_vars.up_gap * 2.0) + 1)
		p_vars.table_my[i] = (int)floor((i)
				* (p_vars.nb_line / (m_edit.w_height - p_vars.up_gap * 2.0)));
	return (p_vars);
}

t_map_info	cd_setup_map_info(t_map_editor m_edit)
{
	t_map_info	map_info;

	map_info.step = 1;
	map_info.screen = cd_setup_frame(m_edit);
	map_info.map_name = NULL;
	map_info.north = NULL;
	map_info.south = NULL;
	map_info.west = NULL;
	map_info.east = NULL;
	map_info.player_dir = 'N';
	map_info.ceiling = 0;
	map_info.floor = 0;
	return (map_info);
}
