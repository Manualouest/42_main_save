/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/18 21:17:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_a_read(int fd, char *current_line, int *save_len);

char	*get_next_line(int fd)
{
	static char	*save;
	int			save_len;
	char		*line;
	int			line_len;

	if (fd < 1)
		return (NULL);
	save_len = 0;
	if (save != 0)
	{
		save_len = ft_len_str_n(save, 0, 0);
		line = ft_strlcat(save, NULL, 0);
	}
	else
		line = ft_strlcat(NULL, NULL, 0);
	while (ft_len_str_n(line, BUFFER_SIZE, 1) == -1 && save_len >= 0)
	{
		line = add_a_read(fd, line, &save_len);
		if (line == NULL)
			return (NULL);
	}
	line_len = ft_len_str_n(line, 0, 0);
	//// (((save_len - line_len) % BUFFER_SIZE == 0) || (save_len == line_len))
	//// (ft_len_str_n(&line[ft_len_str_n(line, BUFFER_SIZE, 1) + 1], BUFFER_SIZE, 1) != -1 || (save_len == line_len))
	free(save);
	if (save_len == -1)
	{
		if (ft_len_str_n(&line[ft_len_str_n(line, BUFFER_SIZE, 1) + 1], BUFFER_SIZE, 1) != -1 || (save_len == line_len))
		{
			save = ft_strlcat(&line[ft_len_str_n(line, BUFFER_SIZE, 1) + 1], 0, 0);
			if (save == NULL)
				return (NULL);
		}
	}
	else
	{
		if (((save_len - line_len) % BUFFER_SIZE == 0) || (save_len == line_len))
		{
			save = ft_strlcat(&line[ft_len_str_n(line, BUFFER_SIZE, 1) + 1], 0, 0);
			if (save == NULL)
				return (NULL);
		}
	}
	line = ft_get_until_n(line, 1);
	return (line);
}

static char	*add_a_read(int fd, char *current_line, int *save_len)
{
	char	*part_read;
	char	*result;
	int		nb_read;

	result = ft_strlcat(current_line, 0, 1);
	if (ft_len_str_n(result, BUFFER_SIZE, 1) != -1)
		return (result);
	part_read = malloc(BUFFER_SIZE + 1);
	if (!part_read)
		return (NULL);
	nb_read = read(fd, part_read, BUFFER_SIZE);
	if (nb_read < 0 || !part_read)
	{
		free(part_read);
		return (NULL);
	}
	if (nb_read != BUFFER_SIZE)
		*save_len = -1;
	part_read[nb_read] = 0;
	result = ft_strlcat(result, part_read, 1);
	free(part_read);
	return (result);
}

#include <stdio.h>
int	main(void)
{
	int			fd;
	char		*test;
	static char	*save;

	fd = open("tests.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	close(fd);
	free(save);
	return (0);
}
