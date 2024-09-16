/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:46:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 15:22:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

int	cd_get_pixel_kind(t_map_editor *m_edit, t_p_vars p_vars, int x, int y)
{
	int	mx;
	int	my;

	if (x < p_vars.left_gap || x >= p_vars.right_gap
		|| y < p_vars.up_gap || y >= p_vars.down_gap
		|| (x - p_vars.left_gap) % 25 == 0 || (y - p_vars.up_gap) % 25 == 0)
		return (1);
	mx = p_vars.table_mx[x - p_vars.left_gap] - p_vars.offsetx + p_vars.x + 1;
	my = p_vars.table_my[y - p_vars.up_gap] - p_vars.offsety + p_vars.y + 1;
	if (mx == m_edit->origin_x && my == m_edit->origin_y)
		return (2);
	if (mx >= 0 && my >= 0 && mx < m_edit->m_width && my < m_edit->m_height
		&& m_edit->map[my][mx] == '1')
		return (3);
	if ((mx < -1 || my < -1 || mx > m_edit->m_width || my > m_edit->m_height)
		|| ((mx == -1 || mx == m_edit->m_width)
			&& my >= -1 && my <= m_edit->m_height)
		|| ((my == -1 || my == m_edit->m_height)
			&& mx >= -1 && mx <= m_edit->m_width))
		return (4);
	return (0);
}

mlx_image_t	*cd_slow_down(t_map_editor *m_edit, struct timeval start_time,
				int target_fps, int do_return)
{
	mlx_image_t		*img;
	struct timeval	end_time;
	char			*fps;
	int				start;
	int				end;

	gettimeofday(&end_time, NULL);
	start = start_time.tv_sec * 1000000 + start_time.tv_usec;
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	while (1000000 / abs(end - start + 1) > target_fps)
	{
		gettimeofday(&end_time, NULL);
		end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	}
	gettimeofday(&end_time, NULL);
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	fps = ft_itoa(1000000 / abs(end - start + 1));
	img = mlx_put_string(m_edit->mlx, fps, 5, -4);
	free(fps);
	if (do_return)
		return (img);
	mlx_delete_image(m_edit->mlx, img);
	return (NULL);
}

void	cd_print_map(t_map_editor *m_edit, int x, int y)
{
	int	pixel_kind;

	pixel_kind = cd_get_pixel_kind(m_edit, m_edit->p_vars, x, y);
	if (pixel_kind == 1)
		mlx_put_pixel(m_edit->frame.img, x, y, 0x000000FF);
	else if (pixel_kind == 2)
		mlx_put_pixel(m_edit->frame.img, x, y, 0xFFFFFFFF);
	else if (pixel_kind == 3)
		mlx_put_pixel(m_edit->frame.img, x, y, 0xBFBFBFFF);
	else if (pixel_kind == 4)
		mlx_put_pixel(m_edit->frame.img, x, y, 0x2F2F2FFF);
	else
		mlx_put_pixel(m_edit->frame.img, x, y, 0x909090FF);
}

void	cd_place_mouse(t_map_editor *m_edit, t_img_info frame)
{
	int	x;
	int	y;
	int	i;

	mlx_get_mouse_pos(m_edit->mlx, &x, &y);
	if (x < 0 || x >= m_edit->w_width || y < 0 || y >= m_edit->w_height)
		return ;
	i = -6;
	while (++i <= 5)
	{
		if (x + i >= 0 && x + i < m_edit->w_width)
			mlx_put_pixel(frame.img, x + i, y, 0xAF5050FF);
		else if (x + i < 0)
			mlx_put_pixel(frame.img, 0, y, 0xAF5050FF);
		else
			mlx_put_pixel(frame.img, m_edit->w_width - 1, y, 0xAF5050FF);
		if (y + i >= 0 && y + i < m_edit->w_height)
			mlx_put_pixel(frame.img, x, y + i, 0xAF5050FF);
		else if (x + i < 0)
			mlx_put_pixel(frame.img, x, 0, 0xAF5050FF);
		else
			mlx_put_pixel(frame.img, x, m_edit->w_height - 1, 0xAF5050FF);
	}
}

void	cd_map_printer(void *vm_edit)
{
	int					y;
	int					x;
	struct timeval		time;
	t_map_editor		*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	gettimeofday(&time, NULL);
	if (m_edit->fps)
		mlx_delete_image(m_edit->mlx, m_edit->fps);
	y = -1;
	while (++y < m_edit->w_height)
	{
		x = -1;
		while (++x < m_edit->w_width)
			cd_print_map(m_edit, x, y);
	}
	cd_place_mouse(m_edit, m_edit->frame);
	m_edit->fps = cd_slow_down(m_edit, time, 60, 1);
	mlx_resize_image(m_edit->fps, m_edit->fps->width - 3,
		m_edit->fps->height - 3);
}
