/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:11:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_get_floor_roof(char *rgb)
{
	char	**cut_rgb;
	int		trgb;

	cut_rgb = ft_split(rgb, ',');
	trgb = cd_get_hex(0, ft_atoi(cut_rgb[0]), ft_atoi(cut_rgb[1]),
		ft_atoi(cut_rgb[2]));
	cd_free_tab(cut_rgb);
	return (trgb);
}
#include <stdio.h>
void	cd_change_pixel_color(t_frame_info *frame, int x, int y, int color)
{
	char	*dst;

	// frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel, &frame->line_size, &frame->endian);
	dst = frame->addr + (y * frame->line_size + x * (frame->bits_per_pixel / 8));
	if (dst)
		*(unsigned int*)dst = color;
}

void	cd_clean_frame(t_mlx_info *mlx_info, t_frame_info *frame)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mlx_info->w_height)
	{
		x = -1;
		while (++x < mlx_info->w_width)
			cd_change_pixel_color(frame, x, y, 0x000000FF);
	}
}

unsigned int	**cd_setup_tab(t_frame_info *frame_info)
{
	int				i;
	int				ii;
	unsigned int	**tab;

	i = -1;
	tab = ft_calloc(sizeof(*tab), frame_info->height + 1);
	while (++i < frame_info->height)
	{
		ii = -1;
		tab[i] = ft_calloc(sizeof(*tab[i]), frame_info->width + 1);
		while (++ii < frame_info->width)
			tab[i][ii] = *(unsigned int *)(frame_info->addr + (i * frame_info->line_size + ii *
				(frame_info->bits_per_pixel / 8)));
	}
	return (tab);
}

void	cd_setup_frame_info(t_frame_info *frame_info, void *img, int height, int width)
{
	frame_info->img = img;
	frame_info->bits_per_pixel = 0;
	frame_info->line_size = 0;
	frame_info->endian = 0;
	frame_info->addr = mlx_get_data_addr(frame_info->img, &frame_info->bits_per_pixel, &frame_info->line_size, &frame_info->endian);
	frame_info->height = height;
	frame_info->width = width;
	frame_info->tab = cd_setup_tab(frame_info);
}

void	cd_get_img_info(t_frame_info *frame_info, t_mlx_info *mlx_info, char *filename)
{
	int		height;
	int		width;
	void	*img;

	height = 1;
	width = 1;
	img = mlx_xpm_file_to_image(mlx_info->mlx, filename, &width, &height);
	cd_setup_frame_info(frame_info, img, height, width);
}

void	cd_setup_img(t_info *info)
{
	// void	*m_frame;
	// void	*r_frame;

	info->mlx_info->north = malloc(sizeof(*info->mlx_info->north));
	info->mlx_info->south = malloc(sizeof(*info->mlx_info->south));
	info->mlx_info->west = malloc(sizeof(*info->mlx_info->west));
	info->mlx_info->east = malloc(sizeof(*info->mlx_info->east));
	cd_get_img_info(info->mlx_info->north, info->mlx_info, info->north);
	cd_get_img_info(info->mlx_info->south, info->mlx_info, info->south);
	cd_get_img_info(info->mlx_info->west, info->mlx_info, info->west);
	cd_get_img_info(info->mlx_info->east, info->mlx_info, info->east);
	info->mlx_info->main_frame = malloc(sizeof(*info->mlx_info->main_frame));
	info->mlx_info->refresh_frame = malloc(sizeof(*info->mlx_info->refresh_frame));
	// m_frame = mlx_new_image(info->mlx_info->mlx, info->mlx_info->w_width, info->mlx_info->w_height);
	// r_frame = mlx_new_image(info->mlx_info->mlx, info->mlx_info->w_width, info->mlx_info->w_height);
	cd_setup_frame_info(info->mlx_info->main_frame, mlx_new_image(info->mlx_info->mlx, info->mlx_info->w_width, info->mlx_info->w_height), info->mlx_info->w_height, info->mlx_info->w_width);
	cd_setup_frame_info(info->mlx_info->refresh_frame, mlx_new_image(info->mlx_info->mlx, info->mlx_info->w_width, info->mlx_info->w_height), info->mlx_info->w_height, info->mlx_info->w_width);
	cd_clean_frame(info->mlx_info, info->mlx_info->refresh_frame);
}

void	cd_setup_mlx_main(t_info *info)
{
	info->mlx_info->mlx = mlx_init();
	info->mlx_info->w_width = 1280; //1280, 1920
	info->mlx_info->w_height = 720; //720, 1080
	info->mlx_info->s_width = 50;
	info->mlx_info->s_height = 50;
	info->mlx_info->fov = M_PI / 3.0;
	info->mlx_info->floor = cd_get_floor_roof(info->floor);
	info->mlx_info->roof = cd_get_floor_roof(info->ceiling);
	cd_setup_img(info);
}
