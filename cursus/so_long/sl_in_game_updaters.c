/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_in_game_updates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:39:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/08 05:47:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

void	sl_update_moves(t_map_info *map_info)
{
	if (map_info->total_moves > 0)
		write(1, "\E[H\E[2J", 7);
	map_info->total_moves ++;
	write(1, "Moves played: ", 14);
	ft_putnbr(map_info->total_moves);
	write(1, "\n", 1);
	if (map_info->c_num > 0)
	{
		write(1, "Collectibles left: ", 19);
		ft_putnbr(map_info->c_num);
	}
	else
		write(1, "GO GIVE THEM NOW!", 17);
	write(1, "\n", 1);
}

void	sl_change_exit(t_map_info *map_info, int old_type, int ex, int ey)
{
	int			x;
	int			y;
	t_img_stack	*tp_stk;

	x = map_info->player.x;
	y = map_info->player.y;
	tp_stk = sl_link_finder(*map_info->img_stack, (ey * map_info->size.x) + ex);
	if (((x - ex <= 3 && x - ex >= 0) || (ex - x <= 3 && ex - x >= 0))
		&& ((y - ey <= 3 && y - ey >= 0) || (ey - y <= 3 && ey - y >= 0))
		&& map_info->exit_type != 0)
		map_info->exit_type = 2;
	else if (map_info->exit_type == 2)
		map_info->exit_type = 3;
	if (map_info->c_num <= 0 && map_info->exit_type == 0)
		map_info->exit_type = 1;
	x = ex * 42 + 16;
	y = ey * 42 + 16;
	if (map_info->exit_type != old_type)
		sl_redo_link(tp_stk, map_info, 'E');
	if (map_info->exit_type != old_type)
		mlx_image_to_window(map_info->mlx, tp_stk->img, x, y);
}

void	sl_change_player(t_map_info *map_info)
{
	int	x;
	int	y;

	x = map_info->player.x * 42 + 16;
	y = map_info->player.y * 42 + 16;
	sl_redo_link(*map_info->player_img, map_info, 'P');
	mlx_image_to_window(map_info->mlx, (*map_info->player_img)->img, x, y);
	map_info->c_num = -2;
}

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack	*tp_link;
	int			index;
	int			x;
	int			y;

	mp_inf->player.x += way % 10;
	mp_inf->player.y += way / 10;
	(*mp_inf->player_img)->img->instances->x = mp_inf->player.x * 42 + 16;
	(*mp_inf->player_img)->img->instances->y = mp_inf->player.y * 42 + 16;
	index = (mp_inf->player.y * mp_inf->size.x) + mp_inf->player.x;
	x = mp_inf->player.x * 42 + 16;
	y = mp_inf->player.y * 42 + 16;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'C')
		tp_link->img->instances->enabled = 0;
	if (tp_link->type == 'E')
		index = -1;
	sl_update_moves(mp_inf);
	if (index == -1)
		sl_win_stop(mp_inf);
	sl_change_exit(mp_inf, mp_inf->exit_type, mp_inf->exit.x, mp_inf->exit.y);
	if (mp_inf->c_num == 0)
		sl_change_player(mp_inf);
}

int	sl_next(t_map_info *map_info, int way)
{
	int			index;
	int			x;
	int			y;
	char		link_type;

	x = map_info->player.x;
	y = map_info->player.y;
	x += way % 10;
	y += way / 10;
	index = (y * map_info->size.x) + x;
	link_type = sl_link_finder(*map_info->img_stack, index)->type;
	if (link_type == '1' || (link_type == 'E' && map_info->c_num > 0))
		return (0);
	else if (link_type == 'C')
		map_info->c_num --;
	return (1);
}
