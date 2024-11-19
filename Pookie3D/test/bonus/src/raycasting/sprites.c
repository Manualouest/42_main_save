/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:43:15 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:25:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_get_smaller_index(t_game *game, int o_i, float o_min)
{
	float	cur_min;
	int		i_save;
	int		i;

	cur_min = o_min;
	i_save = o_i;
	i = o_i;
	while (game->graphic.sprites[++i])
	{
		if (game->graphic.sprites[i]->distance < cur_min)
		{
			cur_min = game->graphic.sprites[i]->distance;
			i_save = i;
		}
	}
	if (cur_min != o_min)
		return (i_save);
	return (0);
}

void	cd_sort_sprites(t_game *game)
{
	int			i;
	int			ii;
	t_sprite	*swp;

	if (!game->graphic.sprites || !game->graphic.sprites[0])
		return ;
	i = -1;
	while (game->graphic.sprites[++i])
	{
		ii = cd_get_smaller_index(game, i, game->graphic.sprites[i]->distance);
		if (ii)
		{
			swp = game->graphic.sprites[i];
			game->graphic.sprites[i] = game->graphic.sprites[ii];
			game->graphic.sprites[ii] = swp;
		}
	}
}

t_sprite_vars	cd_setup_sprite_vars(t_game *game, t_sprite *sprite)
{
	float			invdir;
	float			trsx;
	t_sprite_vars	sp_var;

	invdir = 1.F / (game->player.diry * game->player.planex
			- game->player.dirx * game->player.planey);
	trsx = invdir * (game->player.diry * (sprite->x - game->player.x)
			- game->player.dirx * (sprite->y - game->player.y));
	sp_var.trsy = invdir * (-game->player.planey
			* (sprite->x - game->player.x)
			+ game->player.planex * (sprite->y - game->player.y));
	sp_var.screenx = ((int)game->graphic.width >> 1)
		* (1 + trsx / sp_var.trsy);
	sp_var.sp_height = (int)fabs(game->graphic.height / sp_var.trsy) >> 3;
	sp_var.sp_width = ((int)fabs(game->graphic.height / sp_var.trsy) >> 3)
		/ game->graphic.width_mod;
	sp_var.stry = ((-sp_var.sp_height) >> 1)
		+ (sp_var.sp_height << 2) + sprite->height;
	sp_var.stry += ((sp_var.sp_height << 3)) * game->player.height
		+ game->graphic.up_op;
	sp_var.endy = sp_var.stry + sp_var.sp_height;
	sp_var.strx = (-sp_var.sp_width >> 1) + sp_var.screenx;
	sp_var.endx = sp_var.strx + sp_var.sp_width;
	return (sp_var);
}

void	cd_put_sprite(t_game *game, t_sprite_vars sp_var,
	t_sprite *sp)
{
	sp_var.x = sp_var.strx - 1;
	while (++sp_var.x < sp_var.endx && sp_var.x < game->graphic.width)
	{
		if (sp_var.x < 0
			|| (int)(sp_var.trsy + 0.5)
				> game->rays.sprite_distances[(int)sp_var.x])
			continue ;
		sp_var.txtx = (sp_var.x - sp_var.strx)
			* (sp->txt[0][0] / (sp_var.endx - sp_var.strx));
		sp_var.y = sp_var.stry * (sp_var.stry >= 0) - 1;
		while (++sp_var.y < sp_var.endy && sp_var.y < game->graphic.height)
		{
			sp_var.txty = (sp_var.y - sp_var.stry)
				* (sp->txt[0][1] / (sp_var.endy - sp_var.stry));
			mlx_put_pixel(game->screen, sp_var.x, sp_var.y,
				sp->txt[sp_var.txtx + 1][sp_var.txty]);
			cd_dim_color(game, sp_var.x, sp_var.y, sp->distance);
		}
	}
}

void	cd_render_sprites(t_game *game, int move_height)
{
	t_sprite_vars	sp_var;
	t_sprite		*sprite;
	int				i;

	if (!game->graphic.sprites || !game->graphic.sprites[0])
		return ;
	i = -1;
	while (game->graphic.sprites[++i])
	{
		sprite = game->graphic.sprites[i];
		sp_var = cd_setup_sprite_vars(game, sprite);
		if (sp_var.trsy > 0)
			cd_put_sprite(game, sp_var, sprite);
		if (!move_height)
			continue ;
		if (sprite->direction)
			sprite->height += 10 * sprite->distance * game->mlx->delta_time;
		else
			sprite->height -= 10 * sprite->distance * game->mlx->delta_time;
		if (sprite->height >= 10)
			sprite->direction = 0;
		if (sprite->height <= 0)
			sprite->direction = 1;
	}
}
