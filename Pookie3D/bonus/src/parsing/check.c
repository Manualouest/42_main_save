/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:16:58 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:16:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	check_name_cub(char *path, t_game *game)
{
	int	i;

	i = 0;
	while (path[i] != '\0')
		i++;
	if (!(path[i - 1] == 'b' && path[i - 2] == 'u'
			&& path[i - 3] == 'c' && path[i - 4] == '.'))
	{
		error_handler(CUB_ERR, game, NULL);
	}
}

void	check_name_png(char *path, t_game *game, char *o_line)
{
	int	i;

	i = 0;
	while (path[i] != '\0')
		i++;
	if (!(path[i - 1] == 'g' && path[i - 2] == 'n'
			&& path[i - 3] == 'p' && path[i - 4] == '.'))
	{
		error_handler(PNG_ERR, game, o_line);
	}
}
