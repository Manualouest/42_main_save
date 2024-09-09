/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:46:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/09 15:59:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

// void	cd_change_pixel_color(t_img_info frame, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = frame.addr + (y * frame.line_size + x * (frame.bpp / 8));
// 	if (dst)
// 		*(unsigned int*)dst = color;
// }

int	cd_get_pixel_kind(t_p_vars p_vars, int x, int y)
{
	if (x < p_vars.left_gap || x >= p_vars.right_gap
		|| y < p_vars.up_gap || y >= p_vars.down_gap
		|| (x - p_vars.left_gap) % 25== 0 || (y - p_vars.up_gap) % 25== 0)
		return (1);
	return (0);
}

void	cd_slow_down(t_map_editor *m_edit, struct timeval start_time)
{
	struct timeval	end_time;
	char			*fps;
	int				start;
	int				end;

	gettimeofday(&end_time, NULL);
	start = start_time.tv_sec * 1000000 + start_time.tv_usec;
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	// printf("%d\n", end - start);
	if (end - start < 16666) //16666
		usleep(16666 - (end - start)); //16666
	gettimeofday(&end_time, NULL);
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	// printf("2-%d, %d\n", end - start, 1000000 / (end - start));
	fps = ft_itoa(1000000 / (end - start));
	mlx_put_string(m_edit->mlx, fps, 5, -3);
	free(fps);
}

void	cd_map_printer(void *vm_edit)
{
	int				y;
	int				x;
	int				pixel_kind;
	struct timeval	time;
	t_map_editor	*m_edit;

	m_edit = (t_map_editor *)vm_edit;
	gettimeofday(&time, NULL);
	if (m_edit->keys.stopper)
		return ;
	y = -1;
	while (++y < m_edit->w_height)
	{
		x = -1;
		while (++x < m_edit->w_width)
		{
			pixel_kind = cd_get_pixel_kind(m_edit->p_vars, x, y);
			if (pixel_kind == 1)
				mlx_put_pixel(m_edit->frame.img, x, y, 0x000000FF);
			else
				mlx_put_pixel(m_edit->frame.img, x, y, 0xFFFFFFFF);
		}
	}
	cd_slow_down(m_edit, time);
	mlx_image_to_window(m_edit->mlx, m_edit->frame.img, 0, 0);
}
