/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 21:12:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

t_x_y	sl_get_link(t_map_info *map_info, char type)
{
	int			i;
	int			ii;
	t_x_y		exit_coord;

	i = -1;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			if (map_info->map[i][ii] == type)
			{
				exit_coord.x = ii;
				exit_coord.y = i;
				break ;
			}
		}
	}
	return (exit_coord);
}

char	*sl_get_png(char *path, char *tp)
{
	char	*png;
	int		fd;
	int		check;

	png = gnl_strlcat(path, tp, 0);
	png = gnl_strlcat(png, ".png", 1);
	fd = open(png, O_RDONLY);
	free(tp);
	if (fd > 0)
	{
		tp = malloc(2);
		tp[1] = 0;
		check = read(fd, tp, 1);
		close(fd);
		free(tp);
		if (check > 0)
			return (png);
	}
	free(png);
	return (NULL);
}

t_x_y	sl_get_exit(t_map_info map_info)
{
	t_x_y	xy;
	int		i;
	int		ii;

	i = -1;
	while (++i < map_info.size.y)
	{
		ii = -1;
		while (++ii < map_info.size.x)
		{
			if (map_info.map[i][ii] == 'E')
			{
				xy.x = ii;
				xy.y = i;
				break ;
			}
		}
	}
	return (xy);
}

t_x_y	sl_get_player(t_map_info map_info)
{
	t_x_y	xy;
	int		i;
	int		ii;

	i = -1;
	while (++i < map_info.size.y)
	{
		ii = -1;
		while (++ii < map_info.size.x)
		{
			if (map_info.map[i][ii] == 'P')
			{
				xy.x = ii;
				xy.y = i;
				break ;
			}
		}
	}
	return (xy);
}
