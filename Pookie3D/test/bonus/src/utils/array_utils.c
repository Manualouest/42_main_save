/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:28:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:28:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_intlen(int *line)
{
	int	i;

	i = -1;
	while (line[++i] != -1)
		;
	return (i);
}

int	*cd_strtoi_m(char *line, int line_len, int dif)
{
	int	i;
	int	*n_line;

	i = -1;
	if (line_len == -1)
		line_len = ft_strlen(line);
	n_line = malloc(sizeof(int) * (line_len + 1));
	n_line[line_len] = -1;
	while (line[++i])
		n_line[i] = line[i] - dif;
	return (n_line);
}

int	cd_array_len(int **array)
{
	int	i;

	i = 0;
	while (array && array[i][0] != -1)
		i ++;
	return (i);
}

int	**cd_add_new_array_line(int *line, int **array)
{
	int			**new_array;
	int			len_array;
	int			i;

	len_array = cd_array_len(array);
	new_array = malloc(sizeof(*new_array) * (len_array + 2));
	new_array[len_array + 1] = malloc(sizeof(int));
	new_array[len_array + 1][0] = -1;
	new_array[len_array] = line;
	i = -1;
	while (array && ++i < len_array)
		new_array[i] = array[i];
	if (array)
	{
		free(array[len_array]);
		free(array);
	}
	return (new_array);
}

int	*cd_dup_int_list(int *list, int len)
{
	int	i;
	int	*n_list;

	i = -1;
	n_list = malloc(sizeof(*n_list) * (len + 1));
	while (++i < len)
		n_list[i] = list[i];
	return (n_list);
}
