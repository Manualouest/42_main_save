/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/17 16:18:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(char *text, int fd, char **end_save);
static char	*hell_joiner(char *s1, char *s2, int tt_read, char **end_save);

char	*get_next_line(int fd)
{
	static int	line;
	static char	*end_save;
	int			read_len;
	int			i;
	char		*text;
	
	text = malloc(0);
	if (end_save != NULL && line != 0)
		text = hell_joiner(end_save, reader(text, fd, &end_save), 0, &end_save);
	else
		text = reader(text, fd, &end_save);
	line ++;
	return (text);
}

static char	*reader(char *text, int fd, char **end_save)
{
	int		i;
	char	*temp_text;
	size_t	curr_read;
	size_t	tt_read;

	i = 0;
	temp_text = malloc(1);
	temp_text[0] = 0;
	
	curr_read = 0;
	tt_read = 0;
	while (curr_read == 0 || ft_strlen_ncheck(temp_text, tt_read, 1) == -1)
	{
		free(text);
		text = malloc(BUFFER_SIZE + 1);
		curr_read = read(fd, text, BUFFER_SIZE);
		text[curr_read] = 0;
		tt_read += curr_read;
		temp_text = hell_joiner(temp_text, text, tt_read, end_save);
	}
	text[0] = 0;
	i ++;
	/*
	if (ft_strlen_ncheck(temp_text, tt_read, 1) < (ft_strlen_ncheck(temp_text, tt_read, 0)  - 1))
	{
		*end_save = malloc(ft_strlen_ncheck(&temp_text[ft_strlen_ncheck(temp_text, tt_read, 1) + 1], tt_read, 0));
		*end_save = &temp_text[ft_strlen_ncheck(temp_text, tt_read, 1) + 1];
	}               */
	free(text);
	return (temp_text);
}

static char	*hell_joiner(char *s1, char *s2, int tt_read, char **end_save)
{
	int	len;
	char		*s_join;
	int			pos;
	int			pos2;

	pos2 = 0;
	pos = -1;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen_ncheck(s1, 0, 0) + ft_strlen_ncheck(s2, 0, 0));
	s_join = malloc((len + 1) * sizeof(char));
	if (!s_join)
		return (NULL);
	while (s1[++pos] != 0)
		s_join[pos] = s1[pos];
	while (s2[pos2] != 0 && s2[pos2 - 1] != '\n')
	{
		s_join[pos + pos2] = s2[pos2];
		pos2 ++;
	}
	if (s2[pos2 - 1] == '\n' && s2[pos2] != 0)
	{
		*end_save = malloc(ft_strlen_ncheck(&s2[ft_strlen_ncheck(s2, tt_read, 1) + 1], tt_read, 0));
		*end_save = &s2[ft_strlen_ncheck(s2, tt_read, 1) + 1];
	}
	s_join[pos + pos2] = 0;
	if (tt_read != 0)
		free(s1);
	return (s_join);
}











#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*test;

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
	close(fd);
	return (0);
}