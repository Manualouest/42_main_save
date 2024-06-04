/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:24:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/08 03:01:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

int	sl_free_t_map_info(t_map_info *map_info)
{
	int	i;

	i = -1;
	if (map_info->map)
	{
		while (map_info->map[++i] != 0)
			free(map_info->map[i]);
		free(map_info->map[i]);
		free(map_info->map);
		i = -1;
	}
	if (map_info->map_copy)
	{
		while (map_info->map_copy[++i] != 0)
			free(map_info->map_copy[i]);
		free(map_info->map_copy[i]);
		free(map_info->map_copy);
	}
	return (0);
}

int	sl_parsing_error(int err, t_map_info *mp_inf, char **extra, int freem)
{
	if (err == 2)
		write(2, "Map edges invalid.\n", 19);
	else if (err == 3)
		write(2, "Invalid character detected.\n", 28);
	else if (err == 4)
		write(2, "Your map isn't a rectangle.\n", 28);
	else if (err == 5)
		write(2, "Wrong number of player, exit or collectible.\n", 45);
	else if (err == 6)
		write(2, "The map is impossible to complete.\n", 35);
	if (freem)
		sl_free_t_map_info(mp_inf);
	free(*extra);
	return (0);
}

void	sl_get_map(char *file_name, char **map_full, int *tpint)
{
	char	*n_line;

	*tpint = open(file_name, O_RDONLY);
	n_line = gnl(*tpint);
	if (n_line == NULL)
		return ;
	*map_full = NULL;
	while (n_line != NULL)
	{
		*map_full = gnl_strlcat(*map_full, n_line, 1);
		free(n_line);
		n_line = gnl(*tpint);
	}
	free(n_line);
}
