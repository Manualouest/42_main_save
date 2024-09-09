/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:13:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/09 16:04:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_key_handler(mlx_key_data_t keydata, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (keydata.action == MLX_RELEASE)
		cd_key_released(keydata, (void *)&m_edit->keys);
	else
	{
		if (m_edit->keys.stopper)
			return ;
		if (keydata.key == MLX_KEY_ESCAPE)
			cd_stop_maker((void *)m_edit);
		if (keydata.key == MLX_KEY_UP)
			m_edit->keys.up = 1;
		else if (keydata.key == MLX_KEY_DOWN)
			m_edit->keys.down = 1;
		if (keydata.key == MLX_KEY_LEFT)
			m_edit->keys.left = 1;
		else if (keydata.key == MLX_KEY_RIGHT)
			m_edit->keys.right = 1;
	}
	// if (keydata.key == 120)
	// 	cd_remove_wall(m_edit);
	// else if (keydata.key == 99)
	// 	cd_place_wall(m_edit);
	// else if (keydata.key == 118)
	// 	cd_teleport(m_edit);
	// if (keydata.key == )
	// 	m_edit->keys->stopper = 1;
}

void	cd_key_released(mlx_key_data_t keydata, void *vkeys)
{
	t_keys	*keys;

	keys = (t_keys *)vkeys;
	if (keys->stopper)
		return ;
	if (keydata.key == MLX_KEY_UP)
		keys->up = 0;
	else if (keydata.key == MLX_KEY_DOWN)
		keys->down = 0;
	if (keydata.key == MLX_KEY_LEFT)
		keys->left = 0;
	else if (keydata.key == MLX_KEY_RIGHT)
		keys->right = 0;
}

void	cd_mouse_handler(mouse_key_t button, action_t action, modifier_key_t mods, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (m_edit->keys.stopper)
		return ;
	(void)button;
	(void)action;
	(void)mods;
// 	if (button == 1)
// 		cd_remove_wall(m_edit);
// 	else if (button == 3)
// 		cd_place_wall(m_edit);
// 	else if (button == 2)
// 		cd_teleport(m_edit);
	(void)button;
}

void	cd_stop_maker(void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	mlx_close_window(m_edit->mlx);
}
