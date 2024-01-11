/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:18:50 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/06 10:21:35 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "str.h"

int	ft_get_map_line_len(char **map);

int	main(int argc, char **argv)
{
	char	**map;
	char	**param;
	int		pos;
	int		l_len;

	pos = 1;
	while (pos < argc)
	{
		map = ft_readmap(argv[pos]);
		param = ft_find_params_only(argv[pos]);
		if (map != NULL && param != NULL)
		{
			l_len = ft_get_map_line_len(map);
			find_largest_square(map, ft_atoi(param[0]) - 1, l_len);
			ft_map_printer(map, param[1], ft_atoi(param[0]) - 1, l_len);
			free_work_map(map, ft_atoi(param[0]) - 1);
		}
		else
			write(1, "Map error\n", 10);
		free_work_map(param, 2);
		pos++;
	}
}

int	ft_get_map_line_len(char **map)
{
	int	pos;

	pos = 0;
	while (map[0][pos] != 0)
		pos ++;
	return (pos);
}
