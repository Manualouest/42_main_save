/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:38 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/31 14:33:06 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>
// a modifier encore une fois pour que ca fonctionne putain
void	cd_minimap_conditions(t_game *game, t_position *pos, int *i, int *ii)
{
	// char *str;
	// uint32_t purple;
	// str = "(128,0,128)";
	// purple = cd_create_rgba(str);
	if (game->map.map[*i][*ii] == '1')
		mlx_put_pixel(game->screen, pos->x, pos->y, game->graphic.c);
	else if (game->map.map[*i][*ii] == '0')
		mlx_put_pixel(game->screen, pos->x, pos->y, game->graphic.c);
	else if (game->map.map[*i][*ii] == 'N'
				|| game->map.map[*i][*ii] == 'W'
				|| game->map.map[*i][*ii] == 'E'
				|| game->map.map[*i][*ii] == 'S')
		mlx_put_pixel(game->screen, pos->x, pos->y, game->graphic.c);
}

//Fonction qui va faire la mini map
void	cd_minimap(t_game *game)
{
	int			i;
	int			ii;
	t_position	pos;

	pos.x = 0;
	pos.y = 0;
	i = 0;
	while (game->map.map[i])
	{
		ii = 0;
		while (game->map.map[i][ii])
		{
			cd_minimap_conditions(game, &pos, &i, &ii);
			ii++;
		}
		pos.x = 0;
		i++;
	}
}
