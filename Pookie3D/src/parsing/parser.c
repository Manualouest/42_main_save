/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:33:08 by malbrech          #+#    #+#             */
/*   Updated: 2024/11/16 22:17:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	parser(t_game *game)
{
	check_name_cub(game->map.path, game);
	get_infos(game);
	format_d_tab(game->graphic.paths, game);
}

void	get_infos(t_game *game)
{
	char	*buff;
	int		i;

	game->map.fd = open(game->map.path, O_RDONLY);
	buff = get_next_line(game->map.fd);
	i = 1;
	while (i)
	{
		if (buff == NULL)
			break ;
		if (buff[0] != '\n')
			scanner(buff, game);
		else
			free(buff);
		buff = get_next_line(game->map.fd);
		i++;
	}
	i = -1;
	cd_parse_map(game, &game->map);
}

void	scanner(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (is_direction(line, i, game))
			break ;
		else if (is_rgb(line, i, game))
			break ;
		else if ((line[i] == '0' || line[i] == '1'))
		{
			cd_setup_map(line, game);
			break ;
		}
		else
		{
			error_handler(FORMAT_ERR, game, line);
			break ;
		}
	}
}

int	is_direction(char *line, int i, t_game *game)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		game->graphic.paths[NO] = line;
		return (1);
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		game->graphic.paths[SO] = line;
		return (1);
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		game->graphic.paths[WE] = line;
		return (1);
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		game->graphic.paths[EA] = line;
		return (1);
	}
	return (0);
}

int	is_rgb(char *line, int i, t_game *game)
{
	if (line[i] == 'C')
	{
		game->graphic.paths[C] = line;
		return (1);
	}
	if (line[i] == 'F')
	{
		game->graphic.paths[F] = line;
		return (1);
	}
	return (0);
}
