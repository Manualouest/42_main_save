/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:54:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/17 00:23:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_game		game;
	char		*map_file;

	map_file = ft_strdup(argv[1]);
	if (!map_file)
		return (0);
	if (argc > 2)
		return (0);
	game = cd_init_structs(map_file);
	parser(&game);
	cd_img_to_int(&game.graphic, &game);
	game.mlx = mlx_init(1920, 1016, "Cub3d", false);
	if (!game.mlx)
		error_handler(MLX_ERROR, &game, NULL);
	game.screen = mlx_new_image(game.mlx, 1920, 1016);
	if (!game.screen)
		error_handler(MLX_ERROR, &game, NULL);
	if (mlx_image_to_window(game.mlx, game.screen, 0, 0) == -1)
		error_handler(MLX_ERROR, &game, NULL);
	mlx_key_hook(game.mlx, (void (*))cd_keys, (void *)&game);
	if (!mlx_loop_hook(game.mlx, cd_render, (void *)&game))
		error_handler(MLX_ERROR, &game, NULL);
	mlx_loop(game.mlx);
	cd_free_all(&game);
	return (1);
}
