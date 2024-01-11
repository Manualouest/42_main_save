/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:51:22 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/05 12:58:04 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	free_work_map(char **work_map, int l_size)
{
	int	i;

	i = 0;
	while (i < l_size)
	{
		free(work_map[i]);
		i++;
	}
	free(work_map);
}

int	get_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	ft_swap(char *str)
{
	char	temp;

	temp = str[0];
	str[0] = str[1];
	str[1] = temp;
}

void	ft_map_printer(char **map, char *charset, int l_line, int c_line)
{
	t_coord	coord;
	int		print_char;

	coord.x = 0;
	print_char = 0;
	ft_swap(charset);
	while (coord.x < l_line)
	{
		coord.y = 0;
		while (coord.y < c_line)
		{
			print_char = map[coord.x][coord.y] - '0';
			write(1, &charset[print_char], 1);
			coord.y++;
		}
		write(1, "\n", 1);
		coord.x++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	temp;

	num = 0;
	sign = 1;
	temp = 0;
	while (str[temp] != 0 && (str[temp] == ' '
			|| (str[temp] >= 9 && str[temp] <= 13)))
		temp ++;
	while (str[temp] != 0
		&& (str[temp] == '+' || str[temp] == '-'))
	{
		if (str[temp] == '-')
			sign = sign * -1;
		temp ++;
	}
	while (str[temp] != 0 && (str[temp] >= '0' && str[temp] <= '9'))
		num = num * 10 + (str[temp++] - '0');
	return (num * sign);
}
