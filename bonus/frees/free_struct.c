/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:39:48 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cd_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
}

void	cd_free_mlx_info(t_mlx_info *mlx_info)
{
	mlx_destroy_image(mlx_info->mlx, mlx_info->main_frame->img);
	mlx_destroy_image(mlx_info->mlx, mlx_info->refresh_frame->img);
	mlx_destroy_image(mlx_info->mlx, mlx_info->south->img);
	mlx_destroy_image(mlx_info->mlx, mlx_info->north->img);
	mlx_destroy_image(mlx_info->mlx, mlx_info->west->img);
	mlx_destroy_image(mlx_info->mlx, mlx_info->east->img);
	free(mlx_info->south);
	free(mlx_info->north);
	free(mlx_info->west);
	free(mlx_info->east);
	free(mlx_info->mlx);
}

void	cd_free_info(t_info *info)
{
	free(info->north);
	free(info->south);
	free(info->west);
	free(info->east);
	free(info->floor);
	free(info->ceiling);
	cd_free_tab(info->map);
	free(info->p_pos);
	cd_free_mlx_info(info->mlx_info);
	free(info->mlx_info);
	free(info);
}
