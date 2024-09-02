/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:32:22 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/29 12:08:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

#include <stdio.h>

int	cd_is_coord_possible(t_info *info, char **tab, int x, int y)
{
	if (y >= info->m_height || x >= info->m_width || y < 0 || x < 0)
		return (0);
	if (tab[y][x])
		return (1);
	return (0);
}

float	cd_triangle_area(t_pos p1, t_pos p2, t_pos p3)
{
	float	area;

	area = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) +
		p3.x * (p1.y - p2.y)) / 2.0;
	area = fabs(area);
	return (area);
}

int	cd_is_in_triangle(t_pos p, t_pos p1, t_pos p2, t_pos p3)
{
	float	area1;
	float	area2;
	float	area3;
	float	triangle_area;

	area1 = cd_triangle_area(p, p1, p2);
	area2 = cd_triangle_area(p, p2, p3);
	area3 = cd_triangle_area(p, p1, p3);
	triangle_area = cd_triangle_area(p1, p2, p3);
	return (cd_round(triangle_area, 100) == cd_round(
		area1 + area2 + area3, 100));
}

t_mm_info	cd_setup_minimap_struct(t_info *info)
{
	t_mm_info	mm_info;
	
	mm_info.m_height = info->mlx_info->w_height / 4.0;
	mm_info.m_width = info->mlx_info->w_width / 4.0;
	mm_info.gap = 0;
	if (info->keys->minimap)
		mm_info.gap = (info->p_pos->height - 0.41) *
			((info->mlx_info->w_height - mm_info.m_height) / 0.82);
	mm_info.p1.x = (info->p_pos->x + cos(info->p_pos->orientation) /
		(4.0 + ((info->p_pos->height + 0.41)))); // (0.5 / 0.82)
	mm_info.p1.y = (info->p_pos->y + sin(info->p_pos->orientation) /
		(4.0 + ((info->p_pos->height + 0.41)))); // (0.5 / 0.82)
	mm_info.p2.x = (info->p_pos->x + cos(cd_basic_f_clamp(
		info->p_pos->orientation + (0.7 * M_PI), 0, 2.0 * M_PI)) /
		(6.0 + ((info->p_pos->height + 0.41))));
	mm_info.p2.y = (info->p_pos->y + sin(cd_basic_f_clamp(
		info->p_pos->orientation + (0.7 * M_PI), 0, 2.0 * M_PI)) /
		(6.0 + ((info->p_pos->height + 0.41))));
	mm_info.p3.x = (info->p_pos->x + cos(cd_basic_f_clamp(
		info->p_pos->orientation - (0.7 * M_PI), 0, 2.0 * M_PI)) /
		(6.0 + ((info->p_pos->height + 0.41))));
	mm_info.p3.y = (info->p_pos->y + sin(cd_basic_f_clamp(
		info->p_pos->orientation - (0.7 * M_PI), 0, 2.0 * M_PI)) /
		(6.0 + ((info->p_pos->height + 0.41))));
	return (mm_info);
}

void	cd_add_minimap(t_info *info)
{
	t_mm_info	mm_info;
	int		mx;
	int		my;
	int		i;
	int		ii;

	mm_info = cd_setup_minimap_struct(info);
	i = -1;
	while(++i <= mm_info.m_height)
	{
		ii = -1;
		while(++ii <= mm_info.m_width)
		{
			mx = (int)(floor((((float)ii) * (12.0 / mm_info.m_width)) * info->mlx_info->s_width) + (info->p_pos->x - 6.0) * info->mlx_info->s_width);
			my = (int)(floor((((float)i) * (8.0 / mm_info.m_height)) * info->mlx_info->s_height) + (info->p_pos->y - 4.0) * info->mlx_info->s_height);
			mm_info.p.x = mx / info->mlx_info->s_width;
			mm_info.p.y = my / info->mlx_info->s_height;
			if (cd_is_in_triangle(mm_info.p, mm_info.p1, mm_info.p2, mm_info.p3))
				cd_change_pixel_color(info->mlx_info->main_frame, ii, i - mm_info.gap, cd_basic_f_clamp(0x00FFFFFF - ((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF)), 0, (float)0x00FFFFFF));
			else if ((cd_is_coord_possible(info, info->map, (int)floor(mx / info->mlx_info->s_width), (int)floor(my / info->mlx_info->s_height)) && info->map[(int)(my / info->mlx_info->s_height)][(int)(mx / info->mlx_info->s_width)] == '1') || (floor(my / info->mlx_info->s_height) >= info->m_height || floor(mx / info->mlx_info->s_width) >= info->m_width || floor(my / info->mlx_info->s_height) < 0 || floor(mx / info->mlx_info->s_width) < 0))
				cd_change_pixel_color(info->mlx_info->main_frame, ii, i - mm_info.gap, cd_basic_f_clamp((info->mlx_info->floor & 0x00FFFFFF) + (info->mlx_info->roof & 0x00FFFFFF), 0, (float)0x00FFFFFF));
			else
				cd_change_pixel_color(info->mlx_info->main_frame, ii, i - mm_info.gap, 0x00FFFFFF - (info->mlx_info->roof & 0x00FFFFFF));
		}
	}
}
