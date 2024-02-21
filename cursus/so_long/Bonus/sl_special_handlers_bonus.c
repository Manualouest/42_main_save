/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_special_handlers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:45:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/21 16:28:35 by mbirou           ###   ########.fr       */
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
	write(1, "Good job ", 9);
	write(1, emoji, 4);
	free(emoji);
	write(1, "\n", 1);
	write(1, "You finished with ", 18);
	ft_putnbr(map_info->total_moves);
	write(1, " moves played\n", 14);
	mlx_close_window(map_info->mlx);
}

void	sl_repeat_key_handler(mlx_key_data_t keydata, t_map_info *mp_inf)
{
	if (keydata.key == MLX_KEY_A
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, -1, 1);
	else if (keydata.key == MLX_KEY_D
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, 1, 1);
	else if (keydata.key == MLX_KEY_W
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, -10, 1);
	else if (keydata.key == MLX_KEY_S
		&& mp_inf->gifs->player_frame % 4 == 0)
		sl_move_player(mp_inf, 10, 1);
}

void	sl_key_handler(mlx_key_data_t keydata, void *map_info_void)
{
	t_map_info	*mp_inf;

	mp_inf = (t_map_info *)map_info_void;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mp_inf->mlx);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, -1, 0);
		else if (keydata.key == MLX_KEY_D && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, 1, 0);
		else if (keydata.key == MLX_KEY_W && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, -10, 0);
		else if (keydata.key == MLX_KEY_S && keydata.action != MLX_REPEAT)
			sl_move_player(mp_inf, 10, 0);
	}
	if (keydata.action == MLX_REPEAT)
		sl_repeat_key_handler(keydata, mp_inf);
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

void	sl_show_png(t_img_stack *stk, t_map_info *map_info, t_x_y xy)
{
	mlx_image_to_window(map_info->mlx, stk->img,
		xy.x * 42 + 16, xy.y * 42 + 16);
	stk->is_shown = 1;
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
		if (stk->next)
			stk = stk->next;
		else
			stk = (*exit);
		if (stk->is_shown == 0)
			sl_show_png(stk, mp_inf, mp_inf->gifs->exit);
		stk->img->instances->enabled = 1;
	}
}

void	sl_free_png(t_map_info *map_info, t_img_stack **floor)
{
	sl_free_t_map_info(map_info);
	sl_lstclear(map_info->mlx, map_info->img_stack);
	sl_lstclear(map_info->mlx, floor);
	sl_lstclear(map_info->mlx, map_info->gifs->win);
	sl_lstclear(map_info->mlx, map_info->gifs->nowin);
	sl_lstclear(map_info->mlx, map_info->gifs->idle);
	sl_lstclear(map_info->mlx, map_info->gifs->angry);
	sl_lstclear(map_info->mlx, map_info->gifs->happy);
	sl_lstclear(map_info->mlx, map_info->gifs->shy);
	sl_lstclear(map_info->mlx, map_info->gifs->ok);
	sl_lstclear(map_info->mlx, map_info->gifs->cry);
	sl_lstclear(map_info->mlx, map_info->gifs->sus);
	free(map_info->gifs->win);
	free(map_info->gifs->nowin);
	free(map_info->gifs->idle);
	free(map_info->gifs->angry);
	free(map_info->gifs->happy);
	free(map_info->gifs->shy);
	free(map_info->gifs->ok);
	free(map_info->gifs->cry);
	free(map_info->gifs->sus);
	sl_lstclear(map_info->mlx, map_info->counter->counter_move);
	free(map_info->counter->counter_move);
	sl_lstclear(map_info->mlx, map_info->counter->counter_collect);
	free(map_info->counter->counter_collect);
}

t_gifs	sl_init_gifs(t_map_info *map_info)
{
	t_gifs		gifs;

	gifs.player_frame = 0;
	gifs.exit_frame = 0;
	gifs.player_type = 0;
	gifs.exit_type = 0;
	gifs.exit = sl_get_exit(*map_info);
	gifs.xy = sl_get_player(*map_info);
	sl_create_players(map_info, &gifs);
	sl_create_exits(map_info, &gifs);
	return (gifs);
}

int	sl_mlx_handler(t_map_info map_info, t_img_stack **floor)
{
	t_gifs		gifs;
	t_counter	counter;
	int			x;
	int			y;

	x = map_info.size.x * 42 + 32;
	y = map_info.size.y * 42 + 32;
	map_info.mlx = mlx_init(x, y, "So Long", false);
	if (!map_info.mlx)
		return (0);
	sl_create_img(map_info, map_info.img_stack);
	sl_handle_extra_floor(map_info, floor);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);
	gifs = sl_init_gifs(&map_info);
	map_info.gifs = &gifs;
	sl_init_counter(&map_info, &counter);
	map_info.counter = &counter;
	sl_update_moves(&map_info);
	mlx_key_hook(map_info.mlx, &sl_key_handler, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_player, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_exit_main, (void *)&map_info);
	mlx_loop(map_info.mlx);
	sl_free_png(&map_info, floor);
	mlx_terminate(map_info.mlx);
	return (1);
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
	link_type = map_info->map[y][x];
	if (link_type == '1' || (link_type == 'E' && map_info->c_num > 0))
		return (0);
	return (1);
}
