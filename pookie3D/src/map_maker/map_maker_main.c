/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/27 10:34:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	*cd_free_m_info(t_map_info m_info, int free_name)
{
	if (free_name)
		free(m_info.map_name);
	if (m_info.north)
		free(m_info.north);
	if (m_info.south)
		free(m_info.south);
	if (m_info.west)
		free(m_info.west);
	if (m_info.east)
		free(m_info.east);
	if (m_info.ceiling)
		free(m_info.ceiling);
	if (m_info.floor)
		free(m_info.floor);
	if (m_info.map_size)
		free(m_info.map_size);
	if (m_info.player)
		free(m_info.player);
	if (m_info.input)
		free(m_info.input);
	return (NULL);
}

void	cd_clean_map(t_map_editor *m_edit)
{
	int	i;

	m_edit->map[m_edit->origin_y][m_edit->origin_x] = m_edit->dir;
	i = -1;
	while (++i < m_edit->m_height)
	{
		m_edit->map[i][0] = '1';
		m_edit->map[i][(int)m_edit->m_width - 1] = '1';
	}
	i = -1;
	while (++i < m_edit->m_width)
	{
		m_edit->map[0][i] = '1';
		m_edit->map[(int)m_edit->m_height - 1][i] = '1';
	}
}

void	cd_write_file(t_map_editor *m_edit, t_map_info m_info)
{
	int	fd;
	int	i;

	if (!m_edit->map)
		return ;
	fd = open(m_info.map_name, O_CREAT | O_RDWR, S_IRWXU);
	if (fd == -1)
	{
		// error couldn't make file
		m_edit->m_info.map_name = cd_realloc(m_info.map_name, NULL, 0);
		cd_free_tab(m_edit->map);
		return ;
	}
	m_edit->m_info.step = 1;
	while (++m_edit->m_info.step < 8)
	{
		write(fd, *cd_get_txt(m_edit), ft_strlen(*cd_get_txt(m_edit)));
		write(fd, "\n", 1);
	}
	i = -1;
	cd_clean_map(m_edit);
	while (m_edit->map[++i])
		write(fd, m_edit->map[i], ft_strlen(m_edit->map[i]));
	cd_free_tab(m_edit->map);
	close(fd);
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
	free(m_edit->p_vars.table_mx);
	free(m_edit->p_vars.table_my);
}

void	cd_start_map_setup(t_map_editor *m_edit)
{
	char	**split;

	m_edit->mlx = mlx_init(1280, 720, "Map Editor", false);
	m_edit->m_info = cd_setup_m_info(*m_edit);
	mlx_key_hook(m_edit->mlx, cd_input_handler, (void *)m_edit);
	mlx_loop_hook(m_edit->mlx, cd_screen_manager, (void *)m_edit);
	mlx_loop(m_edit->mlx);
	mlx_delete_image(m_edit->mlx, m_edit->m_info.screen.img);
	cd_free_tab_img(m_edit->m_info.text, m_edit, 1);
	mlx_terminate(m_edit->mlx);
	split = ft_split(m_edit->m_info.map_size, ',');
	if (split && split[0])
		m_edit->m_width = ft_atoi(split[0]);
	if (split && split[0] && split[1])
		m_edit->m_height = ft_atoi(split[1]);
	cd_free_tab(split);
	split = ft_split(m_edit->m_info.player, ',');
	if (split && split[0])
		m_edit->origin_x = ft_atoi(split[0]);
	if (split && split[0] && split[1])
		m_edit->origin_y = ft_atoi(split[1]);
	if (split && split[0] && split[1] && split[2])
		m_edit->dir = split[2][0] - ('a' - 'A');
	cd_free_tab(split);
}

char	*cd_map_maker(void)
{
	t_map_editor	m_edit;
	t_img_info		frame;
	t_p_vars		p_vars;

	m_edit.w_width = 1280;
	m_edit.w_height = 720;
	cd_start_map_setup(&m_edit);
	if (ft_strlen(m_edit.m_info.player) < 1)
		return (cd_free_m_info(m_edit.m_info, 1)); //error : input interupted
	m_edit.map = setup_clear_map(m_edit);
	m_edit.mlx = mlx_init(m_edit.w_width,
			m_edit.w_height, "Map Editor", false);
	if (!m_edit.mlx)
		return (NULL);
	frame = cd_setup_frame(m_edit, m_edit.w_width, m_edit.w_height);
	p_vars = cd_setup_p_vars(m_edit);
	m_edit.frame = frame;
	m_edit.p_vars = p_vars;
	m_edit.fps = NULL;
	cd_start_editor(&m_edit);
	if (!m_edit.map)
		m_edit.m_info.map_name = cd_realloc(m_edit.m_info.map_name, NULL, 0);
	cd_write_file(&m_edit, m_edit.m_info);
	cd_free_m_info(m_edit.m_info, 0);
	return (m_edit.m_info.map_name);
}
