/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hive_setup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:48:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/06 16:53:22 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_hive_init(t_map_info *map_info, t_hive *hive)
{
	if (map_info->c_num <= 8)
		hive->bee_count = (int)((float)map_info->c_num / 2 + 0.5);
	else
		hive->bee_count = 4;
	hive->hive_pos = sl_get_hive_pos(map_info);
	hive->size = map_info->size;
	sl_place_hive(hive, map_info);
	if (sl_check_try(map_info, hive->hive_pos, map_info->gifs->xy) == 0)
		hive->hive_pos.x = 0;
	hive->honey_level = 1;
	hive->flowers_brought = 0;
	hive->hive_frame = 0;
	hive->bees = malloc(sizeof(**hive->bees));
	*hive->bees = sl_create_bees(map_info, hive);
	hive->hive_bot = malloc(sizeof(**hive->hive_bot));
	*hive->hive_bot = 0;
	sl_instant_add_png(map_info, hive->hive_bot, HIVE, 1);
	(*hive->hive_bot)->gif_len = 5;
	hive->hive_top = malloc(sizeof(**hive->hive_top));
	*hive->hive_top = 0;
	sl_instant_add_png(map_info, hive->hive_top, HIVE_TOP, 1);
	(*hive->hive_top)->gif_len = 20;
	map_info->hive = hive;
}

t_bees	*sl_create_bees(t_map_info *map_info, t_hive *hive)
{
	int		i;
	t_bees	*bees;
	t_bees	*first;

	i = -1;
	bees = malloc(sizeof(*bees));
	first = bees;
	while (++i < hive->bee_count)
	{
		bees->num = sl_get_bee_num(i);
		bees->is_angry = 0;
		bees->way = 0;
		bees->bee_frame = i * 4;
		bees->wait_frame = i;
		bees->bee_pos = hive->hive_pos;
		bees->target = hive->hive_pos;
		bees->img_stack = malloc(sizeof(**bees->img_stack));
		*bees->img_stack = sl_insert_bees(map_info, hive);
		if (i < hive->bee_count - 1)
			bees->next = malloc(sizeof(struct s_bees));
		else
			bees->next = NULL;
		bees = bees->next;
	}
	return (first);
}

t_img_stack	*sl_insert_bees(t_map_info *map_info, t_hive *hive)
{
	int			i;
	char		*num;
	char		*png;
	t_img_stack	*stk;

	i = 0;
	stk = 0;
	while (++i <= 4)
	{
		num = ft_itoa(i);
		png = sl_get_png(BEE, num);
		sl_custom_addback(map_info, png, &stk, 'B');
		free(png);
	}
	(void)hive;
	return (stk);
}

void	sl_place_hive(t_hive *hive, t_map_info *map_info)
{
	int		rad;
	t_x_y	pos;

	rad = 0;
	while (++rad < (hive->size.x + hive->size.y)
		&& map_info->map[hive->hive_pos.y][hive->hive_pos.x] != '0')
	{
		pos = sl_scanner_vertical(hive, map_info, rad);
		if (sl_check_try(map_info, pos, map_info->gifs->xy) == 1)
			break ;
		pos = sl_scanner_horizontal(hive, map_info, rad);
		if (sl_check_try(map_info, pos, map_info->gifs->xy) == 1)
			break ;
	}
	if (map_info->map[hive->hive_pos.y][hive->hive_pos.x] != '0' && pos.x != 0)
	{
		map_info->map[pos.y][pos.x] = 'H';
		map_info->map_copy[pos.y][pos.x] = 'H';
		hive->hive_pos = pos;
	}
	else if (sl_check_try(map_info, hive->hive_pos, map_info->gifs->xy))
	{
		map_info->map[hive->hive_pos.y][hive->hive_pos.x] = 'H';
		map_info->map_copy[hive->hive_pos.y][hive->hive_pos.x] = 'H';
	}
}

int	sl_check_try(t_map_info *map_info, t_x_y pos, t_x_y xy)
{
	int		y;
	int		x;

	y = -1;
	map_info->map_copy[pos.y][pos.x] = 'H';
	sl_path_check_utils(map_info, xy.x, xy.y);
	while (++y >= 0 && map_info->map_copy[y] != 0)
	{
		x = -1;
		while (y >= 0 && map_info->map_copy[y][++x] != 0)
			if (map_info->map_copy[y][x] == 'P'
				|| map_info->map_copy[y][x] == 'C'
				|| map_info->map_copy[y][x] == 'E'
				|| map_info->map_copy[y][x] == 'H')
				y = -5;
	}
	x = -1;
	while (map_info->map_copy[++x] != 0)
		free(map_info->map_copy[x]);
	free(map_info->map_copy[x]);
	free(map_info->map_copy);
	sl_redo_map_copy(map_info);
	if (y < 0)
		return (0);
	return (1);
}
