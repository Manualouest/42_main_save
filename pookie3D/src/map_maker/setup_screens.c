/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_screens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:51:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 01:15:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	**cd_send_texture(t_map_editor *m_edit)
{
	int	step;

	step = m_edit->m_info.step;
	if (step == 2)
		return (&m_edit->m_info.north);
	if (step == 3)
		return (&m_edit->m_info.south);
	if (step == 4)
		return (&m_edit->m_info.west);
	if (step == 5)
		return (&m_edit->m_info.east);
	if (step == 6)
		return (&m_edit->m_info.ceiling);
	if (step == 7)
		return (&m_edit->m_info.floor);
	if (step == 8)
		return (&m_edit->m_info.map_size);
	return (&m_edit->m_info.player);
}

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

void	cd_setup_screen_2(t_map_editor *m_edit)
{
	char	*type;

	if (m_edit->m_info.step == 2)
		type = "north";
	else if (m_edit->m_info.step == 3)
		type = "south";
	else if (m_edit->m_info.step == 4)
		type = "west";
	else if (m_edit->m_info.step == 5)
		type = "east";
	m_edit->m_info.input = cd_realloc(m_edit->m_info.input, "", 1);
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

void	cd_setup_screen_3(t_map_editor *m_edit)
{
	char	*type;

	if (m_edit->m_info.step > 9)
		return ;
	if (m_edit->m_info.step == 6)
		type = "Please enter ceiling color (r,g,b)";
	else if (m_edit->m_info.step == 7)
		type = "Please enter floor color (r,g,b)";
	else if (m_edit->m_info.step == 8)
		type = "Please enter map size (width,height)";
	else if (m_edit->m_info.step == 9)
		type = "Please enter player position (x,y,orientation)";
	m_edit->m_info.input = cd_realloc(m_edit->m_info.input, "", 1);
	cd_add_text(m_edit, "Finally, time for some numbers", 360, 50);
	cd_resizer(m_edit->m_info.text[0], 200, 20);
	cd_add_text(m_edit, type, 315, 200);
	cd_resizer(m_edit->m_info.text[1], 20, 10);
	cd_add_text(m_edit, "___________________________________________", 100, 270);
	cd_add_text(m_edit, "press <enter> when finished", 80, 310);
	cd_resizer(m_edit->m_info.text[2], -18, -2);
	cd_add_text(m_edit, " ", 0, 0);
}
