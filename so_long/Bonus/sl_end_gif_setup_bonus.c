/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_gif_setup_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:32:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 19:31:51 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_start_end_gif(t_map_info *map_info)
{
	t_end_gif	*end_gif;

	end_gif = malloc(sizeof(*end_gif));
	if (map_info->has_won == 0)
	{
		end_gif->path = "images/end/win/";
		system("paplay --volume=25000 sounds/9.wav &");
		end_gif->sound_frame = 645;
	}
	else
	{
		end_gif->path = "images/end/loose/";
		system("paplay --volume=25000 sounds/10.wav &");
		end_gif->sound_frame = 210;
	}
	write(1, "\E[H\E[2J", 7);
	sl_get_end_gif(map_info, end_gif);
	map_info->end_gif = end_gif;
	mlx_loop_hook(map_info->mlx, &sl_end_gif_loop, map_info);
	mlx_loop(map_info->mlx);
	sl_lstclear(map_info->mlx, end_gif->img_stack);
	free(end_gif->img_stack);
	free(end_gif);
	system("killall paplay $!");
	write(1, "\E[H\E[2J", 7);
}

void	sl_end_gif_loop(void *vmap_info)
{
	t_end_gif	*end_gif;
	t_map_info	*map_info;

	map_info = (t_map_info *)vmap_info;
	end_gif = map_info->end_gif;
	if (--end_gif->sound_frame % 4 == 0)
	{
		if (++end_gif->gif_frame > ft_lstsize(*end_gif->img_stack))
			end_gif->gif_frame = 0;
		if (end_gif->sound_frame % 128 == 0)
			sl_add_an_instance(map_info, end_gif);
		sl_animate_all_instances(end_gif);
	}
	if (end_gif->sound_frame == 0)
	{
		if (--end_gif->loops > 0)
			end_gif->sound_frame = 5000;
		else
			mlx_close_window(map_info->mlx);
		sl_redo_end_song(end_gif);
	}
}

void	sl_add_an_instance(t_map_info *map_info, t_end_gif *end_gif)
{
	t_img_stack	*stk;
	t_x_y		pos;

	if (end_gif->nb_instances > 30)
		return ;
	stk = *end_gif->img_stack;
	end_gif->nb_instances++ ;
	pos = sl_get_rand_pos(map_info);
	while (stk != NULL)
	{
		mlx_image_to_window(map_info->mlx, stk->img, pos.x, pos.y);
		stk->img->instances[end_gif->nb_instances - 1].enabled = 0;
		stk = stk->next;
	}
}

void	sl_animate_all_instances(t_end_gif *end_gif)
{
	t_img_stack	*stk;
	t_img_stack	*tp_stk;
	int			i;

	i = -1;
	while (++i < end_gif->nb_instances)
	{
		stk = *end_gif->img_stack;
		while (stk != NULL && stk->img->instances[i].enabled == 0)
			stk = stk->next;
		if (stk != NULL && stk->img->instances[i].enabled == 1)
		{
			if (stk->next != NULL)
				tp_stk = stk->next;
			else
				tp_stk = *end_gif->img_stack;
			tp_stk->img->instances[i].enabled = 1;
			stk->img->instances[i].enabled = 0;
		}
		else
			(*end_gif->img_stack)->img->instances[i].enabled = 1;
	}
}

void	sl_get_end_gif(t_map_info *map_info, t_end_gif *end_gif)
{
	char	*png;
	int		i;

	i = 1;
	sl_hide_everything(map_info, *map_info->hive->bees);
	mlx_set_window_size(map_info->mlx, 1500, 800);
	mlx_set_window_pos(map_info->mlx, 200, 165);
	end_gif->img_stack = malloc(sizeof(**end_gif->img_stack));
	*end_gif->img_stack = 0;
	end_gif->nb_instances = 0;
	end_gif->gif_frame = 0;
	end_gif->loops = 2 + map_info->total_moves / 70;
	end_gif->loops += end_gif->loops * 3 * map_info->has_won;
	png = sl_get_png(end_gif->path, ft_itoa(i));
	while (png != NULL && ++i > 0)
	{
		sl_custom_addback(map_info, png, end_gif->img_stack, 'E');
		free(png);
		png = sl_get_png(end_gif->path, ft_itoa(i));
	}
	sl_add_an_instance(map_info, end_gif);
}
