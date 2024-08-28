/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 02:57:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_get_longest(char **map)
{
	int	i;
	int	width;
	int	tp_width;

	width = 0;
	i = 0;
	while (map[i])
	{
		tp_width = ft_strlen(map[i]);
		if (width < tp_width)
			width = tp_width;
		i ++;
	}
	return (width);
}

void	cd_check_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			line[i] = '1';
		i ++;
	}
}

void	cd_fill_end(char *line, int width)
{
	int	i;

	i = ft_strlen(line);
	while (i < width)
	{
		if (line[i] != '0')
			line[i] = '1';
		i ++;
	}
}
#include <stdio.h>
int	cd_check_map_holes(char **map, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0'
				&& !((j == 0 || (map[i][j - 1] == '1' || map[i][j - 1] == '0'))
					&& (i == 0 || (map[i - 1][j] == '1' || map[i - 1][j] == '0'))
					&& (j == width || (map[i][j + 1] == '1' || map[i][j + 1] == '0'))
					&& (i == height || (map[i + 1][j] == '1' || map[i + 1][j] == '0'))))
				printf("i: %d, j: %d, c: %c\n", i, j, map[i][j]);
				// return (1);
		}
	}
	return (1);
}

int	cd_clean_map(t_info *info)
{
	int		width;
	int		height;
	char	*line;

	width = cd_get_longest(info->map);
	height = -1;
	while (info->map[++height])
	{
		if ((int)ft_strlen(info->map[height]) == width)
			continue ;
		line = ft_calloc(sizeof(char), width);
		ft_strlcpy(line, info->map[height], ft_strlen(info->map[height]) + 1);
		// cd_check_spaces(line);
		// cd_fill_end(line, width);
		info->map[height] = cd_re_malloc(info->map[height], line);
	}
	// if (!cd_check_map_holes(info->map, width, height))
	// 	return (-1);
	return (height);
}