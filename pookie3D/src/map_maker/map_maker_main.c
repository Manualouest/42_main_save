/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/13 15:58:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_free_params(t_map_editor *m_edit)
{
	free(m_edit->p_vars.table_mx);
	free(m_edit->p_vars.table_my);
}

void	cd_start_editor(t_map_editor *m_edit)
{
	mlx_image_to_window(m_edit->mlx, m_edit->frame.img, 0, 0);
	mlx_set_cursor_mode(m_edit->mlx, MLX_MOUSE_HIDDEN);
	mlx_key_hook(m_edit->mlx, cd_key_handler, (void *)m_edit);
	mlx_mouse_hook(m_edit->mlx, cd_mouse_handler, (void *)m_edit);
	mlx_loop_hook(m_edit->mlx, cd_map_printer, (void *)m_edit);
	mlx_loop(m_edit->mlx);
	mlx_delete_image(m_edit->mlx, m_edit->frame.img);
	mlx_delete_image(m_edit->mlx, m_edit->fps);
	mlx_terminate(m_edit->mlx);
}

char	*cd_map_maker(void)
{
	t_map_editor	m_edit;
	t_img_info		frame;
	t_p_vars		p_vars;

	m_edit.w_width = 1280;
	m_edit.w_height = 720;
	cd_start_map_setup(&m_edit);
	m_edit.m_width = 11;//////////
	m_edit.m_height = 11;/////////
	m_edit.origin_x = 5;///////////
	m_edit.origin_y = 5;///////////
	m_edit.mlx = mlx_init(m_edit.w_width,
			m_edit.w_height, "Map Editor", false);
	if (!m_edit.mlx)
		return (NULL);
	m_edit.map = setup_clear_map(11, 11, 5, 5);
	frame = cd_setup_frame(m_edit, m_edit.w_width, m_edit.w_height);
	p_vars = cd_setup_p_vars(m_edit);
	m_edit.frame = frame;
	m_edit.p_vars = p_vars;
	m_edit.fps = NULL;
	// cd_start_editor(&m_edit);
	// cd_finish_file(m_edit.fd, m_edit.map)



	// to remove
	int	i = -1;
	while(m_edit.map[++i])
	{
		printf("%s\n", m_edit.map[i]);
		free(m_edit.map[i]);
	}
	free(m_edit.map);
	// return (m_edit.filename);



	cd_free_params(&m_edit);
	return (ft_strdup("WIP"));
}
