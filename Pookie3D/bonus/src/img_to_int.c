/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:32:22 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:32:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_create_rgba(char	*color)
{
	int		r;
	int		g;
	int		b;
	int		a;
	char	**split_color;

	split_color = ft_split(color, ',');
	r = ft_atoi(split_color[0]);
	g = ft_atoi(split_color[1]);
	b = ft_atoi(split_color[2]);
	a = 0xFF;
	free(split_color[0]);
	free(split_color[1]);
	free(split_color[2]);
	free(split_color);
	return (r << 24 | g << 16 | b << 8 | a);
}

int	cd_get_pixel_color(mlx_texture_t *txt, int x, int y)
{
	int	pos;
	int	r;
	int	g;
	int	b;
	int	a;

	pos = (y * txt->width + x) * txt->bytes_per_pixel;
	r = txt->pixels[pos];
	g = txt->pixels[pos + 1];
	b = txt->pixels[pos + 2];
	a = txt->pixels[pos + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

int	**cd_extract_pixel(mlx_texture_t *txt)
{
	int	**pixels;
	int	i;
	int	ii;

	pixels = ft_calloc(sizeof(*pixels), txt->width + 2);
	pixels[0] = ft_calloc(sizeof(int *), 2);
	pixels[0][0] = (int)txt->width - 1;
	pixels[0][1] = (int)txt->height - 1;
	pixels[txt->width + 1] = ft_calloc(sizeof(int *), 1);
	pixels[txt->width + 1][0] = -1;
	i = 0;
	while (++i <= (int)txt->width)
	{
		pixels[i] = ft_calloc(sizeof(*(pixels[i])), txt->height + 1);
		pixels[i][txt->height] = -1;
		ii = -1;
		while (++ii < (int)txt->height)
			pixels[i][ii] = cd_get_pixel_color(txt, i - 1, ii);
	}
	mlx_delete_texture(txt);
	return (pixels);
}

void	cd_setup_pickaxe(t_game *game, t_textures *graphic)
{
	mlx_texture_t	*txt;
	char			*path;
	int				i;

	path = ft_strdup("./pngs/pickaxe/0.png");
	i = -1;
	free(graphic->pickaxe[0][0]);
	free(graphic->pickaxe[0]);
	while (++i < 9)
	{
		path[15] = '0' + i;
		txt = mlx_load_png(path);
		if (!txt)
		{
			while (--i >= 0)
				cd_free_int_tab(graphic->pickaxe[i]);
			graphic->pickaxe[0] = malloc(sizeof(graphic->pickaxe[0]));
			graphic->pickaxe[0][0] = malloc(sizeof(int));
			graphic->pickaxe[0][0][0] = -1;
			free(path);
			error_handler(PICK_MISSING, game, NULL);
		}
		graphic->pickaxe[i] = cd_extract_pixel(txt);
	}
	free(path);
}

void	cd_img_to_int(t_game *game, t_textures *graphic)
{
	mlx_texture_t	*txt;
	int				i;

	i = -1;
	while (++i < 94)
	{
		if (graphic->slots[i] == 0)
			continue ;
		free(graphic->txts[i][0]);
		free(graphic->txts[i]);
		txt = mlx_load_png(graphic->p[i]);
		if (!txt)
		{
			graphic->txts[i] = malloc(sizeof(*graphic->txts[i]));
			graphic->txts[i][0] = malloc(sizeof(*graphic->txts[i][0]));
			graphic->txts[i][0][0] = -1;
			error_handler(NO_TEXTURE, game, NULL);
		}
		graphic->txts[i] = cd_extract_pixel(txt);
	}
	cd_setup_pickaxe(game, graphic);
}
