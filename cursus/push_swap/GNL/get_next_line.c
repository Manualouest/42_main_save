/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 20:06:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			line_nlen;
	int			read_chk;

	if (fd < 0 || fd > 1024)
		return (NULL);
	read_chk = BUFFER_SIZE;
	line = ft_strlcat_gnl(save, NULL, 0);
	while (line != NULL && ft_len_str_n_gnl(line, read_chk, 1) == -1)
		line = add_a_read(fd, line, &read_chk);
	if (line == NULL || (read_chk < BUFFER_SIZE
			&& ft_len_str_n_gnl(line, 0, 0) == 0) || (line && line[0] == 0))
		return (ft_free_readd(line, NULL));
	if ((save))
		save = ft_free_readd(save, NULL);
	line_nlen = ft_len_str_n_gnl(line, BUFFER_SIZE, 1);
	if (line_nlen != -1 && ft_len_str_n_gnl(&line[line_nlen + 1], 0, 0) != 0)
		save = ft_free_readd(save, ft_strlcat_gnl(NULL,
					&line[line_nlen + 1], 0));
	if (line[0] != '\n')
		line = ft_get_until_n(line, 1);
	else
		line = ft_free_readd(line, ft_strlcat_gnl(NULL, "\n", 0));
	return (line);
}

char	*add_a_read(int fd, char *current_line, int *read_chk)
{
	char	*part_read;
	char	*result;
	int		nb_read;

	result = ft_strlcat_gnl(current_line, 0, 1);
	if (ft_len_str_n_gnl(result, BUFFER_SIZE, 1) != -1)
		return (result);
	part_read = malloc(BUFFER_SIZE + 1);
	if (!part_read)
		return (NULL);
	nb_read = read(fd, part_read, BUFFER_SIZE);
	if (nb_read < 0 || !part_read)
	{
		free(result);
		free(part_read);
		return (NULL);
	}
	if (nb_read != BUFFER_SIZE)
		*read_chk = nb_read;
	part_read[nb_read] = 0;
	result = ft_strlcat_gnl(result, part_read, 1);
	free(part_read);
	return (result);
}
