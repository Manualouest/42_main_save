/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_special_handlers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:45:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/15 22:53:08 by mbirou           ###   ########.fr       */
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

void	sl_update_pos(t_img_stack *stk, t_img_stack **curr, t_map_info *map_info)
{
	if (stk->next)
		stk = stk->next;
	else
		stk = (*curr);
	stk->img->instances->enabled = 1;
	if (stk->img->instances->x != map_info->gifs->xy.x)
		stk->img->instances->x = map_info->gifs->xy.x * 42 + 16;
	if (stk->img->instances->y != map_info->gifs->xy.y)
		stk->img->instances->y = map_info->gifs->xy.y * 42 + 16;
}

void	sl_anime_player(void *mp_info)
{
	t_img_stack	*stk;
	t_img_stack	**curr;
	t_map_info	*map_info;

	map_info = (t_map_info *)mp_info;
	if (map_info->gifs->player_frame % 4 != 0)
	{
		map_info->gifs->player_frame ++;
		return ;
	}
	if (map_info->gifs->player_type == 0)
		curr = map_info->gifs->nowin;
	else
		curr = map_info->gifs->win;
	if (map_info->gifs->player_frame > ft_lstsize(*curr) * 4)
		map_info->gifs->player_frame = 1;
	stk = sl_link_finder(*curr, map_info->gifs->player_frame / 4);
	stk->img->instances->enabled = 0;
	sl_update_pos(stk, curr, map_info);
	map_info->gifs->player_frame ++;
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
	if (mp_inf->gifs->exit_frame % 4 != 0)
	{
		mp_inf->gifs->exit_frame ++;
		return ;
	}
	sl_anime_get_exit(&exit, mp_inf);
	if (mp_inf->gifs->exit_frame > ft_lstsize(*exit) * 4)
		mp_inf->gifs->exit_frame = 1;
	stk = sl_link_finder(*exit, mp_inf->gifs->exit_frame / 4);
	stk->img->instances->enabled = 0;
	if (stk->next)
		stk->next->img->instances->enabled = 1;
	else
		(*exit)->img->instances->enabled = 1;
	mp_inf->gifs->exit_frame ++;
}

int	sl_mlx_handler(t_map_info map_info, t_img_stack **floor)
{
	t_gifs		gifs;
	int			x;
	int			y;

	x = map_info.size.x * 42 + 32;
	y = map_info.size.y * 42 + 32;
	map_info.mlx = mlx_init(x, y, "So Long", false);
	if (!map_info.mlx)
		return (0);

	gifs.player_frame = 0;
	gifs.exit_frame = 0;
	gifs.player_type = 0;
	gifs.exit_type = 0;

	gifs.exit = sl_get_exit(map_info);
	gifs.xy = sl_create_img(map_info, map_info.img_stack);
	sl_handle_extra_floor(map_info, floor);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);

	sl_create_players(&map_info, &gifs);
	sl_create_exits(&map_info, &gifs);
	map_info.gifs = &gifs;
	sl_show_gif(map_info.mlx, *map_info.gifs->win, map_info.gifs->xy);
	sl_show_gif(map_info.mlx, *map_info.gifs->nowin, map_info.gifs->xy);

	sl_show_gif(map_info.mlx, *map_info.gifs->idle, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->angry, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->happy, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->shy, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->ok, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->cry, map_info.gifs->exit);
	sl_show_gif(map_info.mlx, *map_info.gifs->sus, map_info.gifs->exit);
	
	mlx_key_hook(map_info.mlx, &sl_single_key_handler, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_player, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_exit_main, (void *)&map_info);

	mlx_loop(map_info.mlx);
	sl_free_t_map_info(&map_info);

	sl_lstclear(map_info.mlx, map_info.img_stack);
	sl_lstclear(map_info.mlx, floor);
	// sl_lstclear(map_info.mlx, map_info.gifs->win);
	// sl_lstclear(map_info.mlx, map_info.gifs->nowin);
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
