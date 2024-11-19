/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:52:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/17 00:07:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	**cd_get_empty_tab(void)
{
	int	**empty_tab;

	empty_tab = malloc(sizeof(int *));
	empty_tab[0] = malloc(sizeof(int));
	empty_tab[0][0] = -1;
	return (empty_tab);
}

void	cd_init_graphic(t_game *game)
{
	t_textures	graphic;

	graphic.no = 0;
	graphic.so = 0;
	graphic.we = 0;
	graphic.ea = 0;
	graphic.f = 0;
	graphic.c = 0;
	graphic.paths[0] = NULL;
	graphic.paths[1] = NULL;
	graphic.paths[2] = NULL;
	graphic.paths[3] = NULL;
	graphic.paths[4] = NULL;
	graphic.paths[5] = NULL;
	graphic.paths[6] = NULL;
	graphic.width = 1920;
	graphic.height = 1016;
	graphic.ea = cd_get_empty_tab();
	graphic.we = cd_get_empty_tab();
	graphic.so = cd_get_empty_tab();
	graphic.no = cd_get_empty_tab();
	game->graphic = graphic;
}
