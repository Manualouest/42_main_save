/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:04:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/21 20:00:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

// ./proced 15 "60 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40" "10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10" "40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40"
// ./proced 500 10 1 1 "0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	pr_init_data(argc, argv, &data);


	// int	i = -1;
	// printf("nb_spheres: %d\n", data.nb_sphere);
	// printf("size: ");
	// while (data.sizes[++i] != -1)
	// 	printf("%d, ", data.sizes[i]);
	// i = -1;
	// printf("\nlink_lenghts: ");
	// while (data.link_lenghts[++i] != -1)
	// 	printf("%d, ", data.link_lenghts[i]);
	// i = -1;
	// printf("\nmax_angles: ");
	// while (data.max_angles[++i] != -1)
	// 	printf("%f, ", data.max_angles[i]);
	// i = -1;
	// printf("\nleg_spots: ");
	// while (data.leg_spots[++i] != -1)
	// 	printf("%d, ", data.leg_spots[i]);
	// i = -1;
	// printf("\n");
	// while (++i < data.nb_sphere)
	// 	printf("sphere %d:\n\tx: %f\n\ty: %f\n\to: %f\n\tr: %d\n\tlink_len: %d\n\tmax_angle: %f\n", i, data.spheres[i]->x, data.spheres[i]->y, data.spheres[i]->o, data.spheres[i]->r, data.spheres[i]->link_len, data.spheres[i]->max_angle);
	// i = -1;
	// printf("\n");
	// while (++i < 629)
	// {
	// 	printf("cos: %f, ", data.vars.cos[i]);
	// 	printf("sin: %f\t", data.vars.sin[i]);
	// }
	// printf("\n");

	pr_display_main(&data);


	printf("\ntotal spheres: %d\n", data.nb_sphere);
	i = -1;
	while (data.spheres[++i])
	{
		if (data.spheres[i]->x < 0 || data.spheres[i]->x >= data.mlx.w_width || data.spheres[i]->y < 0 || data.spheres[i]->y >= data.mlx.w_height)
			break ;
	}
	printf("spheres on screen: %d\n", i);

	free(data.sizes);
	free(data.link_lenghts);
	free(data.max_angles);
	free(data.vars.cos);
	free(data.vars.sin);
	i = -1;
	while (data.spheres[++i])
	{
		if (data.leg_spots[i] == 1)
		{
			free(data.spheres[i]->l_leg->elbow);
			free(data.spheres[i]->l_leg->hand);
			free(data.spheres[i]->l_leg);
		}
		if (data.leg_spots[i] == 1)
		{
			free(data.spheres[i]->r_leg->elbow);
			free(data.spheres[i]->r_leg->hand);
			free(data.spheres[i]->r_leg);
		}
		free(data.spheres[i]);
	}
	free(data.leg_spots);
	free(data.spheres);
}