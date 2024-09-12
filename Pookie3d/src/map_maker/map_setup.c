/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/12 18:54:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	test1(t_map_editor *m_edit)
{
	int	y = -1;
	int	x;
	while (++y < m_edit->w_height)
	{
		x = -1;
		while (++x < m_edit->w_width)
		{
			mlx_put_pixel(m_edit->map_info.screen.img, x, y, 0x7F0000FF);
		}
	}
	mlx_put_string(m_edit->mlx, "d", 0, 0);
	mlx_image_to_window(m_edit->mlx, m_edit->map_info.screen.img, 0, 0);
	mlx_image_t *test = mlx_put_string(m_edit->mlx, "HEllo.", 100, 100);
	mlx_resize_image(test, 1000, 50);
	mlx_image_to_window(m_edit->mlx, test, 100, 100);
	mlx_image_to_window(m_edit->mlx, mlx_put_string(m_edit->mlx, "test.", 350, 100), 150, 100);
}

void	test2(t_map_editor *m_edit)
{
	int	y = -1;
	int	x;
	while (++y < m_edit->w_height)
	{
		x = -1;
		while (++x < m_edit->w_width)
		{
			mlx_put_pixel(m_edit->map_info.screen.img, x, y, 0x007F00FF);
		}
	}
	mlx_image_to_window(m_edit->mlx, m_edit->map_info.screen.img, 0, 0);
}

void	test3(t_map_editor *m_edit)
{
	int	y = -1;
	int	x;
	while (++y < m_edit->w_height)
	{
		x = -1;
		while (++x < m_edit->w_width)
		{
			mlx_put_pixel(m_edit->map_info.screen.img, x, y, 0x00007FFF);
		}
	}
	mlx_image_to_window(m_edit->mlx, m_edit->map_info.screen.img, 0, 0);
}

void	key_test(mlx_key_data_t keydata, void *vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ENTER)
	{
		if (m_edit->map_info.step < 3)
			m_edit->map_info.step ++;
		else
			mlx_close_window(m_edit->mlx);
	}
}

void	cd_screen_manager(void	*vm_edit)
{
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	if (m_edit->map_info.step == 1)
		test1(m_edit);
	else if (m_edit->map_info.step == 2)
		test2(m_edit);
	else if (m_edit->map_info.step == 3)
		test3(m_edit);
}

void	cd_start_map_setup(t_map_editor *m_edit)
{
	m_edit->mlx = mlx_init(1280, 720, "Map Editor", false);
	m_edit->map_info = cd_setup_map_info(*m_edit);

	mlx_key_hook(m_edit->mlx, key_test, (void *)m_edit);
	mlx_loop_hook(m_edit->mlx, cd_screen_manager, (void *)m_edit);
	mlx_loop(m_edit->mlx);
	mlx_delete_image(m_edit->mlx, m_edit->map_info.screen.img);
	mlx_terminate(m_edit->mlx);
}