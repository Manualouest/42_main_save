/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/15 15:00:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*file;
	//char		*copy_read;
	int			rd_check;

	if (!fd || BUFFER_SIZE < 1)
	 	return (NULL);
	file = malloc((BUFFER_SIZE  + 1)* sizeof(char));
	if (!file)
		return (NULL);
	rd_check = read(fd, file, BUFFER_SIZE);
	if (rd_check < 1)
	{
		free(file);
		return (NULL);
	}
	if (rd_check == BUFFER_SIZE)
		file[BUFFER_SIZE] = 0;
	else
		file[rd_check] = 0;
	// if (ft_strlen_ncheck(file, rd_check, 1))
	// 	write(1, "yyy", 3);
	return (file);
	//complete_line(file, fd, BUFFER_SIZE);
	return (file);
}

/*
void	ft_putstr(char *str);
int	main(void)
{
	int		fd;
	char	*test;

	fd = open("tests.txt", O_RDONLY);
	test = get_next_line(fd);
	ft_putstr(test);
	free(test);
	test = get_next_line(fd);
	ft_putstr(test);
	free(test);
	test = get_next_line(fd);
	ft_putstr(test);
	free(test);
	close(fd);
	return (0);
}

void	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[pos] != 0)
	{
		write(1, &str[pos], 1);
		pos ++;
	}
}*/