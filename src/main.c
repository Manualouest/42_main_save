/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:04:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 20:03:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

// ./proced 15 "60 40 40 40 40 40 40 40 40 40 40 40 40 40 40" "40 40 40 40 40 40 40 40 40 40 40 40 40 40 40" "40 40 40 40 40 40 40 40 40 40 40 40 40 40 40"

int	main(int argc, char **argv)
{
	t_data	data;
	pr_init_data(argc, argv, &data);


	int	i = -1;
	printf("nb_spheres: %d\n", data.nb_sphere);
	printf("size: ");
	while (data.sizes[++i] != -1)
		printf("%d, ", data.sizes[i]);
	i = -1;
	printf("\nlink_lenghts: ");
	while (data.link_lenghts[++i] != -1)
		printf("%d, ", data.link_lenghts[i]);
	i = -1;
	printf("\nmax_angles: ");
	while (data.max_angles[++i] != -1)
		printf("%f, ", data.max_angles[i]);
	i = -1;
	printf("\nleg_spots: ");
	while (data.leg_spots[++i] != -1)
		printf("%d, ", data.leg_spots[i]);
	i = -1;
	printf("\n");
	while (++i < data.nb_sphere)
		printf("sphere %d:\n\tx: %f\n\ty: %f\n\to: %f\n\tr: %d\n\tlink_len: %d\n\tmax_angle: %f\n", i, data.spheres[i]->x, data.spheres[i]->y, data.spheres[i]->o, data.spheres[i]->r, data.spheres[i]->link_len, data.spheres[i]->max_angle);

	pr_display_main(&data);
	
}