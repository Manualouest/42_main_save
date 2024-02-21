/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_patrol_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:48:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/21 18:58:26 by mbirou           ###   ########.fr       */
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

int	sl_collectible_path(t_hive *hive, t_x_y start, int way, int way2)
{ //-1 = O, 1 = E, -10 = N, 10 = S
	char	**map_cpy;
	int		width;
	int		height;

	map_cpy = map_info->map_copy;
	width = map_info->size.x;
	height = map_info->size.y;
	if (map_info->map_copy[y][x] == 'E')
	{
		map_info->map_copy[y][x] = '1';
		return ;
	}
	map_info->map_copy[y][x] = '1';
	if (y > 1 && map_cpy[y - 1][x] != '1')
		sl_path_check_utils(map_info, x, y - 1);
	if (x < width - 1 && map_cpy[y][x + 1] != '1')
		sl_path_check_utils(map_info, x + 1, y);
	if (y < height - 1 && map_cpy[y + 1][x] != '1')
		sl_path_check_utils(map_info, x, y + 1);
	if (x > 1 && map_cpy[y][x - 1] != '1')
		sl_path_check_utils(map_info, x - 1, y);
}

t_x_y	sl_place_hive(t_map_info *map_info, t_hive *hive)
{
	int		i;
	t_x_y	start;

	i = -1;
	start.x = 0;
	start.y = 0;
	while (++i < map_info->c_num)
	{
		while (++start.y < map_info->size.y)
		{
			start.x = 0;
			while (++start.x < map_info->size.x)
			{
				printf ("%d, %d, %c\n", start.y, start.x, map_info->map[start.y][start.x]);
				if (map_info->map[start.y][start.x] == 'C')
					sl_collectible_path(hive, start, 0);
			}
		}
	}
	return (start);
}

void	sl_hive_init(t_map_info *map_info, t_hive *hive)
{
	if (map_info->c_num <= 8)
		hive->bee_count = (int)((float)map_info->c_num / 2 + 0.5);
	else
		hive->bee_count = 4;
	hive->tp_map = sl_map_copy(map_info);
	hive->hive_pos = sl_place_hive(map_info, hive);
}


int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_img_stack	*floor;

	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	floor = NULL;
	map_info.img_stack = &img_stack;
	map_info.total_moves = -1;
	map_info.way = 0;
	// if (sl_mlx_handler(map_info, &floor) == 0)
		// exit(0);

	t_hive hive;
	sl_hive_init(&map_info, &hive);
	int	i = -1;
	
	while (++i < map_info.size.y)
		printf("%s", hive.tp_map[i]);
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