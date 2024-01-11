/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:41:32 by mbirou            #+#    #+#             */
/*   Updated: 2023/09/05 18:53:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "str.h"

char	*ft_make_line(char *map, char *params, int pos_init, int len_line)
{
	char	*line;
	int		pos;

	pos = 0;
	line = malloc((len_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (pos < len_line)
	{
		if (map[pos_init + pos] == params[0])
			line[pos] = '1';
		else if (map[pos_init + pos] == params[1])
			line[pos] = '0';
		else if (map[pos_init + pos] != '\n')
		{
			free(line);
			return (NULL);
		}
		pos ++;
	}
	line[pos] = 0;
	return (line);
}

char	**ft_free_matrix(char **matrix, char *params, int nb_mallocs)
{
	int	pos;

	pos = 0;
	while (pos < nb_mallocs)
	{
		free(matrix[pos]);
		pos ++;
	}
	free(params);
	free(matrix);
	return (NULL);
}

char	**ft_matrix_map_maker(char *map, int nb_line)
{
	char	**matrix;
	char	*params;
	int		pos1;
	int		len_line;
	int		map_start;

	matrix = malloc((nb_line) * sizeof(char *));
	params = ft_get_params(map, nb_line);
	len_line = ft_get_line_len(map, nb_line);
	map_start = ft_find_start_index(map);
	if (!matrix || params == NULL || len_line == 0 || map_start == 0)
	{
		ft_free_matrix(matrix, params, 0);
		return (NULL);
	}
	pos1 = -1;
	while (pos1++ + 1 < nb_line - 1)
	{
		matrix[pos1] = ft_make_line(map, params, map_start, len_line);
		if (matrix[pos1] == NULL)
			return (ft_free_matrix(matrix, params, pos1));
		map_start = map_start + len_line + 1;
	}
	free(params);
	return (matrix);
}

char	**ft_readmap(char *filename)
{
	char	**map_matrix;
	char	buff[1000000];
	int		file_descr;
	int		file_size;
	int		nb_lines;

	file_descr = open(filename, O_RDONLY);
	file_size = read(file_descr, buff, 100000);
	close(file_descr);
	buff[file_size] = 0;
	if (file_size < 0)
		return (NULL);
	nb_lines = ft_count_lines(buff);
	map_matrix = ft_matrix_map_maker(buff, nb_lines);
	if (map_matrix == NULL || buff[0] == '0')
	{
		return (NULL);
	}
	return (map_matrix);
}

char	**ft_find_params_only(char *filename)
{
	char	**params;
	char	buff[1000000];
	int		file_descr;
	int		file_size;
	int		nb_lines;

	params = malloc(2 * sizeof(char *));
	file_descr = open(filename, O_RDONLY);
	file_size = read(file_descr, buff, 1000000);
	close(file_descr);
	buff[file_size] = 0;
	if (file_size < 0)
		return (NULL);
	nb_lines = ft_count_lines(buff);
	params[0] = ft_itostr(nb_lines);
	params[1] = ft_get_params(buff, nb_lines);
	if (params == NULL)
		return (NULL);
	return (params);
}
