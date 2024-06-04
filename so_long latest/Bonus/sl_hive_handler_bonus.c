/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hive_handler_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:17:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 20:42:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_show_top_hive(t_img_stack *stk, t_map_info *map_info, t_x_y xy)
{
	mlx_image_to_window(map_info->mlx, stk->img,
		xy.x * 42 + 24, xy.y * 42 + 24);
	stk->is_shown = 1;
}

void	sl_hive_radar_check(t_map_info *map_info, t_hive *hive)
{
	t_bees	*bees;

	if (sl_is_in_circle(*map_info, hive->honey_level, hive->hive_pos.x,
			hive->hive_pos.y))
	{
		bees = *hive->bees;
		while (bees != NULL)
		{
			bees->is_angry = 1;
			bees = bees->next;
		}
	}
}

void	sl_handle_bottom_hive(t_map_info *map_info, t_hive *hive)
{
	if (hive->flowers_brought >= (hive->bee_count + hive->bee_count / 2)
		* hive->honey_level && hive->honey_level < 5
		&& map_info->mlx->width != 1500)
	{
		sl_lstclear(map_info->mlx, hive->hive_bot);
		sl_instant_add_png(map_info, hive->hive_bot,
			HIVE, ++hive->honey_level);
		sl_show_png(*hive->hive_bot, (t_map_info *)map_info, hive->hive_pos);
	}
	if (ft_lstsize(*hive->hive_top) <= (*hive->hive_top)->gif_len
		&& map_info->mlx->width != 1500)
	{
		sl_lstclear(map_info->mlx, hive->hive_bot);
		sl_instant_add_png(map_info, hive->hive_bot, HIVE, hive->honey_level);
		sl_show_png(*hive->hive_bot, (t_map_info *)map_info, hive->hive_pos);
		(*hive->hive_bot)->is_shown = 0;
	}
	else if (ft_lstsize(*hive->hive_top) == (*hive->hive_top)->gif_len + 1
		&& (*hive->hive_bot)->is_shown == 0 && map_info->mlx->width != 1500)
	{
		sl_lstclear(map_info->mlx, hive->hive_bot);
		sl_instant_add_png(map_info, hive->hive_bot, HIVE, hive->honey_level);
		sl_show_png(*hive->hive_bot, (t_map_info *)map_info, hive->hive_pos);
	}
	sl_hive_radar_check(map_info, hive);
}

void	sl_animate_hive(void *map_info)
{
	t_hive		*hive;
	t_img_stack	*stk;

	hive = ((t_map_info *)map_info)->hive;
	if (hive->hive_frame++ % 8 != 0)
		return ;
	if (hive->hive_frame > (*hive->hive_top)->gif_len * 8)
		hive->hive_frame = 0;
	if (ft_lstsize(*hive->hive_top) < (*hive->hive_top)->gif_len)
		sl_instant_add_png((t_map_info *)map_info, hive->hive_top,
			HIVE_TOP, hive->hive_frame / 8 + 1);
	stk = sl_link_finder(*hive->hive_top, hive->hive_frame / 8);
	if (stk->is_shown == 0)
		sl_show_top_hive(stk, (t_map_info *)map_info, hive->hive_pos);
	else
		stk->img->instances->enabled = 1;
	if (hive->hive_frame / 8 == 0
		&& ft_lstsize(*hive->hive_top) == (*hive->hive_top)->gif_len)
		sl_link_finder(*hive->hive_top, (*hive->hive_top)->gif_len)
		->img->instances->enabled = 0;
	else if (hive->hive_frame / 8 != 0)
		sl_link_finder(*hive->hive_top, hive->hive_frame / 8 - 1)
		->img->instances->enabled = 0;
	sl_handle_bottom_hive((t_map_info *)map_info, hive);
	sl_anime_bees_main(hive, map_info);
}
