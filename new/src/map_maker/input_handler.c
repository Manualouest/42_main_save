/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:13:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 19:30:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

int	cd_key_pressed(int keycode, t_map_editor *m_edit)
{
	if (m_edit->keys.stopper)
		return (0);
	if (keycode == 65307)
		cd_stop_maker(m_edit);
	if (keycode == 65362)
		m_edit->keys.up = 1;
	else if (keycode == 65364)
		m_edit->keys.down = 1;
	if (keycode == 65361)
		m_edit->keys.left = 1;
	else if (keycode == 65363)
		m_edit->keys.right = 1;
	// if (keycode == 120)
	// 	cd_remove_wall(m_edit);
	// else if (keycode == 99)
	// 	cd_place_wall(m_edit);
	// else if (keycode == 118)
	// 	cd_teleport(m_edit);
	// if (keycode == )
	// 	m_edit->keys->stopper = 1;
	return (1);
}

int	cd_key_released(int keycode, t_keys *keys)
{
	if (keys->stopper)
		return (0);
	if (keycode == 65362)
		keys->up = 0;
	else if (keycode == 65364)
		keys->down = 0;
	if (keycode == 65361)
		keys->left = 0;
	else if (keycode == 65363)
		keys->right = 0;
	return (1);
}

int	cd_mouse_handler(int button, int x, int y, t_map_editor *m_edit)
{
	if (m_edit->keys.stopper)
		return (0);
	(void)x;
	(void)y;
// 	if (button == 1)
// 		cd_remove_wall(m_edit);
// 	else if (button == 3)
// 		cd_place_wall(m_edit);
// 	else if (button == 2)
// 		cd_teleport(m_edit);
	(void)button;
	return (1);
}

int	cd_stop_maker(t_map_editor *m_edit)
{
	mlx_loop_end(m_edit->mlx);
	return (1);
}
