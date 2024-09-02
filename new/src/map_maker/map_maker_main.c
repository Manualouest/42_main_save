/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 00:18:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	**setup_clear_map(void)
{
	char	**map;

	map = ft_calloc(sizeof(char), 4);
	map[0] = ft_calloc(sizeof(char), 4);
	map[1] = ft_calloc(sizeof(char), 4);
	map[2] = ft_calloc(sizeof(char), 4);
	map[0] = ft_strdup("111");
	map[1] = ft_strdup("101");
	map[2] = ft_strdup("111");
	return (map);
}

t_keys	cd_setup_keys(void)
{
	t_keys	keys;

	keys.up = 0;
	keys.down = 0;
	keys.left = 0;
	keys.right = 0;
	keys.remove = 0;
	keys.place = 0;
	keys.teleport = 0;
	keys.stopper = 0;
	return (keys);
}

t_img_info	cd_setup_frame(t_map_editor m_edit)
{
	t_img_info	frame;

	frame.img = mlx_new_image(m_edit.mlx, m_edit.w_width, m_edit.w_height);
	frame.bpp = 0;
	frame.line_size = 0;
	frame.endian = 0;
	frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_size,
		&frame.endian);
	frame.width = m_edit.w_width;
	frame.height = m_edit.w_height;
}

char	*cd_map_maker(void)
{
	t_map_editor	m_edit;
	t_keys			keys;
	t_img_info		frame;

	m_edit.w_width = 1280;
	m_edit.w_height = 720;
	m_edit.m_width = 3;
	m_edit.m_height = 3;
	m_edit.map = setup_clear_map();
	mlx_init(m_edit.mlx);
	mlx_new_window(m_edit.mlx, m_edit.w_width, m_edit.w_height, "Map Editor");
	keys = cd_setup_keys();
	frame = cd_setup_frame(m_edit);
	m_edit.keys = &keys;
	m_edit.frame = &frame;
}
