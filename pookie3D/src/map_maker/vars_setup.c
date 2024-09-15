/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 00:51:02 by mbirou           ###   ########.fr       */
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

t_img_info	cd_setup_frame(t_map_editor m_edit, int width, int height)
{
	t_img_info	frame;

	frame.img = mlx_new_image(m_edit.mlx, width, height);
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

t_map_info	cd_setup_m_info(t_map_editor m_edit)
{
	t_map_info	m_info;

	m_info.step = 1;
	m_info.try_step = 0;
	m_info.screen = cd_setup_frame(m_edit, 1, 1);
	m_info.text = NULL;
	mlx_put_pixel(m_info.screen.img, 0, 0, 0x2F2F2FFF);
	mlx_resize_image(m_info.screen.img, m_edit.w_width, m_edit.w_height);
	m_info.map_name = NULL;
	m_info.north = NULL;
	m_info.south = NULL;
	m_info.west = NULL;
	m_info.east = NULL;
	m_info.ceiling = NULL;
	m_info.floor = NULL;
	m_info.map_size = NULL;
	m_info.player = NULL;
	m_info.input = ft_calloc(sizeof(char), 1);
	m_info.player_dir = 'N';
	return (m_info);
}
