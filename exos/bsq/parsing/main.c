int	main(int argc, char **argv)
{
	char	**map;
	char	*params;
	int	pos;
	int	nb_lines;
	int	line_len;

	pos = 1;
	while (pos < argc)
	{
		map = ft_readmap(argv[pos]);
		params = ft_find_params_only(argv[pos]);
		if (map != NULL || params != NULL)
		{
			nb_lines = ft_get_nbline(map);
			line_len = ft_get_line_len(map);
			find_largest_square(map, nb_lines, line_len);
			ft_map_printer(map, nb_line, line_len, params);
			free_work_map(map, nb_line);
			free(params);
		}
		else
		{
			free_work_map(map, nb_line);
			free(params);
			write(1, "Error\n", 6);
		}
	}
}

int	ft_get_nbline(char **map)
{
	int	pos;

	pos = 0;
	while (map[pos] != 0)
		pos ++;
	return (pos);
}

int	ft_get_line_len(char **map)
{
	int	pos;

	pos = 0;
	while (map[0][pos] != 0)
		pos ++;
	return (pos);
}
