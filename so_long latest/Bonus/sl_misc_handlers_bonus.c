/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_misc_handlers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:02:59 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 02:25:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_print_emoji(int choice)
{
	char	*emoji;

	emoji = malloc(4);
	if (choice == 0)
	{
		emoji[0] = 0xF0;
		emoji[1] = 0x9F;
		emoji[2] = 0x98;
		emoji[3] = 0x8F;
	}
	else
	{
		emoji[0] = 0xF0;
		emoji[1] = 0x9F;
		emoji[2] = 0x98;
		emoji[3] = 0x9E;
	}
	write(1, emoji, 4);
	free(emoji);
}

void	sl_win_stop(t_map_info *map_info, int win_loose)
{
	system("if [ $(ps -e |grep \"paplay\" | wc -l) -eq 1 ]; \
		then killall paplay $!; fi");
	map_info->has_won = win_loose;
	sl_start_end_gif(map_info);
	if (win_loose == 0)
		write(1, "Good Job ", 9);
	else
		write(1, "Womp Womp ", 10);
	sl_print_emoji(win_loose);
	write(1, "\n", 1);
	write(1, "You finished with ", 18);
	if (map_info->total_moves > -1)
	{
		ft_putnbr(map_info->total_moves);
		write(1, " moves played\n", 14);
	}
	else
		write(1, "so many moves we couldn't even fit it in an int...\n", 51);
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

void	sl_loops(t_map_info map_info)
{
	mlx_key_hook(map_info.mlx, &sl_key_handler, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_player, (void *)&map_info);
	mlx_loop_hook(map_info.mlx, &sl_anime_exit_main, (void *)&map_info);
	if (map_info.hive->hive_pos.x != 0)
		mlx_loop_hook(map_info.mlx, &sl_animate_hive, (void *)&map_info);
	mlx_close_hook(map_info.mlx, &sl_cross_close, NULL);
	mlx_loop(map_info.mlx);
}

int	sl_mlx_handler(t_map_info map_info, t_img_stack **floor)
{
	t_gifs		gifs;
	t_counter	counter;
	int			x;
	int			y;
	t_hive		hive;

	x = map_info.size.x * 42 + 32;
	y = map_info.size.y * 42 + 32;
	map_info.mlx = mlx_init(x, y, "So Long", true);
	if (!map_info.mlx)
		return (0);
	sl_create_img(map_info, map_info.img_stack);
	sl_handle_extra_floor(map_info, floor);
	sl_img_show(map_info.mlx, map_info, *map_info.img_stack);
	gifs = sl_init_gifs(&map_info);
	map_info.gifs = &gifs;
	sl_init_counter(&map_info, &counter);
	sl_update_moves(&map_info);
	sl_hive_init(&map_info, &hive);
	sl_loops(map_info);
	sl_free_hive(&map_info, floor);
	mlx_terminate(map_info.mlx);
	return (1);
}
