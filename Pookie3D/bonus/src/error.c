/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:32:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 21:53:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_free_int_img(int **tab)
{
	int	i;
	int	len;

	i = -1;
	len = tab[0][0] + 1;
	while (++i <= len)
		free(tab[i]);
	free(tab);
}

void	cd_free_int_tab(int **tab)
{
	int	i;

	i = -1;
	while (tab[++i][0] != -1)
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

void	cd_free_int_imgs(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 94)
	{
		cd_free_int_tab(game->graphic.txts[i]);
		if (game->graphic.p[i])
			free(game->graphic.p[i]);
	}
	i = -1;
	i = -1;
	if (game->graphic.pickaxe[0][0][0] != -1)
		while (++i < 9)
			cd_free_int_tab(game->graphic.pickaxe[i]);
	else
		cd_free_int_tab(game->graphic.pickaxe[0]);
	i = -1;
	while (game->graphic.sprites[++i])
		free(game->graphic.sprites[i]);
	free(game->graphic.sprites);
}

void	cd_free_all(t_game *game)
{
	t_inventory	*tp_inv;

	if (game->map.path)
		free(game->map.path);
	cd_free_int_imgs(game);
	free(game->rays.sprite_distances);
	while (game->player.inventory)
	{
		tp_inv = game->player.inventory->next;
		free(game->player.inventory);
		game->player.inventory = tp_inv;
	}
	free(game->graphic.pickaxe);
	cd_free_int_tab(game->map.map);
	cd_free_int_tab(game->graphic.tmap);
	cd_free_int_tab(game->graphic.fmap);
	cd_free_int_tab(game->graphic.rmap);
	if (game->screen)
		mlx_delete_image(game->mlx, game->screen);
	if (game->gui)
		mlx_delete_image(game->mlx, game->gui);
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
