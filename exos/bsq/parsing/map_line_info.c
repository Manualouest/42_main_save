#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

int	ft_count_lines(char *file)
{
	int	pos;
	int	nb_lines;

	pos = 0;
	nb_lines = 0;
	while (file[pos] != 0)
	{
		if (file[pos] == '\n')
			nb_lines++;
		pos ++;
	}
	return (nb_lines);
}

int	ft_check_linenb_param(char *map, int nb_line, int last_pos)
{
	int	nb;
	int	pos;

	nb = 0;
	pos = 0;
	while (pos < last_pos)
	{
		if (!(map[pos] >= '0' && map[pos] <= '9'))
			return (0);
		nb = (nb * 10) + (map[pos] - '0');
		pos ++;
	}
	if (nb != nb_line - 1)
		return (0);
	return (1);
}

char	*ft_get_params(char *map, int nb_line)
{
	char	*params;
	int		pos;

	pos = 0;
	while (map[pos] != '\n')
	{
		pos ++;
	}
	params = malloc(4 * sizeof(char));
	params[0] = map[pos - 3];
	params[1] = map[pos - 2];
	params[2] = map[pos - 1];
	params[3] = 0;
	if (params[0] == params[1] || params[0] == params[2]
		|| params[1] == params[2]
		|| !(params[0] >= 32)
		|| !(params[1] >= 32)
		|| !(params[2] >= 32)
		|| ft_check_linenb_param(map, nb_line, pos - 3) == 0)
		return (NULL);
	return (params);
}

int	ft_get_line_len(char *map, int nb_line)
{
	int	pos1;
	int	pos2;
	int	line_len_st;
	int	line_len;
	int	diff_check;

	pos1 = 0;
	line_len_st = 0;
	diff_check = 0;
	pos2 = 0;
	while (pos1 < nb_line && diff_check < 3)
	{
		line_len = 0;
		while (map[pos2++] != '\n' && map[pos2 - 1] != 0)
			line_len ++;
		if (line_len > line_len_st)
			diff_check ++;
		line_len_st = line_len;
		pos1 ++;
	}
	if (diff_check > 2)
		return (0);
	return (line_len_st);
}

int	ft_find_start_index(char *map)
{
	int	pos;
	int	tt_len;

	pos = 0;
	tt_len = ft_strlen(map);
	while (map[pos] != '\n' && pos < tt_len)
	{
		pos ++;
	}
	if (pos == tt_len || pos == 0)
		return (0);
	return (pos + 1);
}
