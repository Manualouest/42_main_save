/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/07 03:43:54 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

void	sl_create_img(t_map_info mp_inf, t_img_stack **img_stk)
{
	int		i;
	int		ii;
	t_x_y	xy;

	i = -1;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			xy.y = i;
			xy.x = ii;
			if ( mp_inf.map_copy[i][ii] == 'P')
			{
				sl_lstadd_back(img_stk, &mp_inf, '0', xy);
				sl_lstadd_back(mp_inf.player_img, &mp_inf, 'P', xy);
			}
			else
				sl_lstadd_back(img_stk, &mp_inf, mp_inf.map_copy[i][ii], xy);
		}
	}
}

void	sl_img_show(mlx_t *mlx, t_map_info mp_inf, t_img_stack *img_stk)
{
	t_img_stack	*tp_stk;
	int			i;
	int			ii;

	i = -1;
	tp_stk = img_stk;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			mlx_image_to_window(mlx, tp_stk->img, ii * 42 + 16, i * 42 + 16);
			tp_stk = tp_stk->next;
		}
	}
	i = mp_inf.player.y;
	ii = mp_inf.player.x;
	write(1, &(*mp_inf.player_img)->type, 1);
	mlx_image_to_window(mlx, (*mp_inf.player_img)->img, ii * 42 + 16, i * 42 + 16);
}

void	ft_putnbr(int n)
{
	unsigned int	temp;
	char			num;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
		ft_putnbr(temp / 10);
	num = temp % 10 + '0';
	write(1, &num, 1);
}

void	sl_update_moves(t_map_info *map_info)
{
	if (map_info->total_moves > 0)
		write(1,"\E[H\E[2J",7);
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
		write(1, "ESCAPE NOW!", 11);
	write(1, "\n", 1);
}

void	sl_win_stop(t_map_info *map_info)
{
	write(1,"\E[H\E[2J",7);
	write(1, "You won :D\n", 11);
	write(1, "With ", 5);
	ft_putnbr(map_info->total_moves);
	write(1, " moves played\n", 14);
	mlx_close_window(map_info->mlx);
}

void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack *tp_link;
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
	{
		tp_link->img->instances->x = -64;
		tp_link->img->instances->y = -64;
	}
	if (tp_link->type == 'E')
		index = -1;
	sl_update_moves(mp_inf);
	if (index == -1)
		sl_win_stop(mp_inf);
}

void	sl_change_exit(t_map_info *map_info)
{
	int			i;
	int			ii;
	int			index;
	t_img_stack	*tp_stk;

	i = -1;
	index = -1;
	while (++i < map_info->size.y && index == -1)
	{
		ii = -1;
		while (++ii < map_info->size.x && index == -1)
			if (map_info->map[i][ii] == 'E')
				index = (i * map_info->size.x) + ii;
	}
	tp_stk = sl_link_finder(*map_info->img_stack, index);
	sl_redo_link(tp_stk, map_info, 'E');
	sl_redo_link((*map_info->player_img), map_info, 'P');
	i --;
	ii --;
	mlx_image_to_window(map_info->mlx, tp_stk->img, ii * 42 + 16, i * 42 + 16);
	ii = map_info->player.x * 42 + 16;
	ii = map_info->player.x * 42 + 16;
	mlx_image_to_window(map_info->mlx, (*map_info->player_img)->img, ii, i);
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
	if (map_info->c_num == 0)
	{
		sl_change_exit(map_info);
		map_info->c_num --;
	}
	return (1);
}

void	sl_single_key_handler(mlx_key_data_t keydata, void *map_info_void)
{
	t_map_info *mp_inf;

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
				sl_lstadd_back(floor, &mp_inf, '0', mp_inf.size);
				mlx_image_to_window(mp_inf.mlx, ft_lstlast(*floor)->img, x, y);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_img_stack	*player_img;
	t_img_stack	*floor;

	write(1,"\E[H\E[2J",7);
	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	player_img = NULL;
	floor = NULL;
	map_info.player_img = &player_img;
	map_info.img_stack = &img_stack;
	map_info.total_moves = 0;
	map_info.mlx = mlx_init(map_info.size.x * 42 + 32, map_info.size.y * 42 + 32, "So Long", false);
	if (!map_info.mlx)
		return (0);
	
	sl_handle_extra_floor(map_info, &floor);
	sl_create_img(map_info, map_info.img_stack);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);

	mlx_key_hook(map_info.mlx, &sl_single_key_handler, (void *)&map_info);
	mlx_loop(map_info.mlx);
	
	sl_free_t_map_info(&map_info);
	sl_lstclear(map_info.mlx, map_info.img_stack);
	sl_lstclear(map_info.mlx, &floor);
	sl_lstclear(map_info.mlx, map_info.player_img);
	mlx_terminate(map_info.mlx);
}

