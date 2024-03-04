/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hive_handler_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:17:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/04 01:46:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_animate_hive(void *map_info)
{
	t_hive	*hive;

	hive = ((t_map_info *)map_info)->hive;
	if (hive->hive_frame++ % 4 == 0)
	{
		if (hive->flowers_brought > (hive->bee_count * 2)
			* hive->honey_level)
			sl_instant_add_png((t_map_info *)map_info, hive->hive_bot,
				HIVE_BOT, hive->honey_level++);
		if (sl_link_finder(*hive->hive_bot, hive->honey_level)->is_shown == 0)
			sl_show_png(sl_link_finder(*hive->hive_bot, hive->honey_level), 
				(t_map_info *)map_info, hive->hive_pos);
	}
}