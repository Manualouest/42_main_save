/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mining.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:59:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/29 12:52:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>
#include <stdio.h>

char	**cd_add_map_line(t_info *info, int pos)
{
	char	*line;
	char	**n_map;
	int		i;

	line = ft_calloc(sizeof(char), info->m_width);
	i = -1;
	
	while (++i < info->m_width)
		line[i] = '1';
	n_map = ft_calloc(sizeof(char *), info->m_height + 2);
	if (pos == 1)
		n_map[0] = line;
	else
		n_map[info->m_height] = line;
	i = 0;
	while (i < info->m_height)
	{
		n_map[i + pos] = info->map[i];
		i ++;
	}
	free(info->map);
	info->m_height ++;
	info->p_pos->y += pos;
	return (n_map);
}

void	cd_add_map_row(t_info *info, int pos)
{
	char	*line;
	int		i;

	i = 0;
	while (i < info->m_height)
	{
		line = ft_calloc(sizeof(char), info->m_width + 4);
		ft_strlcpy(&line[pos], info->map[i], ft_strlen(info->map[i]) + 1);
		if (pos == 1)
			line[0] = '1';
		else
			line[info->m_width] = '1';
		info->map[i] = cd_re_malloc(info->map[i], line);
		i ++;
	}
	info->p_pos->x += pos;
	info->m_width ++;
}

int	cd_check_hole(t_info *info, t_ray_info ray_info, int x, int y)
{
	if (x == 0
	 	&& ray_info.x + (x + (x == -1)) + 1 == info->m_width)
		return (1);
	else if (x == 1
		&& ray_info.x + (x + (x == -1)) == 1)
		return (1);
	else if (y == 0
		&& ray_info.y + (y + (y == -1)) + 1 == info->m_height)
		return (1);
	else if (y == 1
		&& ray_info.y + (y + (y == -1)) == 1)
		return (1);
	return (0);
}

void	cd_mine_block(t_info *info)
{
	t_ray_info	ray_info;
	int			x;
	int			y;
	int			need_wall;

	x = -1;
	y = -1;
	ray_info.angle = info->p_pos->orientation;
	ray_info = cd_cast_ray(info, ray_info);
	if (ray_info.distance >= 5)
		return ;
	if (ray_info.side == 0 && cos(ray_info.angle) > 0)
		x = 0;
	else if (ray_info.side == 0 && cos(ray_info.angle) <= 0)
		x = 1;
	else if (ray_info.side == 1 && sin(ray_info.angle) > 0)
		y = 0;
	else
		y = 1;
	need_wall = cd_check_hole(info, ray_info, x, y);
	if (x != -1 && need_wall)
		cd_add_map_row(info, x);
	else if (need_wall)
		info->map = cd_add_map_line(info, y);
	if (need_wall)
		info->map[(int)ray_info.y + (y + (y == -1))][(int)ray_info.x + (x + (x == -1))] = '0';
	else
		info->map[(int)ray_info.y][(int)ray_info.x] = '0';
}

void	cd_place_block(t_info *info)
{
	t_ray_info	ray_info;
	int			x;
	int			y;

	x = 0;
	y = 0;
	ray_info.angle = info->p_pos->orientation;
	ray_info = cd_cast_ray(info, ray_info);
	if (ray_info.distance <= 1.0|| ray_info.distance >= 6)
		return ;
	if (ray_info.side == 0 && cos(ray_info.angle) > 0)
		x = -1;
	else if (ray_info.side == 0 && cos(ray_info.angle) <= 0)
		x = 1;
	else if (ray_info.side == 1 && sin(ray_info.angle) > 0)
		y = -1;
	else
		y = 1;
	if (!((int)ray_info.y + y == floor(info->p_pos->y)
		&& (int)ray_info.x + x == floor(info->p_pos->x)))
		info->map[(int)ray_info.y + y][(int)ray_info.x + x] = '1';
}

int	cd_mouse_hook(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (info->current_display == 1)
			cd_mine_block(info);
		if (info->current_display == 2)
			cd_edit_map(info, 0);
	}
	if (button == 2 && info->current_display == 2)
		cd_edit_map(info, 2);
	if (button == 3)
	{
		if (info->current_display == 1)
			cd_place_block(info);
		if (info->current_display == 2)
			cd_edit_map(info, 1);
	}
	return (1);
}
