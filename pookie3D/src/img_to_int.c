/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/18 13:48:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

	pixels = ft_calloc(sizeof(*pixels), txt->height + 1);
	pixels[txt->height] = ft_calloc(sizeof(int *), 1);
	pixels[txt->height][0] = -1;
	i = -1;
	while (++i < txt->height)
	{
		pixels[i] = ft_calloc(sizeof(*(pixels[i])), txt->width + 1);
		pixels[i][txt->width] = -1;
		ii = -1;
		while (++ii < txt->width)
			pixels[i][ii] = cd_get_pixel_color(txt, ii, i);
	}
	return (pixels);
}

void	cd_img_to_int(t_textures *graphic)
{
	mlx_texture_t	*txt;
	int				i;

	i = -1;
	while (graphic->paths && graphic->paths[++i] && i <= 5)
	{
		if (i <= 3)
			txt = mlx_load_png(graphic->paths[i]);
		if (i == 0)
			graphic->no = cd_extract_pixel(txt);
		else if (i == 1)
			graphic->so = cd_extract_pixel(txt);
		else if (i == 2)
			graphic->we = cd_extract_pixel(txt);
		else
			graphic->ea = cd_extract_pixel(txt);
		if (i <= 3)
			mlx_delete_texture(txt);
		else if (i == 4)
			graphic->f = cd_create_rgba(graphic->paths[i]);
		else if (i == 5)
			graphic->f = cd_create_rgba(graphic->paths[i]);
		free(graphic->paths[i]);
	}
}
