/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:54:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/07 20:02:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_s_link	slink;
	char		*map_file;

	slink.error = 0;
	if (argc == 1)
		map_file = cd_map_maker();
	else
		map_file = ft_strdup(argv[1]);
	if (!map_file)
		return (0);
	printf("%s", map_file);
	if (argc > 2)
		return (0);
	// parsing(&slink, map_file);
	free(map_file);
	if (slink.error == 0)
		return (0);
	// launch_game(slink);
	return (1);
}
