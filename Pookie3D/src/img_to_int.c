/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/17 00:21:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	cd_create_rgba(char	*color, t_game *game)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**split_color;

	i = -1;
	while (color[++i])
		if (!ft_isdigit(color[i]) && color[i] != ',')
			error_handler(BAD_COLOR, game, NULL);
	split_color = ft_split(color, ',');
	i = tab_len(split_color);
	if (i == 3)
	{
		r = ft_atoi(split_color[0]);
		g = ft_atoi(split_color[1]);
		b = ft_atoi(split_color[2]);
	}
	free(split_color[0]);
	free(split_color[1]);
	free(split_color[2]);
	free(split_color);
	if (i != 3)
		error_handler(BAD_COLOR, game, NULL);
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

int	cd_get_pixel_color(mlx_texture_t *txt, int x, int y)
{
	int	pos;
	int	r;
	int	g;
	int	b;
	int	a;

	pos = ((y - 1) * txt->width + x) * txt->bytes_per_pixel;
	r = txt->pixels[pos];
	g = txt->pixels[pos + 1];
	b = txt->pixels[pos + 2];
	a = txt->pixels[pos + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

int	**cd_extract_pixel(mlx_texture_t *txt, int is_flipped)
{
	int	**pixels;
	int	i;
	int	ii;

	pixels = ft_calloc(sizeof(*pixels), txt->height + 2);
	pixels[0] = ft_calloc(sizeof(int *), 2);
	pixels[0][0] = (int)txt->width - 1;
	pixels[0][1] = (int)txt->height - 1;
	pixels[txt->height + 1] = ft_calloc(sizeof(int *), 1);
	pixels[txt->height + 1][0] = -1;
	i = 0;
	while (++i <= (int)txt->height)
	{
		pixels[i] = ft_calloc(sizeof(*(pixels[i])), txt->width + 1);
		pixels[i][txt->width] = -1;
		ii = -1;
		while (++ii < (int)txt->width)
		{
			if (!is_flipped)
				pixels[i][ii] = cd_get_pixel_color(txt, ii, i);
			else
				pixels[i][ii] = cd_get_pixel_color(txt, pixels[0][0] - ii, i);
		}
	}
	return (pixels);
}

void	cd_realloc_int_img(t_game *game, int ***tab,
	mlx_texture_t *txt, int is_flipped)
{
	if (!txt)
		error_handler(PNG_NOT_FOUND, game, NULL);
	cd_free_int_tab(tab[0]);
	tab[0] = cd_extract_pixel(txt, is_flipped);
	mlx_delete_texture(txt);
}

void	cd_img_to_int(t_textures *graphic, t_game *game)
{
	mlx_texture_t	*txt;
	int				i;

	i = -1;
	while (graphic->paths[++i] && i <= 5)
	{
		if (i <= 3)
			txt = mlx_load_png(graphic->paths[i]);
		if (i == 0)
			cd_realloc_int_img(game, &graphic->no, txt, 0);
		else if (i == 1)
			cd_realloc_int_img(game, &graphic->so, txt, 1);
		else if (i == 2)
			cd_realloc_int_img(game, &graphic->we, txt, 1);
		else if (i == 3)
			cd_realloc_int_img(game, &graphic->ea, txt, 0);
		else if (i == 4)
			graphic->f = cd_create_rgba(graphic->paths[i], game);
		else if (i == 5)
			graphic->f = cd_create_rgba(graphic->paths[i], game);
		free(graphic->paths[i]);
		graphic->paths[i] = NULL;
	}
}
