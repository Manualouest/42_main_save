/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/30 15:30:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

char	*gnl_add_a_read(int fd, char *current_line, int *read_chk);

char	*gnl(int fd)
{
	static char	*save;
	char		*line;
	int			line_nlen;
	int			read_chk;

	if (fd < 0 || fd > 1024)
		return (NULL);
	read_chk = BUFFER_SIZE;
	line = gnl_strlcat(save, NULL, 0);
	while (line != NULL && gnl_len_str_n(line, read_chk, 1) == -1)
		line = gnl_add_a_read(fd, line, &read_chk);
	if (line == NULL || (read_chk < BUFFER_SIZE
			&& gnl_len_str_n(line, 0, 0) == 0) || (line && line[0] == 0))
		return (gnl_free_readd(line, NULL));
	if ((save))
		save = gnl_free_readd(save, NULL);
	line_nlen = gnl_len_str_n(line, BUFFER_SIZE, 1);
	if (line_nlen != -1 && gnl_len_str_n(&line[line_nlen + 1], 0, 0) != 0)
		save = gnl_free_readd(save, gnl_strlcat(NULL, &line[line_nlen + 1], 0));
	if (line[0] != '\n')
		line = gnl_get_until_n(line, 1);
	else
		line = gnl_free_readd(line, gnl_strlcat(NULL, "\n", 0));
	return (line);
}

char	*gnl_add_a_read(int fd, char *current_line, int *read_chk)
{
	char	*part_read;
	char	*result;
	int		nb_read;

	result = gnl_strlcat(current_line, 0, 1);
	if (gnl_len_str_n(result, BUFFER_SIZE, 1) != -1)
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
	result = gnl_strlcat(result, part_read, 1);
	free(part_read);
	return (result);
}
