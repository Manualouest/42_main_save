/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:01:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/17 00:04:26 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	cd_set_orientation(char o)
{
	if (o == 'N')
		return (1.5 * M_PI + 0.01);
	if (o == 'S')
		return (0.5 * M_PI + 0.01);
	if (o == 'W')
		return (M_PI + 0.01);
	if (o == 'E')
		return (0.01);
	return (-1);
}

void	cd_setup_map(char *line, t_game *game)
{
	int	i;

	i = -1;
	while (++i >= 0 && line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& game->map.player.x == -1 && (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
		{
			game->map.player.x = i + 0.5;
			game->map.player.y = game->map.height + 0.5;
			game->map.player.view = cd_set_orientation(line[i]);
			line[i] = '0';
		}
		else if (line[i] != ' ' && line[i] != '0' && line[i] != '1')
			i = -2;
	}
	if (i < 0)
		error_handler(BAD_CHAR, game, line);
	line[i] = 0;
	if (i > game->map.width)
		game->map.width = i;
	game->map.map = add_new_line(line, game->map.map);
	game->map.height += 1;
}

int	cd_check_edges(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (map->map[i][0] == '0' || map->map[i][map->width - 1] == '0')
			return (0);
	}
	i = -1;
	while (++i < map->width)
	{
		if (map->map[0][i] == '0' || map->map[map->height - 1][i] == '0')
			return (0);
	}
	return (1);
}

void	cd_resize_map(t_game *game, int width)
{
	char	*new_line;
	int		i;
	int		len;

	i = -1;
	while (game->map.map[++i])
	{
		new_line = ft_calloc(sizeof(char), width + 1);
		len = ft_strlen(game->map.map[i]);
		ft_strlcpy(new_line, game->map.map[i],
			len + 1);
		while (len < width)
		{
			new_line[len] = ' ';
			len ++;
		}
		free(game->map.map[i]);
		game->map.map[i] = (new_line);
	}
}

void	cd_parse_map(t_game *game, t_map *map)
{
	int	i;
	int	ii;

	cd_resize_map(game, map->width);
	i = -1;
	while (++i >= 0 && map->map[i])
	{
		ii = -1;
		while (i >= 0 && ++ii < map->width)
		{
			if (map->map[i][ii] == ' ' && (map->map[i - (i > 0)][ii] == '0'
				|| map->map[i + (!(!map->map[i + 1]))][ii] == '0'
				|| map->map[i][ii + (!(!map->map[i][ii + 1]))] == '0'
				|| map->map[i][ii - (ii > 0)] == '0'))
				i = -2;
			if (i >= 0 && map->map[i][ii] == ' ')
				map->map[i][ii] = '1';
		}
	}
	if (i < 0 || !cd_check_edges(map))
		error_handler(BAD_MAP, game, NULL);
}
