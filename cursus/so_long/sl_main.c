/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/08 05:50:22 by mbirou           ###   ########.fr       */
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
			if (mp_inf.map_copy[i][ii] == 'P')
			{
				sl_add_back(img_stk, &mp_inf, '0', xy);
				sl_add_back(mp_inf.player_img, &mp_inf, 'P', xy);
			}
			else
				sl_add_back(img_stk, &mp_inf, mp_inf.map_copy[i][ii], xy);
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
	i = mp_inf.player.y * 42 + 16;
	ii = mp_inf.player.x * 42 + 16;
	mlx_image_to_window(mlx, (*mp_inf.player_img)->img, ii, i);
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

void	sl_get_exit(t_map_info *map_info)
{
	int			i;
	int			ii;

	i = -1;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			if (map_info->map[i][ii] == 'E')
			{
				map_info->exit.x = ii;
				map_info->exit.y = i;
				break ;
			}
		}
	}
	map_info->exit_type = 0;
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_img_stack	*player_img;
	t_img_stack	*floor;

	write(1, "\E[H\E[2J", 7);
	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	player_img = NULL;
	floor = NULL;
	map_info.player_img = &player_img;
	map_info.img_stack = &img_stack;
	map_info.total_moves = 0;
	sl_get_exit(&map_info);
	if (sl_mlx_handler(map_info, floor) == 0)
		exit(0);
	return (0);
}
