/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:28:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:10:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_put_inv_txt(t_game *game, int **txt, int is_txt)
{
	int	x;
	int	y;
	int	txtx;
	int	txty;

	y = -1;
	while (++y < 120)
	{
		x = -1;
		while (++x < 120)
		{
			if ((y <= 10 || y >= 110) || (x <= 10 || x >= 110))
				mlx_put_pixel(game->gui, x + 1800, y + 896, 0x606060FF);
			else if (is_txt)
			{
				txtx = ((float)x - 10.F) * ((float)txt[0][0] / 100.F);
				txty = ((float)y - 10.F) * ((float)txt[0][1] / 100.F);
				mlx_put_pixel(game->gui, x + 1800,
					y + 896, txt[txtx + 1][txty]);
			}
			else if (!is_txt)
				mlx_put_pixel(game->gui, x + 1800, y + 896, txt[0][0]);
		}
	}
}

void	cd_put_pickaxe(t_game *game, int **txt)
{
	int	y;
	int	y_offset;
	int	x;

	y_offset = game->graphic.height - txt[0][1];
	y = -1;
	while (++y < txt[0][1])
	{
		x = -1;
		while (++x < txt[0][0])
			mlx_put_pixel(game->gui, x, y + y_offset, txt[x + 1][y]);
	}
}

void	cd_show_block_inventory(t_game *game)
{
	int			i;
	t_inventory	*tp_inv;

	i = 0;
	mlx_resize_image(game->gui, 1, 1);
	mlx_put_pixel(game->gui, 0, 0, 0);
	mlx_resize_image(game->gui, 1920, 1016);
	tp_inv = game->player.inventory;
	while (tp_inv)
	{
		tp_inv = tp_inv->next;
		i ++;
	}
	if (i > 0)
		cd_put_inv_txt(game,
			game->graphic.txts[game->player.inventory->tile], 1);
	else
		cd_put_inv_txt(game, &(int *){&(int){0x404040A0}}, 0);
	cd_put_pickaxe(game, game->graphic.pickaxe[(int)game->graphic.pic_frame]);
	game->graphic.pic_frame = cd_clamp(game->graphic.pic_frame + 3
			* game->mlx->delta_time, 0, 9);
}
