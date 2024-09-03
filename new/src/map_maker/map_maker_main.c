/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 20:09:24 by mbirou           ###   ########.fr       */
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
	frame.addr = mlx_get_data_addr(frame.img,
		&frame.bpp, &frame.line_size,
		&frame.endian);
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

void	cd_free_params(t_map_editor *m_edit)
{
	free(m_edit->p_vars.table_mx);
	free(m_edit->p_vars.table_my);
}

void	cd_mlx_setups(t_map_editor *m_edit)
{
	mlx_hook(m_edit->mlx_win, 2, 1L<<0, cd_key_pressed, m_edit);
	mlx_hook(m_edit->mlx_win, 3, 1L<<1, cd_key_released, &m_edit->keys);
	mlx_hook(m_edit->mlx, 17, 1L<<0, cd_stop_maker, m_edit);
	mlx_mouse_hook(m_edit->mlx_win, cd_mouse_handler, m_edit);
	if (!mlx_loop_hook(m_edit->mlx, cd_map_printer, m_edit))
		mlx_loop_end(m_edit->mlx);
	mlx_loop(m_edit->mlx);
	cd_free_params(m_edit);
	mlx_clear_window(m_edit->mlx, m_edit->mlx_win);
	mlx_destroy_image(m_edit->mlx, m_edit->frame.img);
	mlx_destroy_window(m_edit->mlx, m_edit->mlx_win);
	// mlx_destroy_display(m_edit->mlx);
	free(m_edit->mlx); //da hell
}

char	*cd_map_maker(void)
{
	t_map_editor	m_edit;
	t_keys			keys;
	t_img_info		frame;
	t_p_vars		p_vars;

	m_edit.w_width = 1280;
	m_edit.w_height = 720;
	m_edit.m_width = 3;
	m_edit.m_height = 3;
	m_edit.mlx = mlx_init();
	if (!m_edit.mlx)
		return (NULL);
	m_edit.mlx_win = mlx_new_window(m_edit.mlx, m_edit.w_width,
		m_edit.w_height, "Map Editor");
	m_edit.map = setup_clear_map();
	keys = cd_setup_keys();
	frame = cd_setup_frame(m_edit);
	p_vars = cd_setup_p_vars(m_edit);
	m_edit.keys = keys;
	m_edit.frame = frame;
	m_edit.p_vars = p_vars;
	cd_mlx_setups(&m_edit);
	// cd_finish_file(m_edit.fd, m_edit.map)

	// to remove
	int	i = -1;
	while(m_edit.map[++i])
		free(m_edit.map[i]);
	free(m_edit.map);

	// return (m_edit.filename);
	return ("WIP");
}
