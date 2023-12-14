/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_rush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:51:39 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:51:41 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

// return 0 if line is correct or empty
// return 1001 if there is no numbers on the line.
// return 1002 if there is no ":" after the numbers.
// return 1003 if there is non printable character or value is empty.
int	is_line_correct(char *line)
{
	int		i;
	int		dep;

	i = 0;
	if (line[i] == '\n')
		return (0);
	while (line[i] != 0 && line[i] != '\n' && line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (1001);
	while (line[i] != 0 && line[i] != '\n' && line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (1002);
	i++;
	while (line[i] != 0 && line[i] != '\n' && line[i] == ' ')
		i++;
	dep = i;
	while (line[i] != 0 && line[i] != '\n' && !(line[i] < 32 || line[i] > 126))
		i++;
	if (i != (ft_strlen(line) - 1) || dep == i)
		return (1003);
	return (0);
}

char	**split_base_lines(char **ret, char *base, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < ft_strlen(base))
	{
		k = 0;
		while (base[j + k] != ' ')
		{
			k++;
		}
		ret[i] = (char *)malloc((k + 1) * sizeof(char));
		k = 0;
		while (base[j + k] != ' ')
		{
			ret[i][k] = base[j + k];
			k++;
		}
		ret[i][k] = '\0';
		i++;
		j = j + k;
		if (base[j] == ' ')
			j++;
	}
	return (ret);
}

int	are_base_lines_in_dict(char **ret, char **dict, int size_dict)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	while (i < 32)
	{
		found = 0;
		j = 0;
		while (j < size_dict && found == 0)
		{
			if (dict[j] != NULL)
			{
				if (ft_strcmp(ret[i], dict[j]) == 0)
					found = 1;
			}
			j++;
		}
		if (found == 0)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

char	**get_base_lines(char **ret)
{
	char	*base;
	char	*base2;

	base = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 30 40";
	base2 = "50 60 70 80 90 100 1000 1000000 1000000000";
	ret = split_base_lines(ret, base, 0);
	ret = split_base_lines(ret, base2, 23);
	return (ret);
}

//return 1 if it contain a line that isnt correct
// 0 if all lines are correct
int	is_dico_well_parsed(char *str)
{
	int		tab_ind[3];
	char	*line;

	tab_ind[0] = 0;
	tab_ind[1] = 0;
	while (str[tab_ind[0]])
	{
		if (str[tab_ind[0]] == '\n')
		{
			tab_ind[2] = 0;
			line = (char *)malloc((tab_ind[0] - tab_ind[1] + 2) * sizeof(char));
			while (tab_ind[1] <= tab_ind[0])
				line[tab_ind[2]++] = str[tab_ind[1]++];
			line[tab_ind[2]] = '\0';
			tab_ind[1] = tab_ind[0] + 1;
			if (is_line_correct(line) != 0)
			{
				free(line);
				return (1);
			}
			free(line);
		}
		tab_ind[0]++;
	}
	return (0);
}
