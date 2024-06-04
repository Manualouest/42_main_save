/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:17:15 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 21:15:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_anime_player(void *mp_info)
{
	t_img_stack	*stk;
	t_img_stack	**player;
	t_map_info	*map_info;

	map_info = (t_map_info *)mp_info;
	if (map_info->gifs->player_frame++ % 4 == 0)
	{
		if (map_info->gifs->player_type == 0)
			player = map_info->gifs->nowin;
		else
			player = map_info->gifs->win;
		if (map_info->gifs->player_frame > ((*player)->gif_len + 1) * 4 + 1
			&& map_info->gifs->player_type == 0)
			map_info->gifs->player_frame = 0;
		else if (map_info->gifs->player_frame > ((*player)->gif_len + 1)
			* 4 + 1 && map_info->gifs->player_type == 1)
			map_info->gifs->player_frame = 28;
		stk = sl_link_finder(*player, map_info->gifs->player_frame / 4);
		if (stk->is_shown == 0)
			sl_show_png(stk, map_info, map_info->gifs->xy);
		stk->img->instances->enabled = 0;
		sl_update_pos(stk, player, map_info);
	}
}

void	sl_update_pos(t_img_stack *stk, t_img_stack **curr,
	t_map_info *map_info)
{
	if (ft_lstsize(*curr) <= (*curr)->gif_len)
		sl_instant_add_png(map_info, curr, (*curr)->path,
			map_info->gifs->player_frame / 4);
	if (stk->next)
		stk = stk->next;
	else
	{
		if (map_info->gifs->player_type == 0)
			stk = (*curr);
		else
			stk = sl_link_finder(*curr, 7);
	}
	if (stk->is_shown == 0)
		sl_show_png(stk, map_info, map_info->gifs->xy);
	stk->img->instances->enabled = 1;
	if (stk->img->instances->x != map_info->gifs->xy.x && map_info->way != 2)
		stk->img->instances->x = map_info->gifs->xy.x * 42 + 16;
	if (stk->img->instances->y != map_info->gifs->xy.y && map_info->way != 2)
		stk->img->instances->y = map_info->gifs->xy.y * 42 + 16;
}

void	sl_anime_get_exit(t_img_stack	***exit, t_map_info	*mp_inf)
{
	if (mp_inf->gifs->exit_type == 0)
		*exit = mp_inf->gifs->idle;
	else if (mp_inf->gifs->exit_type == 1)
		*exit = mp_inf->gifs->angry;
	else if (mp_inf->gifs->exit_type == 2)
		*exit = mp_inf->gifs->happy;
	else if (mp_inf->gifs->exit_type == 3)
		*exit = mp_inf->gifs->shy;
	else if (mp_inf->gifs->exit_type == 4)
		*exit = mp_inf->gifs->ok;
	else if (mp_inf->gifs->exit_type == 5)
		*exit = mp_inf->gifs->cry;
	else
		*exit = mp_inf->gifs->sus;
}

t_img_stack	*sl_get_next_exit_png(t_img_stack *stk, t_img_stack **exit)
{
	if (stk->next)
		return (stk->next);
	else
		return (*exit);
}

void	sl_anime_exit_main(void *map_info)
{
	t_img_stack	*stk;
	t_img_stack	**exit;
	t_map_info	*mp_inf;

	mp_inf = (t_map_info *)map_info;
	if (mp_inf->gifs->exit_frame++ % 4 != 0)
	{
		sl_anime_get_exit(&exit, mp_inf);
		if (mp_inf->gifs->exit_frame > ft_lstsize(*exit) * 4)
			mp_inf->gifs->exit_frame = 0;
		stk = sl_link_finder(*exit, mp_inf->gifs->exit_frame / 4);
		if (stk->is_shown == 0)
			sl_show_png(stk, mp_inf, mp_inf->gifs->exit);
		stk->img->instances->enabled = 0;
		if (ft_lstsize(*exit) <= (*exit)->gif_len)
			sl_instant_add_png(mp_inf, exit, (*exit)->path,
				mp_inf->gifs->exit_frame);
		stk = sl_get_next_exit_png(stk, exit);
		if (stk->is_shown == 0)
			sl_show_png(stk, mp_inf, mp_inf->gifs->exit);
		stk->img->instances->enabled = 1;
	}
	sl_handle_exit_sound(mp_inf->gifs, map_info);
}
