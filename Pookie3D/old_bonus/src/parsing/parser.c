/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:33:08 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/15 14:16:44 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

// fonction principale du parser
void	parser(t_game *game)
{
	check_name_cub(game->map.path, game);
	get_infos(game);
	format_d_tab(game->graphic.paths);
}

// Recupere les infos depuis la map
void	get_infos(t_game *game)
{
	char	*buff;
	int		i;
	int		true_line;

	true_line = 0;
	game->map.fd = open(game->map.path, O_RDONLY);
	buff = get_next_line(game->map.fd);
	i = 1;
	while (i)
	{
		if (buff == NULL)
			break ;
		scanner(buff, game, &true_line);
		buff = get_next_line(game->map.fd);
		i++;
	}
	i = -1;
	cd_parse_map(game, &game->map);
}

// Scan les lignes de la map 1 par une pour recuperer les informations
void	scanner(char *line, t_game *game, int *true_line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (is_direction(line, i, true_line, game))
			break ;
		else if (is_rgb(line, i, true_line, game))
			break ;
		else if ((line[i] == '0' || line[i] == '1') && *true_line >= 6)
		{
			cd_setup_map(line, game);
			break ;
		}
		else
		{
			error_handler(FORMAT_ERR, game);
			break ;
		}
	}
}

// Conditions pour les directions
int	is_direction(char *line, int i, int *true_line, t_game *game)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		game->graphic.paths[NO] = line;
		*true_line += 1;
		return (1);
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		game->graphic.paths[SO] = line;
		*true_line += 1;
		return (1);
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		game->graphic.paths[WE] = line;
		*true_line += 1;
		return (1);
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		game->graphic.paths[EA] = line;
		*true_line += 1;
		return (1);
	}
	return (0);
}

// Conditions pour les couleurs rgb
int	is_rgb(char *line, int i, int *true_line, t_game *game)
{
	if (line[i] == 'C')
	{
		game->graphic.paths[C] = line;
		*true_line += 1;
		return (1);
	}
	if (line[i] == 'F')
	{
		game->graphic.paths[F] = line;
		*true_line += 1;
		return (1);
	}
	return (0);
}
