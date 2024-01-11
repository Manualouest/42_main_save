/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:02:11 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/05 12:59:10 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	place_zero(char **work_map, char **map, int l_size, int c_size);
void	scan_work_map(char **work_map, char **map, int l_size, int c_size);
void	merge_maps(char **work_map, char **map, int l_size, int c_size);
void	fill_square(char **map, t_coord square_info);

void	find_largest_square(char **map, int l_size, int c_size)
{
	t_coord	coord;
	char	**work_map;
	int		i;

	work_map = malloc(sizeof(char *) * (l_size + 1));
	if (work_map == NULL)
		return ;
	i = 0;
	while (l_size + 1 > i)
	{
		work_map[i] = malloc(sizeof(char) * (c_size + 1));
		if (work_map[i] == NULL)
			return ;
		i++;
	}
	coord.x = -1;
	coord.y = -1;
	while (l_size > coord.x++ + 1)
		work_map[coord.x][0] = map[coord.x][0];
	while (c_size > coord.y++ + 1)
		work_map[0][coord.y] = map[0][coord.y];
	scan_work_map(work_map, map, l_size, c_size);
	merge_maps(work_map, map, l_size, c_size);
	free_work_map(work_map, l_size + 1);
}

void	scan_work_map(char **work_map, char **map, int l_size, int c_size)
{
	t_coord	coord;
	int		a;
	int		b;
	int		c;

	coord.x = 0;
	while (l_size > coord.x++ + 1)
	{
		coord.y = 0;
		while (c_size > coord.y++ + 1)
		{
			if (map[coord.x][coord.y] == '0')
				work_map[coord.x][coord.y] = '0';
			else
			{
				a = work_map[coord.x - 1][coord.y];
				b = work_map[coord.x - 1][coord.y - 1];
				c = work_map[coord.x][coord.y - 1];
				work_map[coord.x][coord.y] = get_min(a, b, c) + 1;
			}
		}
	}
}

void	merge_maps(char **work_map, char **map, int l_size, int c_size)
{
	t_coord	highest;
	t_coord	coord;

	highest.pos = 0;
	highest.x = 0;
	highest.y = 0;
	coord.x = -1;
	while (l_size > coord.x++ + 1)
	{
		coord.y = -1;
		while (c_size > coord.y++ + 1)
		{
			if (work_map[coord.x][coord.y] > highest.pos)
			{
				highest.pos = work_map[coord.x][coord.y];
				highest.x = coord.x;
				highest.y = coord.y;
			}
		}
	}
	fill_square(map, highest);
}

void	fill_square(char **map, t_coord square_info)
{
	t_coord	coord;

	coord.x = square_info.x - square_info.pos + 1 + '0';
	while (coord.x <= square_info.x)
	{
		coord.y = square_info.y - square_info.pos + 1 + '0';
		while (coord.y <= square_info.y)
		{
			map[coord.x][coord.y] = '2';
			coord.y++;
		}
		coord.x++;
	}
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int	l_size;
	int	c_size;
	int	**map;
	t_coord	coord;
	
	find_largest_square(map, l_size, c_size);
	for (coord.x = 0; coord.x < l_size ; coord.x++)
	{
		for (coord.y = 0; coord.y < c_size; coord.y++)
		{
			printf("%d", map[coord.x][coord.y]);
		}
		printf("\n");
	}
	return (0);
}*/
