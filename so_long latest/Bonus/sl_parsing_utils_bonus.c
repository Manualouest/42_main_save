/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:49:09 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/06 13:39:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

int	sl_has_empty_lines(char *map_full)
{
	int	i;

	i = -1;
	if (map_full[0] == '\n')
		return (1);
	while (map_full[++i] != 0)
		if (i > 0 && map_full[i] == '\n' && map_full[i - 1] == '\n')
			return (1);
	return (0);
}

int	check_file_type(char *map_file)
{
	int	len;

	len = gnl_len_str_n(map_file, 0, 0);
	if (map_file[len - 1] == 'r'
		&& map_file[len - 2] == 'e'
		&& map_file[len - 3] == 'b'
		&& map_file[len - 4] == '.')
		return (1);
	return (0);
}
