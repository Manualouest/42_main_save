/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/03 20:02:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

void	sl_create_img(t_map_info map_info, t_img_stack **img_stack)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < map_info.size.y)
	{
		ii = -1;
		while (++ii < map_info.size.x)
		{
			sl_lstadd_back(img_stack, &map_info, map_info.map[i][ii]);
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
			mlx_image_to_window(mlx, tp_stk->img, ii * 32 + 16, i * 32 + 16);
			tp_stk = tp_stk->next;
		}
	}
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
	mlx_close_window(map_info->mlx);
}

#include <stdio.h>
void	sl_move_player(t_map_info *mp_inf, int way)
{
	t_img_stack *tp_link;
	int			index;
	int			x;
	int			y;

	x = mp_inf->player.x;
	y = mp_inf->player.y;
	index = (y * mp_inf->size.x) + x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	sl_redo_link(tp_link, mp_inf, '0');
	mlx_image_to_window(mp_inf->mlx, tp_link->img, x * 32 + 16, y * 32 + 16);
	x += way % 10;
	y += way / 10;
	index = (y * mp_inf->size.x) + x;
	tp_link = sl_link_finder(*mp_inf->img_stack, index);
	if (tp_link->type == 'E')
		index = -1;
	sl_redo_link(tp_link, mp_inf, 'P');
	mlx_image_to_window(mp_inf->mlx, tp_link->img, x * 32 + 16, y * 32 + 16);
	mp_inf->player.x = x;
	mp_inf->player.y = y;
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
	mlx_image_to_window(map_info->mlx, tp_stk->img, ii * 32 - 16, i * 32 - 16);
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

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;

	write(1,"\E[H\E[2J",7);
	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	map_info.img_stack = &img_stack;
	map_info.total_moves = 0;
	map_info.mlx = mlx_init(map_info.size.x * 32 + 32, map_info.size.y * 32 + 32, "So Long", false);
	if (!map_info.mlx)
		return (0);
	
	sl_create_img(map_info, map_info.img_stack);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);

	mlx_key_hook(map_info.mlx, &sl_single_key_handler, (void *)&map_info);
	mlx_loop(map_info.mlx);
	
	sl_free_t_map_info(&map_info);
	sl_lstclear(map_info.mlx, map_info.img_stack);
	mlx_terminate(map_info.mlx);
}
