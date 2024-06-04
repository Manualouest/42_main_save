/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:23:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 20:26:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_repeat_key_handler(mlx_key_data_t keydata, t_map_info *mp_inf)
{
	if (keydata.key == MLX_KEY_A
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, -1);
	else if (keydata.key == MLX_KEY_D
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, 1);
	else if (keydata.key == MLX_KEY_W
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, -10);
	else if (keydata.key == MLX_KEY_S
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, 10);
}

void	sl_key_handler(mlx_key_data_t keydata, void *map_info_void)
{
	t_map_info	*mp_inf;

	mp_inf = (t_map_info *)map_info_void;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		system("killall paplay $!");
		write(1, "\E[H\E[2J", 7);
		mlx_close_window(mp_inf->mlx);
	}
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, -1);
		else if (keydata.key == MLX_KEY_D && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, 1);
		else if (keydata.key == MLX_KEY_W && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, -10);
		else if (keydata.key == MLX_KEY_S && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, 10);
	}
	if (keydata.action == MLX_REPEAT)
		sl_repeat_key_handler(keydata, mp_inf);
}

void	sl_show_png(t_img_stack *stk, t_map_info *map_info, t_x_y xy)
{
	mlx_image_to_window(map_info->mlx, stk->img,
		xy.x * 42 + 16, xy.y * 42 + 16);
	stk->is_shown = 1;
}

int	sl_next(t_map_info *map_info, int way)
{
	int			x;
	int			y;
	char		link_type;

	x = map_info->gifs->xy.x;
	y = map_info->gifs->xy.y;
	x += way % 10;
	y += way / 10;
	if (map_info->mlx->width == 1500)
		return (0);
	link_type = map_info->map[y][x];
	if (link_type == '1' || link_type == 'H'
		|| (link_type == 'E' && map_info->c_num > 0))
		return (0);
	return (1);
}

t_gifs	sl_init_gifs(t_map_info *map_info)
{
	t_gifs		gifs;

	gifs.player_frame = 0;
	gifs.exit_frame = 0;
	gifs.player_type = 0;
	gifs.exit_type = 0;
	gifs.exit_sound_frame = -1;
	gifs.exit = sl_get_exit(*map_info);
	gifs.xy = sl_get_player(*map_info);
	sl_create_players(map_info, &gifs);
	sl_create_exits(map_info, &gifs);
	return (gifs);
}
