/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:34:12 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:57:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->graphic.width,
			game->graphic.height, "Pookie3d", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->screen = mlx_new_image(game->mlx, game->graphic.width,
			game->graphic.height);
	mlx_image_to_window(game->mlx, game->screen, 0, 0);
	game->gui = mlx_new_image(game->mlx, game->graphic.width,
			game->graphic.height);
	mlx_image_to_window(game->mlx, game->gui, 0, 0);
	mlx_key_hook(game->mlx, (void (*))cd_keys, (void *)game);
	mlx_mouse_hook(game->mlx, (void (*))cd_mouse_input, (void *)game);
	mlx_scroll_hook(game->mlx, (void (*))cd_inventory_switch, (void *)game);
	mlx_loop_hook(game->mlx, (void (*))cd_render, (void *)game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*map_file;

	map_file = ft_strdup(argv[1]);
	if (!map_file)
		return (0);
	if (argc > 2)
		return (0);
	game = cd_init_structs(map_file);
	parser(&game);
	cd_img_to_int(&game, &game.graphic);
	game.graphic.pic_frame = 0;
	cd_init_mlx(&game);
	mlx_loop(game.mlx);
	cd_free_all(&game);
	return (1);
}
