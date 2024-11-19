/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:17:07 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:21:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_set_orientation(t_game *game, char o, int i)
{
	if (o == 'N')
	{
		game->player.dirx = 0;
		game->player.diry = -1;
	}
	else if (o == 'S')
	{
		game->player.dirx = 0;
		game->player.diry = 1;
	}
	else if (o == 'W')
	{
		game->player.dirx = -1;
		game->player.diry = 0;
	}
	else
	{
		game->player.dirx = 1;
		game->player.diry = 0;
	}
	game->player.planex = 0.9449296585499998935 * -game->player.diry;
	game->player.planey = 0.9449296585499998935 * game->player.dirx;
	game->player.x = i + 0.5;
	game->player.y = game->map.height + 0.5;
}

char	cd_put_first_slot(t_game *game, int is_wmap)
{
	int	i;

	if (is_wmap == 1)
		return ('1');
	i = -1;
	while (++i < 94)
	{
		if (game->graphic.slots[i])
			return ((char)(i + 33));
	}
	return (' ');
}

int	cd_parse_line(char **line, t_game *game, int map_kind)
{
	int	i;

	i = -1;
	while (line[0][++i] && line[0][i] != '\n')
	{
		if (line[0][i] == ' ')
			line[0][i] = cd_put_first_slot(game, map_kind);
		if (!game->graphic.slots[(int)line[0][i] - 33])
		{
			if (map_kind != 1 && map_kind != 3 && !(line[0][i] == '0'
				&& !game->map.map[game->graphic.tp_h][i]))
				return (-1);
			else if ((line[0][i] == 'N' || line[0][i] == 'S'
				|| line[0][i] == 'E' || line[0][i] == 'W')
				&& game->player.x == -1)
			{
				cd_set_orientation(game, line[0][i], i);
				line[0][i] = '0';
			}
		}
	}
	if (line[0][i] && line[0][i] == '\n')
		line[0][i] = 0;
	return (i);
}

void	cd_setup_map(char *line, t_game *game, int ***map)
{
	int	line_len;

	line_len = cd_parse_line(&line, game, 1);
	if (line_len == -1)
		error_handler(BAD_CHAR, game, line);
	map[0] = cd_add_new_array_line(cd_strtoi_m(line, line_len, '0'), map[0]);
	game->map.height ++;
	if (line_len > game->map.width)
		game->map.width = line_len;
}

void	cd_setup_txt_maps(char *line, t_game *game, int ***map, int step)
{
	int	line_len;

	line_len = cd_parse_line(&line, game, step);
	if (line_len == -1)
		error_handler(BAD_CHAR, game, line);
	game->graphic.tp_h ++;
	if (line_len > game->map.width || game->graphic.tp_h > game->map.height)
		error_handler(BAD_MAPS, game, line);
	map[0] = cd_add_new_array_line(cd_strtoi_m(line, line_len, '!'), map[0]);
}
