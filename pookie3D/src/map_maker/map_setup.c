/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 01:15:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

int	cd_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
		close (fd);
	if (fd == -1 && errno != EACCES)
		return (0);
	if (errno == EACCES)
		return (-1);
	return (1);
}

void	cd_map_name_input(t_map_editor *m_edit, t_map_info *m_info)
{
	char				*map_input;

	cd_free_tab(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
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
			m_info->text = cd_free_tab(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
	free(map_input);
}

void	cd_map_texture_input(t_map_editor *m_edit, t_map_info *m_info, char **texture)
{
	char				*texture_input;

	cd_free_tab(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
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
			*texture = ft_strdup(texture_input);
			m_info->text = cd_free_tab(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
	free(texture_input);
}

int	cd_check_input(char *input, int step)
{
	int	i;
	int	nb_comma;

	i = -1;
	nb_comma = 0;
	while (input && input[++i])
	{
		if (!ft_isdigit(input[i]) && input[i] != ','
			&& (step != 9 || (step == 9 && (input[i] == 'n' || input[i] == 's'
				|| input[i] == 'w' || input[i] == 'e') && (nb_comma != 2
				|| input[i - 1 + (i == 0)] != ',' || input[i + 1]))))
			return (0);
		if (input[i] == ',')
			nb_comma ++;
	}
	if (nb_comma != 2 - (step == 8))
		return (0);
	return (1);
}

void	cd_map_numbers_input(t_map_editor *m_edit, t_map_info *m_info, char **texture)
{
	if (m_info->step > 9)
		return ;
	cd_free_tab(&m_info->text[cd_tab_len(m_info->text) - 1], m_edit, 0);
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
		if (cd_check_input(m_info->input, m_info->step) != 1)
			m_info->step *= -1;
		else
		{
			m_info->step ++;
			*texture = ft_strdup(m_info->input);
			m_info->text = cd_free_tab(m_info->text, m_edit, 1);
		}
		m_info->try_step = 0;
	}
}

void	cd_screen_manager(void	*vm_edit)
{
	t_map_editor	*m_edit;
	t_map_info		m_info;
	struct timeval		time;

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
		cd_map_numbers_input(m_edit, &m_edit->m_info, cd_send_texture(m_edit));
	else
		cd_map_texture_input(m_edit, &m_edit->m_info, cd_send_texture(m_edit));
	if (m_edit->m_info.text)
		mlx_image_to_window(m_edit->mlx, m_edit->m_info.text[0], 0, -1000);
	cd_slow_down(m_edit, time, 60, 0);
	if (m_info.step > 9)
		mlx_close_window(m_edit->mlx);
}

void	cd_start_map_setup(t_map_editor *m_edit)
{
	m_edit->mlx = mlx_init(1280, 720, "Map Editor", false);
	m_edit->m_info = cd_setup_m_info(*m_edit);

	mlx_key_hook(m_edit->mlx, cd_input_handler, (void *)m_edit);
	mlx_loop_hook(m_edit->mlx, cd_screen_manager, (void *)m_edit);
	mlx_loop(m_edit->mlx);
	mlx_delete_image(m_edit->mlx, m_edit->m_info.screen.img);
	cd_free_tab(m_edit->m_info.text, m_edit, 1);
	mlx_terminate(m_edit->mlx);
	free(m_edit->m_info.input);
	printf("filename: %s\n", m_edit->m_info.map_name);
	printf("north: %s\nsouth: %s\nwest: %s\neast: %s\nceiling: %s\nfloor: %s\nsize: %s\nplayer: %s\n", m_edit->m_info.north, m_edit->m_info.south, m_edit->m_info.west, m_edit->m_info.east, m_edit->m_info.ceiling, m_edit->m_info.floor, m_edit->m_info.map_size, m_edit->m_info.player);
}