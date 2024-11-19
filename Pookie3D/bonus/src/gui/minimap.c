/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:36:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:37:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_setup_minimap(t_game *game, int step)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 240)
	{
		x = -1;
		while (++x < 240)
		{
			if (!step)
				mlx_put_pixel(game->gui, x + 1680, y, 0x000000FF);
			else if (y <= 10 || y >= 230 || x <= 10 || x >= 230)
				mlx_put_pixel(game->gui, x + 1680, y, 0x606060FF);
		}
	}
}

void	cd_put_mini_txt(t_game *game, int m_x, int m_y)
{
	int	y;
	int	x;
	int	y_offset;
	int	x_offset;
	int	**txt;

	y_offset = 25 * (m_y + 4) + 10;
	x_offset = 25 * (m_x + 4) + 10;
	if (y_offset < 10 || x_offset < 10)
		return ;
	if (!game->map.map[(int)game->player.y - m_y][(int)game->player.x - m_x])
		txt = game->graphic.txts[game->graphic.fmap
		[(int)game->player.y - m_y][(int)game->player.x - m_x]];
	else
		txt = game->graphic.txts[game->graphic.tmap
		[(int)game->player.y - m_y][(int)game->player.x - m_x]];
	y = -1;
	while (++y < 25)
	{
		x = -1;
		while (++x < 25)
			mlx_put_pixel(game->gui, x + x_offset + 1680, y + y_offset,
				txt[x * (txt[0][0] / 25) + 1][y * (txt[0][1] / 25)]);
	}
}

int	cd_is_in_triangle(t_position p, t_position p1,
	t_position p2, t_position p3)
{
	float	area1;
	float	area2;
	float	area3;
	float	triangle_area;

	area1 = fabs((p.x * (p1.y - p2.y) + p1.x * (p2.y - p.y)
				+ p2.x * (p.y - p1.y)) / 2.0);
	area2 = fabs((p.x * (p2.y - p3.y) + p2.x * (p3.y - p.y)
				+ p3.x * (p.y - p2.y)) / 2.0);
	area3 = fabs((p.x * (p1.y - p3.y) + p1.x * (p3.y - p.y)
				+ p3.x * (p.y - p1.y)) / 2.0);
	triangle_area = fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y)
				+ p3.x * (p1.y - p2.y)) / 2.0);
	return (floor(triangle_area * 100) / 100.F == floor(
			(area1 + area2 + area3) * 100) / 100.F);
}

void	cd_setup_minimap_struct(t_game *game)
{
	t_position	p1;
	t_position	p2;
	t_position	p3;
	t_position	p4;

	p1.x = 12 + game->player.dirx * -9;
	p1.y = 12 + game->player.diry * -9;
	p2.x = 12 - (game->player.planex) * 4.5;
	p2.y = 12 - (game->player.planey) * 4.5;
	p3.x = 12 + (game->player.planex) * 4.5;
	p3.y = 12 + (game->player.planey) * 4.5;
	p4.y = -1;
	while (++p4.y < 25)
	{
		p4.x = -1;
		while (++p4.x < 25)
		{
			if (cd_is_in_triangle(p4, p1, p2, p3))
				mlx_put_pixel(game->gui, p4.x + 1790, p4.y + 110, 0xFF0000FF);
		}
	}
}

void	cd_minimap(t_game *game)
{
	int	y;
	int	x;

	cd_setup_minimap(game, 0);
	y = -6;
	while (++y < 5)
	{
		x = -6;
		while (++x < 5)
		{
			if (game->player.y - y < 0
				|| game->player.y - y >= game->map.height
				|| game->player.x - x < 0
				|| game->player.x - x >= game->map.width)
				continue ;
			cd_put_mini_txt(game, x, y);
		}
	}
	cd_setup_minimap_struct(game);
	cd_setup_minimap(game, 1);
}
