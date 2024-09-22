/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:59:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 21:20:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

t_sphere	**pr_add_sphere(t_sphere **spheres, t_data *data)
{
	t_sphere	**n_spheres;
	int			i;

	n_spheres = ft_calloc(sizeof(*n_spheres), data->nb_sphere + 1);
	n_spheres[data->nb_sphere] = NULL;
	i = -1;
	data->link_lenghts = pr_extend_itab(data->link_lenghts);
	data->sizes = pr_extend_itab(data->sizes);
	data->max_angles = pr_extend_ftab(data->max_angles);
	data->leg_spots = pr_extend_itab(data->leg_spots);
	while (++i < data->nb_sphere)
		n_spheres[i] = spheres[i];
	n_spheres[i] = pr_create_sphere(data, i);
	n_spheres[i]->x = n_spheres[i - 1]->x;
	n_spheres[i]->y = n_spheres[i - 1]->y;
	n_spheres[i]->o = n_spheres[i - 1]->o;
	data->nb_sphere ++;
	free(spheres);
	return (n_spheres);
}

mlx_image_t	*pr_slow_down(struct timeval start_time, t_data *data,
				int target_fps, int do_return)
{
	mlx_image_t		*img;
	struct timeval	end_time;
	char			*fps;
	int				start;
	int				end;

	gettimeofday(&end_time, NULL);
	start = start_time.tv_sec * 1000000 + start_time.tv_usec;
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	while (1000000 / abs(end - start + 1) > target_fps)
	{
		gettimeofday(&end_time, NULL);
		end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	}
	gettimeofday(&end_time, NULL);
	end = end_time.tv_sec * 1000000 + end_time.tv_usec;
	fps = ft_itoa(1000000 / abs(end - start + 1));
	img = mlx_put_string(data->mlx.mlx, fps, 5, -4);
	free(fps);
	if (do_return)
		return (img);
	mlx_delete_image(data->mlx.mlx, img);
	return (NULL);
}

int	pr_rand_color(void)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = abs(rand()) * ((float)0xFF / (float)INT32_MAX);
	g = abs(rand()) * ((float)0xFF / (float)INT32_MAX);
	b = abs(rand()) * ((float)0xFF / (float)INT32_MAX);
	a = 0xFF;
	return  (r << 24 | g << 16 | b << 8 | a);
}

void	pr_put_thick_pixel(mlx_image_t *screen, int x, int y, int thickness, int color)
{
	int	i;
	int	ii;

	i = y - thickness;
	while (++i < y + thickness)
	{
		ii = x - thickness;
		while (++ii < x + thickness)
		{
			if (ii >= 0 && ii < (int)screen->width && i >= 0 && i < (int)screen->height)
				mlx_put_pixel(screen, ii, i, color);
		}
	}
}

float	pr_clamp(float num, float min, float max)
{
	while (num < min)
		num += max;
	while (num > max)
		num -= max;
	return (num);
}