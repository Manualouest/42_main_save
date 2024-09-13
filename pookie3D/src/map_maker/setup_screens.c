/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_screens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:51:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/13 21:00:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_add_text(t_map_editor *m_edit, char *text, int x, int y)
{
	(&m_edit->m_info)->text = cd_append_img((&m_edit->m_info)->text,
			mlx_put_string(m_edit->mlx, text, x, y));
}

void	cd_resizer(mlx_image_t *img, int width, int height)
{
	int	new_width;
	int	new_height;

	new_width = img->width + width;
	new_height = img->height + height;
	mlx_resize_image(img, new_width, new_height);
}

void	cd_setup_screen_1(t_map_editor *m_edit)
{
	cd_add_text(m_edit, "Welcome to the map editor", 360, 50);
	cd_resizer(m_edit->m_info.text[0], 200, 20);
	cd_add_text(m_edit, "Please enter the name of your map (35 char max):", 60, 200);
	cd_resizer(m_edit->m_info.text[1], 80, 10);
	cd_add_text(m_edit, "_________________________________________", 100, 270);
	cd_add_text(m_edit, "press <enter> when finished", 80, 310);
	cd_resizer(m_edit->m_info.text[3], -18, -2);
	cd_add_text(m_edit, " ", 0, 0);
}

void	cd_setup_screen_2(t_map_editor *m_edit, char *type)
{
	cd_add_text(m_edit, "Now time for the textures", 360, 50);
	cd_resizer(m_edit->m_info.text[0], 200, 20);
	cd_add_text(m_edit, "Please enter the", 60, 200);
	cd_resizer(m_edit->m_info.text[1], 80, 10);
	cd_add_text(m_edit, type, 315, 200);
	cd_resizer(m_edit->m_info.text[2], 20, 10);
	cd_add_text(m_edit, "texture", 400, 200);
	cd_resizer(m_edit->m_info.text[3], 30, 10);
	cd_add_text(m_edit, "___________________________________________", 100, 270);
	cd_add_text(m_edit, "press <enter> when finished", 80, 310);
	cd_resizer(m_edit->m_info.text[4], -18, -2);
	cd_add_text(m_edit, " ", 0, 0);
}
