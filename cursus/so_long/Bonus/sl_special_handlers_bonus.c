/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_special_handlers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:45:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 19:32:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_win_stop(t_map_info *map_info)
{
	char	*emoji;

	emoji = malloc(4);
	emoji[0] = 0xF0;
	emoji[1] = 0x9F;
	emoji[2] = 0x98;
	emoji[3] = 0x8F;
	write(1, "\E[H\E[2J", 7);
	write(1, "W rizz ", 7);
	write(1, emoji, 4);
	free(emoji);
	write(1, "\n", 1);
	write(1, "You finished with ", 18);
	ft_putnbr(map_info->total_moves);
	write(1, " moves played\n", 14);
	mlx_close_window(map_info->mlx);
}

void	sl_single_key_handler(mlx_key_data_t keydata, void *map_info_void)
{
	t_map_info	*mp_inf;

	mp_inf = (t_map_info *)map_info_void;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mp_inf->mlx);
	if (mlx_is_key_down(mp_inf->mlx, MLX_KEY_A) && sl_next(mp_inf, -1))
		sl_move_player(mp_inf, -1);
	else if (mlx_is_key_down(mp_inf->mlx, MLX_KEY_D) && sl_next(mp_inf, 1))
		sl_move_player(mp_inf, 1);
	else if (mlx_is_key_down(mp_inf->mlx, MLX_KEY_W) && sl_next(mp_inf, -10))
		sl_move_player(mp_inf, -10);
	else if (mlx_is_key_down(mp_inf->mlx, MLX_KEY_S) && sl_next(mp_inf, 10))
		sl_move_player(mp_inf, 10);
}

void	sl_handle_extra_floor(t_map_info mp_inf, t_img_stack **floor)
{
	int			i;
	int			ii;
	int			x;
	int			y;

	i = -1;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			if (mp_inf.map[i][ii] != '0')
			{
				x = ii * 42 + 16;
				y = i * 42 + 16;
				sl_add_back(floor, &mp_inf, '0', mp_inf.size);
				mlx_image_to_window(mp_inf.mlx, ft_lstlast(*floor)->img, x, y);
			}
		}
	}
}

int	sl_mlx_handler(t_map_info map_info, t_img_stack *floor)
{
	int	x;
	int	y;

	x = map_info.size.x * 42 + 32;
	y = map_info.size.y * 42 + 32;
	map_info.mlx = mlx_init(x, y, "So Long", false);
	if (!map_info.mlx)
		return (0);
	sl_handle_extra_floor(map_info, &floor);
	sl_load_players(&map_info, "player_unwin_bonus");
	sl_load_players(&map_info, "");
	sl_create_img(map_info, map_info.img_stack);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);
	mlx_key_hook(map_info.mlx, &sl_single_key_handler, (void *)&map_info);
	mlx_loop(map_info.mlx);
	sl_free_t_map_info(&map_info);
	sl_lstclear(map_info.mlx, map_info.img_stack);
	sl_lstclear(map_info.mlx, &floor);
	// sl_lstclear(map_info.mlx, map_info.players.win);
	// sl_lstclear(map_info.mlx, map_info.players.nowin);
	mlx_terminate(map_info.mlx);
	return (1);
}

int	sl_next(t_map_info *map_info, int way)
{
	int			index;
	int			x;
	int			y;
	char		link_type;

	x = map_info->players.xy.x;
	y = map_info->players.xy.y;
	x += way % 10;
	y += way / 10;
	index = (y * map_info->size.x) + x;
	link_type = sl_link_finder(*map_info->img_stack, index)->type;
	if (link_type == '1' || (link_type == 'E' && map_info->c_num > 0))
		return (0);
	return (1);
}
