/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:13:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 00:53:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_key_handler(mlx_key_data_t keydata, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(m_edit->mlx);
		if (keydata.key == MLX_KEY_UP)
			m_edit->p_vars.y += 1;
		else if (keydata.key == MLX_KEY_DOWN)
			m_edit->p_vars.y -= 1;
		if (keydata.key == MLX_KEY_LEFT)
			m_edit->p_vars.x += 1;
		else if (keydata.key == MLX_KEY_RIGHT)
			m_edit->p_vars.x -= 1;
	}
}

void	cd_remove_wall(t_map_editor *m_edit)
{
	int	x;
	int	y;
	int	mx;
	int	my;

	mlx_get_mouse_pos(m_edit->mlx, &x, &y);
	mx = m_edit->p_vars.table_mx[x - m_edit->p_vars.left_gap]
		- m_edit->p_vars.offsetx + m_edit->p_vars.x + 1;
	my = m_edit->p_vars.table_my[y - m_edit->p_vars.up_gap]
		- m_edit->p_vars.offsety + m_edit->p_vars.y + 1;
	if (mx < 0 || my < 0 || mx >= m_edit->m_width || my >= m_edit->m_height)
		return ;
	if (m_edit->map[my][mx] == '1')
		m_edit->map[my][mx] = '0';
}

void	cd_place_wall(t_map_editor *m_edit)
{
	int	x;
	int	y;
	int	mx;
	int	my;

	mlx_get_mouse_pos(m_edit->mlx, &x, &y);
	mx = m_edit->p_vars.table_mx[x - m_edit->p_vars.left_gap]
		- m_edit->p_vars.offsetx + m_edit->p_vars.x + 1;
	my = m_edit->p_vars.table_my[y - m_edit->p_vars.up_gap]
		- m_edit->p_vars.offsety + m_edit->p_vars.y + 1;
	if (mx < 0 || my < 0 || mx >= m_edit->m_width || my >= m_edit->m_height)
		return ;
	if (!(my == m_edit->origin_y && mx == m_edit->origin_x)
		&& m_edit->map[my][mx] == '0')
		m_edit->map[my][mx] = '1';
}

void	cd_mouse_handler(mouse_key_t button, action_t action,
	modifier_key_t mods, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (!m_edit->map)
		return ;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		cd_remove_wall(m_edit);
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
		cd_place_wall(m_edit);
}

void	cd_input_handler(mlx_key_data_t keydata, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(m_edit->mlx);
	if (keydata.key == MLX_KEY_ENTER && m_edit->m_info.try_step == 0)
		m_edit->m_info.try_step = 1; //try_step = 1
	else if (keydata.key == MLX_KEY_BACKSPACE
		&& ft_strlen(m_edit->m_info.input) != 0)
		m_edit->m_info.input[ft_strlen(m_edit->m_info.input) - 1] = 0;
	else if (keydata.key >= MLX_KEY_A && keydata.key <= MLX_KEY_Z
		&& ft_strlen(m_edit->m_info.input) < 36)
		m_edit->m_info.input = cd_append_char(m_edit->m_info.input,
			keydata.key - MLX_KEY_A + 'a');
	else if (((keydata.key >= MLX_KEY_0 && keydata.key <= MLX_KEY_9)
		|| (keydata.key >= MLX_KEY_COMMA && keydata.key <= MLX_KEY_SLASH))
		&& ft_strlen(m_edit->m_info.input) < 36)
		m_edit->m_info.input = cd_append_char(m_edit->m_info.input,
			keydata.key);
}
