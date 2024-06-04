/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:46:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 02:30:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_create_players(t_map_info *map_info, t_gifs *gifs)
{
	gifs->nowin = malloc(sizeof(**gifs->nowin));
	*gifs->nowin = 0;
	gifs->win = malloc(sizeof(**gifs->win));
	*gifs->win = 0;
	sl_instant_add_png(map_info, gifs->nowin, PLAYER_UNWIN, 1);
	(*gifs->nowin)->gif_len = 120;
	(*gifs->nowin)->path = PLAYER_UNWIN;
	sl_instant_add_png(map_info, gifs->win, PLAYER_WIN, 1);
	(*gifs->win)->gif_len = 19;
	(*gifs->win)->path = PLAYER_WIN;
}

void	sl_create_exits(t_map_info *map_info, t_gifs *gifs)
{
	gifs->idle = malloc(sizeof(**gifs->idle));
	*gifs->idle = 0;
	gifs->angry = malloc(sizeof(**gifs->angry));
	*gifs->angry = 0;
	gifs->happy = malloc(sizeof(**gifs->happy));
	*gifs->happy = 0;
	gifs->shy = malloc(sizeof(**gifs->shy));
	*gifs->shy = 0;
	gifs->ok = malloc(sizeof(**gifs->ok));
	*gifs->ok = 0;
	gifs->cry = malloc(sizeof(**gifs->cry));
	*gifs->cry = 0;
	gifs->sus = malloc(sizeof(**gifs->sus));
	*gifs->sus = 0;
	sl_init_exit_stack(map_info, gifs->idle, EXIT_IDLE, 39);
	sl_init_exit_stack(map_info, gifs->angry, EXIT_ANGRY, 132);
	sl_init_exit_stack(map_info, gifs->happy, EXIT_HAPPY, 119);
	sl_init_exit_stack(map_info, gifs->shy, EXIT_SHY, 23);
	sl_init_exit_stack(map_info, gifs->ok, EXIT_OK, 1);
	sl_init_exit_stack(map_info, gifs->cry, EXIT_CRY, 139);
	sl_init_exit_stack(map_info, gifs->sus, EXIT_SUS, 73);
}

void	sl_init_exit_stack(t_map_info *map_info, t_img_stack **stk,
	char *path, int gif_len)
{
	sl_instant_add_png(map_info, stk, path, 1);
	(*stk)->gif_len = gif_len;
	(*stk)->path = path;
}

void	sl_init_counter(t_map_info *map_info, t_counter *counter)
{
	char	*png;

	counter->move = 0;
	counter->counter_move = malloc(sizeof(**counter->counter_move));
	*counter->counter_move = 0;
	png = sl_get_png(COUNTER_MOVE, ft_itoa(0));
	sl_custom_addback(map_info, png, counter->counter_move, 'P');
	free(png);
	mlx_image_to_window(map_info->mlx, (*counter->counter_move)->img, 16, 16);
	(*counter->counter_move)->is_shown = 1;
	counter->collect = 0;
	counter->counter_collect = malloc(sizeof(**counter->counter_collect));
	*counter->counter_collect = 0;
	png = sl_get_png(COUNTER_COLLECT, ft_itoa(0));
	sl_custom_addback(map_info, png, counter->counter_collect, 'P');
	free(png);
	mlx_image_to_window(map_info->mlx, (*counter->counter_collect)->img,
		map_info->size.x * 42 + 16, map_info->size.y * 42 + 16);
	(*counter->counter_collect)->is_shown = 1;
	map_info->counter = counter;
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_img_stack	*floor;

	if (argc != 2)
	{
		if (argc < 2)
			sl_parsing_error(9, &map_info, NULL, 0);
		else
			sl_parsing_error(10, &map_info, NULL, 0);
		exit (0);
	}
	if (!sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	floor = NULL;
	map_info.img_stack = &img_stack;
	map_info.total_moves = -1;
	map_info.way = 0;
	map_info.has_won = -1;
	map_info.floor = &floor;
	if (sl_mlx_handler(map_info, &floor) == 0)
		exit(0);
	return (0);
}
