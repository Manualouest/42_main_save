/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/09 16:11:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_free_params(t_map_editor *m_edit)
{
	free(m_edit->p_vars.table_mx);
	free(m_edit->p_vars.table_my);
}

void	cd_mlx_setups(t_map_editor *m_edit)
{
	mlx_key_hook(m_edit->mlx, cd_key_handler, (void *)m_edit);
	// mlx_key_hook(m_edit->mlx, cd_key_released, (void *)&m_edit->keys);
	mlx_mouse_hook(m_edit->mlx, cd_mouse_handler, (void *)m_edit);
	mlx_loop_hook(m_edit->mlx, cd_map_printer, (void *)m_edit);
	mlx_loop(m_edit->mlx);

	mlx_terminate(m_edit->mlx);
	cd_free_params(m_edit);
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
	m_edit.mlx = mlx_init(m_edit.w_width,
		m_edit.w_height, "Map Editor", false);
	if (!m_edit.mlx)
		return (NULL);
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
	printf("%f, %d, %d\n", m_edit.w_width, m_edit.p_vars.left_gap, m_edit.p_vars.right_gap);
	int	i = -1;
	while(m_edit.map[++i])
		free(m_edit.map[i]);
	free(m_edit.map);

	// return (m_edit.filename);
	return (ft_strdup("WIP"));
}
