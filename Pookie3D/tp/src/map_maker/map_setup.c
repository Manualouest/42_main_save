/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 15:18:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_map_name_input(t_map_editor *m_edit, t_map_info *m_info)
{
	char	*map_input;

	cd_free_tab_img(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
	if (m_info->step == -1)
	{
		m_info->input = cd_realloc(m_info->input, "BadName", 1);
		m_info->step *= -1;
	}
	map_input = ft_strjoin(m_info->input, ".cub");
	cd_add_text(m_edit, map_input, 105, 265);
	if (m_info->text[cd_tab_len(m_info->text)])
		cd_resizer(m_edit->m_info.text[cd_tab_len(m_info->text)], 0, 10);
	if (m_info->try_step)
	{
		if (cd_check_file(map_input) != 0)
			m_info->step *= -1;
		else
		{
			m_info->step ++;
			m_info->map_name = ft_strdup(map_input);
			m_info->text = cd_free_tab_img(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
	free(map_input);
}

void	cd_map_texture_input(t_map_editor *m_edit, t_map_info *m_info,
			char **txt)
{
	char	*texture_input;

	cd_free_tab_img(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
	if (m_info->step < -1)
	{
		m_info->input = cd_realloc(m_info->input, "BadName", 1);
		m_info->step *= -1;
	}
	texture_input = ft_strjoin(m_info->input, ".xpm");
	cd_add_text(m_edit, texture_input, 105, 265);
	if (m_info->text[cd_tab_len(m_info->text)])
		cd_resizer(m_edit->m_info.text[cd_tab_len(m_info->text)], 0, 10);
	if (m_info->try_step)
	{
		if (cd_check_file(texture_input) != 1)
			m_info->step *= -1;
		else
		{
			m_info->step ++;
			*txt = cd_realloc(*txt, ft_strjoin(*txt, texture_input), 0);
			m_info->text = cd_free_tab_img(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
	free(texture_input);
}

void	cd_map_numbers_input(t_map_editor *m_edit, t_map_info *m_info,
			char **txt)
{
	if (m_info->step > 9)
		return ;
	cd_free_tab_img(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
	if (m_info->step < -1)
	{
		m_info->input = cd_realloc(m_info->input, "BadInput", 1);
		m_info->step *= -1;
	}
	cd_add_text(m_edit, m_info->input, 105, 265);
	if (m_info->text[cd_tab_len(m_info->text)])
		cd_resizer(m_edit->m_info.text[cd_tab_len(m_info->text)], 0, 10);
	if (m_info->try_step)
	{
		if (cd_check_input(m_info, m_info->input, m_info->step) != 1)
			m_info->step *= -1;
		else
		{
			m_info->step ++;
			*txt = cd_realloc(*txt, ft_strjoin(*txt, m_info->input), 0);
			m_info->text = cd_free_tab_img(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
}

void	cd_screen_manager(void	*vm_edit)
{
	t_map_editor	*m_edit;
	t_map_info		m_info;
	struct timeval	time;

	m_edit = (t_map_editor *)vm_edit;
	m_info = m_edit->m_info;
	gettimeofday(&time, NULL);
	if (!m_info.text && (m_info.step == 1 || m_info.step == -1))
		cd_setup_screen_1(m_edit);
	else if (!m_info.text && (m_info.step > 5 || m_info.step < -5))
		cd_setup_screen_3(m_edit);
	else if (!m_info.text)
		cd_setup_screen_2(m_edit);
	if (m_info.step == 1 || m_info.step == -1)
		cd_map_name_input(m_edit, &m_edit->m_info);
	else if (m_info.step > 5 || m_info.step < -5)
		cd_map_numbers_input(m_edit, &m_edit->m_info, cd_get_txt(m_edit));
	else
		cd_map_texture_input(m_edit, &m_edit->m_info, cd_get_txt(m_edit));
	if (m_edit->m_info.text)
		mlx_image_to_window(m_edit->mlx, m_edit->m_info.text[0], 0, -1000);
	cd_slow_down(m_edit, time, 60, 0);
	if (m_info.step > 9)
		mlx_close_window(m_edit->mlx);
}
