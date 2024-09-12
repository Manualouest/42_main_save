/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:13:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/12 15:07:56 by mbirou           ###   ########.fr       */
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
