/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:20:36 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/27 09:25:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cd_switch_display(t_info *info, int target_display)
{
	if (info->current_display != target_display)
		info->current_display = target_display;
	else
	{
		info->current_display = 1;
		mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win,
			info->mlx_info->w_width / 2.0, info->mlx_info->w_height / 2.0);
	}
}

int	cd_update_frame(t_info *info)
{
	struct timeval	time;
	time_t			secs;
	suseconds_t		usecs;
	char			*fps;

	gettimeofday(&time, NULL);
	secs = time.tv_sec;
	usecs = time.tv_usec;
	if (info->current_display == 1)
	{
		cd_move_player(info);
		cd_raycast(info);
		cd_add_minimap(info);
	}
	else if (info->current_display == 2)
		cd_minimap_editor(info);
	cd_put_mouse(info);
	mlx_put_image_to_window(info->mlx_info->mlx, info->mlx_info->mlx_win,
		info->mlx_info->main_frame->img, 0, 0);
	gettimeofday(&time, NULL);
	if (secs == time.tv_sec)
	{
		fps = ft_itoa((1000000 / (time.tv_usec - usecs)));
		if ((1000000 / (time.tv_usec - usecs)) > 60)
		{
			usleep(16666 - (time.tv_usec - usecs));
			fps = ft_itoa(60);
		}
		mlx_string_put(info->mlx_info->mlx, info->mlx_info->mlx_win, 1, 10, cd_invert_color(cd_get_color(info->mlx_info->main_frame, 6, 15)), fps);
		free(fps);
	}
	return (0);
}
