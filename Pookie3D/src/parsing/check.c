/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:18:09 by malbrech          #+#    #+#             */
/*   Updated: 2024/11/16 22:35:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

void	check_name_png(char *txt, t_game *game)
{
	int	i;

	i = 0;
	while (txt[i] != '\0')
		i++;
	if (!(txt[i - 1] == 'g' && txt[i - 2] == 'n'
			&& txt[i - 3] == 'p' && txt[i - 4] == '.'))
	{
		error_handler(PNG_ERR, game, NULL);
	}
}
