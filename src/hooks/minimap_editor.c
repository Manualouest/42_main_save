/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:29:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/27 12:12:22 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

int	cd_make_mx_my(t_info *info, int *mx, int *my, int get_var)
{
	int	side_gap = (((info->mlx_info->w_width / (info->mlx_info->s_width / 2.0)) - floor(info->mlx_info->w_width / (info->mlx_info->s_width / 2.0))) * (info->mlx_info->s_width / 2.0)) / 2.0;
	int	up_gap = (((info->mlx_info->w_height / (info->mlx_info->s_height / 2.0)) - floor(info->mlx_info->w_height / (info->mlx_info->s_height / 2.0))) * (info->mlx_info->s_height / 2.0)) / 2.0;
	int	line = floor(info->mlx_info->w_width / (info->mlx_info->s_width / 2.0));
	int	row = floor(info->mlx_info->w_height / (info->mlx_info->s_height / 2.0));
	int	offsetx = line / 2 - (info->p_pos->x - 1);
	int	offsety = row / 2 - (info->p_pos->y - 1);

	if (get_var == 0)
	{
		*mx = (int)floor((*mx - side_gap) / ((info->mlx_info->w_width - side_gap * 2) / (line))) - offsetx;
		*my = (int)floor((*my - up_gap) / ((info->mlx_info->w_height - up_gap * 2) / (row))) - offsety;
	}
	else if (get_var == 1)
		return (side_gap);
	else if (get_var == 2)
		return (up_gap);
	else if (get_var == 3)
		return (line);
	else if (get_var == 4)
		return (row);
	else if (get_var == 5)
		return (offsetx);
	else if (get_var == 6)
		return (offsety);
	return (0);
}

// void			cd_remove_wall(info);
// {
// 	int	m_x;
// 	int	m_y;

// 	mlx_mouse_get_pos(info->mlx_info->mlx, info->mlx_info->mlx_win, &m_x, &m_y);
// 	cd_make_mx_my(info, &mx, &my, 0);
// }

// void			cd_place_wall(info);

void	cd_minimap_editor(t_info *info)
{
	int	side_gap;
	int	up_gap;
	// int	line;
	// int	row;
	int	mx;
	int	my;
	// int	offsetx;
	// int	offsety;
	int	y;
	int	x;

	// line = floor(info->mlx_info->w_width / (info->mlx_info->s_width / 2.0));
	// row = floor(info->mlx_info->w_height / (info->mlx_info->s_height / 2.0));
	// side_gap = (((info->mlx_info->w_width / (info->mlx_info->s_width / 2.0)) - floor(info->mlx_info->w_width / (info->mlx_info->s_width / 2.0))) * (info->mlx_info->s_width / 2.0)) / 2.0;
	// up_gap = (((info->mlx_info->w_height / (info->mlx_info->s_height / 2.0)) - floor(info->mlx_info->w_height / (info->mlx_info->s_height / 2.0))) * (info->mlx_info->s_height / 2.0)) / 2.0;
	// offsetx = line / 2 - (info->p_pos->x - 1);
	// offsety = row / 2 - (info->p_pos->y - 1);
	side_gap = cd_make_mx_my(info, &mx, &my, 1);
	up_gap = cd_make_mx_my(info, &mx, &my, 2);
	y = -1;
	while(++y < info->mlx_info->w_height)
	{
		x = -1;
		while (++x < info->mlx_info->w_width)
		{
			if (x <= side_gap || y <= up_gap || x >= info->mlx_info->w_width - side_gap || y >= info->mlx_info->w_height - up_gap)
				cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_invert_color(cd_basic_f_clamp((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF), 0, (float)0x00FFFFFF)));
			else 
			{
				// mx = (int)floor((x - side_gap) / ((info->mlx_info->w_width - side_gap * 2) / (line))) - offsetx;
				// my = (int)floor((y - up_gap) / ((info->mlx_info->w_height - up_gap * 2) / (row))) - offsety;
				mx = x;
				my = y;
				cd_make_mx_my(info, &mx, &my, 0);
				if (y > up_gap && x > side_gap && ((my >= 0 && my < info->m_height && mx >= 0 && mx < info->m_width)
					&& info->map[my][mx] == '1'))
					cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_basic_f_clamp((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF), 0, (float)0x00FFFFFF));
				else if (y > up_gap && x > side_gap && (my < 0 || my >= info->m_height || mx < 0 || mx >= info->m_width))
					cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_basic_f_clamp((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF), 0, (float)0x00FFFFFF));
				else if (mx == floor(info->p_pos->x) && my == floor(info->p_pos->y))
					cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_basic_f_clamp(0x00FFFFFF - ((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF)), 0, (float)0x00FFFFFF));
				else
					cd_change_pixel_color(info->mlx_info->main_frame, x, y, 0x00FFFFFF - (info->mlx_info->roof & 0x00FFFFFF));
				// printf("y: %d, x: %d, %c\n", (int)floor((y - up_gap * 2) / (row - 1)), (int)floor((x - side_gap / 2) / (line - 1)), info->map[(int)floor((y - up_gap * 2) / (row - 1))][(int)floor((x - side_gap / 2) / (line - 1))]);
			}
			if ((x - side_gap) % (int)(info->mlx_info->s_width / 2.0) == 0 || (y - up_gap) % (int)(info->mlx_info->s_height / 2.0) == 0)
				cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_invert_color(cd_get_color(info->mlx_info->main_frame, x, y)));
			// if (x >= info->mlx_info->w_width / 2 - 20 && x <= info->mlx_info->w_width / 2 + 20 && y >= info->mlx_info->w_height / 2 - 20 && y <= info->mlx_info->w_height / 2 + 20)
			// 	cd_change_pixel_color(info->mlx_info->main_frame, x, y, 0x00FFFFFF);
		}
	}
}
