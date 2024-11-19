/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:05:39 by malbrech          #+#    #+#             */
/*   Updated: 2024/11/17 00:21:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cd_free_int_tab(int **tab)
{
	int	i;

	i = -1;
	while (tab[++i][0] != -1)
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

void	cd_free_all(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map && game->map.map[++i])
		free(game->map.map[i]);
	i = -1;
	while (++i < 6)
		if (game->graphic.paths[i])
			free(game->graphic.paths[i]);
	if (game->map.map)
		free(game->map.map);
	if (game->map.path)
		free(game->map.path);
	cd_free_int_tab(game->graphic.so);
	cd_free_int_tab(game->graphic.no);
	cd_free_int_tab(game->graphic.we);
	cd_free_int_tab(game->graphic.ea);
	if (game->screen)
		mlx_delete_image(game->mlx, game->screen);
	if (game->fps)
		mlx_delete_image(game->mlx, game->fps);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	error_handler(char *ERR_MSG, t_game *game, char *line)
{
	ft_putstr_fd(ERR_MSG, 1);
	cd_free_all(game);
	while (line)
	{
		free(line);
		line = get_next_line(game->map.fd);
	}
	exit(0);
}
