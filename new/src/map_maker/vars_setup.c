/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/09 16:12:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	**setup_clear_map(void)
{
	char	**map;

	map = ft_calloc(sizeof(char *), 4);
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

	frame.img = mlx_new_image(m_edit.mlx, m_edit.w_width,
		m_edit.w_height);
	frame.bpp = 0;
	frame.line_size = 0;
	frame.endian = 0;
	frame.width = m_edit.w_width;
	frame.height = m_edit.w_height;
	return (frame);
}

t_p_vars	cd_setup_p_vars(t_map_editor m_edit)
{
	t_p_vars	p_vars;
	int			i;

	p_vars.left_gap = ((int)m_edit.w_width % 25) / 2;
	p_vars.right_gap = m_edit.w_width - p_vars.left_gap;
	p_vars.up_gap = ((int)m_edit.w_height % 25) / 2;
	p_vars.down_gap = m_edit.w_height - p_vars.up_gap;
	p_vars.nb_line = m_edit.w_width / 25;
	p_vars.nb_row = m_edit.w_height / 25;
	p_vars.offsetx = p_vars.nb_line / 2;
	p_vars.offsety = p_vars.nb_row / 2;
	p_vars.x = &(int){1};
	p_vars.y = &(int){1};
	p_vars.table_mx = ft_calloc(sizeof(int), m_edit.w_width);
	p_vars.table_my = ft_calloc(sizeof(int), m_edit.w_height);
	i = -1;
	while (++i < m_edit.w_width)
		p_vars.table_mx[i] = (i - p_vars.left_gap)\
			/ ((m_edit.w_width - p_vars.left_gap * 2) / p_vars.nb_line);	
	i = -1;
	while (++i < m_edit.w_height)
		p_vars.table_my[i] = (i - p_vars.up_gap)\
			/ ((m_edit.w_height - p_vars.up_gap * 2) / p_vars.nb_row);
	return(p_vars);
}
