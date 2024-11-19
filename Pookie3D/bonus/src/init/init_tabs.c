/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:34:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 13:14:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

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
	int			i;

	graphic.tmap = cd_get_empty_tab();
	graphic.fmap = cd_get_empty_tab();
	graphic.rmap = cd_get_empty_tab();
	graphic.width = 1920;
	graphic.width_mod = 1;
	graphic.height = 1016;
	i = -1;
	while (++i < 94)
	{
		graphic.p[i] = NULL;
		graphic.slots[i] = 0;
		graphic.txts[i] = cd_get_empty_tab();
	}
	graphic.dim = 0;
	graphic.incr = 0;
	graphic.sprites = malloc(sizeof(*graphic.sprites));
	graphic.sprites[0] = NULL;
	graphic.pickaxe = malloc(sizeof(int **) * 9);
	graphic.pickaxe[0] = cd_get_empty_tab();
	graphic.pic_frame = -1;
	game->graphic = graphic;
}
