/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:44:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	cdd_debug_info(t_info *info);

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (0);
	info = malloc(sizeof(*info));
	if (!cd_setup_info(info, argv[1]))
		return (0);

	cdd_debug_info(info);

	cd_hook_init(info);

	cd_free_info(info);
	return (0);
}

#include <stdio.h>
void	cdd_debug_info(t_info *info)
{
	printf("north: %s\n", info->north);
	printf("south: %s\n", info->south);
	printf("west: %s\n", info->west);
	printf("east: %s\n", info->east);
	printf("floor: %s\n", info->floor);
	printf("ceiling: %s\n", info->ceiling);
	printf("map: \n");
	int	i = -1;
	while (info->map[++i])
		printf("	%s\n", info->map[i]);
	printf("height: %d, width: %d\n", info->m_height, info->m_width);
	printf("pos; x: %f, y: %f, orient: %f\n", info->p_pos->x, info->p_pos->y, info->p_pos->orientation);
}
