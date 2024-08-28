/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:36:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

unsigned int	cd_get_color(t_frame_info *frame, int x, int y)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_size + x *
		(frame->bits_per_pixel / 8));
	return(*(unsigned int*)dst);
}

int	cd_invert_color(unsigned int color)
{
	if ((color & 0xFF) > 0x7F || ((color >> 8) & 0xFF) > 0x7F
		|| ((color >> 16) & 0xFF) > 0x7F)
		return (0x00000000);
	return (0x00FFFFFF);
}

void	cd_put_center_cross(t_info *info)
{
	int	x;
	int	x_start;
	int	x_m;
	int	y;
	int	y_m;

	x_start = info->mlx_info->w_width / 2 - 50;
	x_m = info->mlx_info->w_width / 2 + 50;
	y = info->mlx_info->w_height / 2 - 50;
	y_m = info->mlx_info->w_height / 2 + 50;
	while (y <= y_m)
	{
		x = x_start;
		while (x <= x_m)
		{
			if (((x == x_m - 100 || x == x_m) && (y >= y_m - 67 && y <= y_m - 33))
				|| ((y == y_m - 100 || y == y_m) && (x >= x_m - 67 && x <= x_m - 33))
				|| x == x_m - 50 || y == y_m - 50)
				cd_change_pixel_color(info->mlx_info->main_frame, x, y,
					cd_invert_color(cd_get_color(info->mlx_info->main_frame, x, y)));
			x ++;
		}
		y ++;
	}
}

void	cd_put_mouse(t_info *info)
{
	int	m_x;
	int	m_y;
	int	x;
	int	y;

	// if (info->current_display == 1)
	// 	cd_put_center_cross(info);
	mlx_mouse_get_pos(info->mlx_info->mlx, info->mlx_info->mlx_win, &m_x, &m_y);
	y = m_y - 5;
	if (y < 0)
		y = 0;
	while (y <= m_y + 5 && y < info->mlx_info->w_height)
	{
		x = m_x - 5;
		if (x < 0)
			x = 0;
		while (x <= m_x + 5 && x < info->mlx_info->w_width)
		{
			if (x == m_x || y == m_y)
				cd_change_pixel_color(info->mlx_info->main_frame, x, y, cd_invert_color(cd_get_color(info->mlx_info->main_frame, x, y)));
			x ++;
		}
		y ++;
	}
}
