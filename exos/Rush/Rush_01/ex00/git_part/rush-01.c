/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:34:54 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/26 09:34:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	arg_num_check(char *args)
{
	int	len;
	int	double_char_check;

	len = 0;
	double_char_check = 0;
	while (*args != 0 && len >= 0)
	{
		if (*args == ' ')
			double_char_check --;
		else if (*args >= '1' || *args <= '9')
			double_char_check ++;
		if (*args != ' ')
			len ++;
		if (((*args < '1' || *args > '9')
				&& *args != ' ')
			|| (double_char_check < 0 || double_char_check > 1))
		{
			len = -2;
		}
		args ++;
	}
	if (len % 4 == 0 && len > 0 && double_char_check == 1)
		return (len);
	else
		return (0);
}

char	*arg_list_maker(char *args, int nb_args)
{
	char	*list_args;
	int		pos;

	list_args = malloc(nb_args * sizeof(int));
	pos = 0;
	while (*args != 0)
	{
		if (*args >= '1' && *args <= '9')
		{
			list_args[pos] = *args;
			pos ++;
		}
		args ++;
	}
	return (list_args);
}

int	arg_checker(char *args, int len_args)
{
	int	pos;

	pos = 0;
	while (args[pos + (len_args / 4)] != 0)
	{
		if (!((args[pos] != ' ')
				&& ((args[pos] - '0') + \
				(args[pos +(len_args / 4)] - '0') >= 3)
				&& ((args[pos] - '0') + \
				(args[pos +(len_args / 4)] - '0') <= (len_args / 4 + 1))))
		{
			pos = 0;
			break ;
		}
		if (pos == len_args / 4 - 1)
		{
			pos = len_args / 2 - 1;
		}
		pos ++;
	}
	if (pos == len_args - (len_args / 4))
		return (1);
	else
		return (0);
}

void	main_checker(int argc, char **argv)
{
	int		len_check;
	char	*num_list;

	if (argc > 2 || argc < 2)
		write(1, "Error\n", 6);
	else
	{
		len_check = arg_num_check(argv[1]);
		if (len_check > 0)
		{
			num_list = malloc(len_check * sizeof(int));
			num_list = arg_list_maker(argv[1], len_check);
			if (len_check == 4 && (num_list[0] == 1
					&& num_list[1] == 1 && num_list[2] == 1 && num_list[3] == 1))
				write(1, "1\n", 1);
			else if (len_check > 4)
			{
				if (arg_checker(num_list, len_check) == 1);
					
				else
					write(1, "Error\n", 6);
			}
		}
		else
			write(1, "Error\n", 6);
	}
}
