/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:49:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/03 16:11:31 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_is_outer_wall(t_game *game, t_ray_info rays)
{
	if (rays.x == 0 || rays.y == 0
		|| rays.x == game->map.width - 1 || rays.y == game->map.height - 1)
		return (1);
	return (0);
}

void	cd_edit_wall(t_game *game, char new_wall)
{
	t_ray_info	rays;
	int			x;
	int			y;

	rays = cd_create_rays();
	rays.angle = game->player.view;
	// rays = cd_cast_ray(rays);
	if (rays.distance > 5)
		return ;
	if (new_wall == '0' && cd_is_outer_wall(game, rays))
		return ;
	x = 0;
	y = 0;
	if (new_wall == '1' && rays.side == 0 && cos(rays.angle) > 0)
		x = -1;
	else if (new_wall == '1' && rays.side == 0 && cos(rays.angle) <= 0)
		x = 1;
	else if (new_wall == '1' && rays.side == 1 && sin(rays.angle) > 0)
		y = -1;
	else if (new_wall == '1' && rays.side == 1)
		y = 1;
	game->map.map[(int)rays.y + y][(int)rays.x + x] = new_wall;
}
