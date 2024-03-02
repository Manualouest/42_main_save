/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_patrol_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:48:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/02 20:15:21 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

#include <stdio.h>

// typedef struct s_bees
// {
// 	char				**path;
// 	int					is_angry;
// 	int					bee_frame;
// 	t_x_y				bee_pos;
// 	struct s_img_stack	**img_stack;
// 	struct s_bees		*next;
// }						t_bees;

// typedef struct s_hive
// {
// 	int					bee_count;
// 	t_x_y				hive_pos;
// 	struct s_bees		*bees;
// }						s_hive_main;

char	**sl_map_copy(t_map_info *map_info)
{
	char	**copy;
	int		i;
	int		ii;

	i = -1;
	copy = malloc(sizeof(char *) * (map_info->size.y + 1));
	copy[map_info->size.y] = 0;
	while (++i < map_info->size.y)
	{
		ii = -1;
		copy[i] = malloc(sizeof(char) * map_info->size.x);
		while (++ii < map_info->size.x)
			copy[i][ii] = map_info->map[i][ii];
	}
	return (copy);
}

t_x_y	sl_get_hive_pos(t_map_info *map_info)
{
	int		x_sum;
	int		y_sum;
	t_x_y	pos;

	pos.y = 0;
	x_sum = 0;
	y_sum = 0;
	while (++pos.y < map_info->size.y)
	{
		pos.x = 0;
		while (++pos.x < map_info->size.x)
		{
			if (map_info->map[pos.y][pos.x] == 'C')
			{
				x_sum += pos.x;
				y_sum += pos.y;
			}
		}
	}
	pos.x = x_sum / map_info->c_num;
	pos.y = y_sum / map_info->c_num;
	return (pos);
}

t_x_y	sl_place_hive_scanner_horizontal(t_hive *hive, int rad)
{
	int		i;
	int		len;
	t_x_y	pos;

	i = 0;
	len = rad * 2 + 1;
	while (++i <= len)
	{
		pos.x = hive->hive_pos.x - (rad - i);
		pos.y = hive->hive_pos.y - rad;
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && hive->tp_map[pos.y][pos.x] == '0')
			return (pos);
		pos.x = hive->hive_pos.x - (rad - i);
		pos.y = hive->hive_pos.y + rad;
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && hive->tp_map[pos.y][pos.x] == '0')
			return (pos);
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_x_y	sl_place_hive_scanner_vertical(t_hive *hive, int rad)
{
	int		i;
	int		len;
	t_x_y	pos;

	i = 0;
	len = rad * 2 + 1;
	while (++i <= len)
	{
		pos.x = hive->hive_pos.x - rad;
		pos.y = hive->hive_pos.y - (rad - i);
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && hive->tp_map[pos.y][pos.x] == '0')
			return (pos);
		pos.x = hive->hive_pos.x + rad;
		pos.y = hive->hive_pos.y - (rad - i);
		if (pos.x < hive->size.x && pos.x > 0 && pos.y < hive->size.y
			&& pos.y > 0 && hive->tp_map[pos.y][pos.x] == '0')
			return (pos);
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

void	sl_place_hive(t_hive *hive)
{
	int		rad;
	t_x_y	pos;

	rad = 0;
	while (++rad < (hive->size.x + hive->size.y))
	{
		pos = sl_place_hive_scanner_vertical(hive, rad);
		if (pos.x != 0 && pos.y != 0)
			break ;
		pos = sl_place_hive_scanner_horizontal(hive, rad);
		if (pos.x != 0 && pos.y != 0)
			break ;
	}
	hive->tp_map[pos.y][pos.x] = 'H';
}

void	sl_hive_init(t_map_info *map_info, t_hive *hive)
{
	if (map_info->c_num <= 8)
		hive->bee_count = (int)((float)map_info->c_num / 2 + 0.5);
	else
		hive->bee_count = 4;
	hive->tp_map = sl_map_copy(map_info);
	hive->hive_pos = sl_get_hive_pos(map_info);
	hive->size = map_info->size;
	sl_place_hive(hive);
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_hive		hive;
	int			i;

	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit(0);
	img_stack = NULL;
	map_info.img_stack = &img_stack;
	map_info.total_moves = -1;
	map_info.way = 0;
	sl_hive_init(&map_info, &hive);
	i = -1;
	while (++i < map_info.size.y)
	{
		printf("%s\n", hive.tp_map[i]);
		free(hive.tp_map[i]);
	}
	free(hive.tp_map);
	return (0);
}

// void	ft_putnbr(int n)
// {
// 	unsigned int	temp;
// 	char			num;

// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		temp = n * -1;
// 	}
// 	else
// 		temp = n;
// 	if (temp > 9)
// 		ft_putnbr(temp / 10);
// 	num = temp % 10 + '0';
// 	write(1, &num, 1);
// }

// int	main(void)
// {
// 	int	a = -1;
// 	while (++a < 10)
// 	{
// 		ft_putnbr(a);
// 		write(1, ",", 1);
// 		ft_putnbr((int)((float)a/2+0.5));
// 		write(1, "\n", 1);
// 	}
// }