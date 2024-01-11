/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:18:46 by mbirou            #+#    #+#             */
/*   Updated: 2023/09/02 10:13:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_strfind_main(char *to_find,char *filename);
int	ft_strlen(char *str);

int	ft_intlen(int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i ++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	pos;
	int	pos2;

	pos2 = 0;
	pos = 0;
	while (dest[pos] != 0)
	{
		pos ++;
	}
	while (src[pos2] != 0)
	{
		dest[pos] = src[pos2];
		pos ++;
		pos2 ++;
	}
	dest[pos] = 0;
	return (dest);
}

char	**ft_separator2(int pos, char *input, int len, int unit_incr)
{
	char	**tp_tab;
	int	pos2;
	
	pos2 = 1;
	if ((pos % 4 == 2 || pos % 4 == 1) && pos != 0)
	{
		tp_tab = malloc(1 * sizeof(char *));
		tp_tab[0] = malloc (3 * sizeof(char));
		tp_tab[0][0] = input[pos - (pos / 4)];
		tp_tab[0][1] = *"\0";
	}
	if (pos % 4 == 3 && pos != 0)
	{
		tp_tab = malloc(2 * sizeof(char *));
		tp_tab[0] = malloc((unit_incr + 1) * sizeof(char *));
		tp_tab[0][0] = *"1";
		while (pos2 <= unit_incr)
			tp_tab[0][pos2 ++] = *"0\0";
		tp_tab[0][pos2] = *"\0";
	}
	if (pos % 4 == 0 || pos == 0)
	{
		tp_tab = malloc(2 * sizeof(char *));
		tp_tab[0] = malloc (2 * sizeof(char));
		tp_tab[0][0] = input[pos - (pos / 4)];
		tp_tab[0][1] = *"\0";
		tp_tab[1] = "100\0";
	}
	return (tp_tab);
}
char	***ft_separator(char *input, int len)
{
	char	***mega_inp;
	int		pos;
	int		unit_incr;
	int		nb_loop;

	mega_inp = malloc((len + (len / 3 - 1) + 1) * sizeof(char **));
	pos = 0;
	unit_incr = len - 3;
	nb_loop = (len + (len / 3 - 1));
	if (len == 3)
		nb_loop = 3;
	while (pos < nb_loop)
	{
		mega_inp[pos] = (ft_separator2(pos, input, len, unit_incr));
		if (pos % 4 == 1)
		{
			mega_inp[pos][0][1] = *"0";
			mega_inp[pos][0][2] = *"\0";
		}
		if (pos % 4 == 3 && pos != 0)
			unit_incr = unit_incr - 3;
		pos ++;
	}
	free(input);
	return (mega_inp);
}

void	ft_cutter_for_printer(char ***mega_tab, int nb_num, int len_mt, char *filename)
{
	int	pos1;
	char	*tp_str;

	pos1 = 0;
	while (pos1 <= nb_num)
	{
		if (pos1 % 4 == 1 && pos1 < nb_num - 1 && mega_tab[pos1][0][0] != 0)
		{
			tp_str = malloc(3 * sizeof(char));
			tp_str[0] = mega_tab[pos1][0][0];
			tp_str[1] = mega_tab[pos1 + 1][0][0];
			tp_str[2] = *"\0";
			pos1 ++;
			pos1 ++;
			ft_strfind_main(tp_str, filename);
			write(1, " ", 1);
			free(tp_str);
			if (nb_num - pos1 > 2)
				continue;
		}
		else if (pos1 % 4 == 0 || pos1 == 0)
		{
			if (mega_tab[pos1][0][0] != '0')
			{
				if (mega_tab[pos1][0][0] != 0)
				{
					ft_strfind_main(mega_tab[pos1][0], filename);
					write(1, "-", 1);
				}
				ft_strfind_main(mega_tab[pos1][1], filename);
				if (pos1 < nb_num - 1)
					write(1, " ", 1);
			}
		}
		else if (pos1 % 4 == 3)
		{
			ft_strfind_main(mega_tab[pos1][0], filename);
			if (pos1 < nb_num - 1)
					write(1, " ", 1);
		}
		else
		{
			if (mega_tab[pos1][0][0] != '0' && mega_tab[pos1][0][0] != 0)
			{
				ft_strfind_main(mega_tab[pos1][0], filename);
				if (pos1 < nb_num - 1)
					write(1, " ", 1);
			}
		}
		pos1 ++;
	}
	write(1, "\n", 1);
}

void	*ft_make_input(char *input, char *filename)
{
	char	*correct_input;
	char	***mega_tab;
	int		pos;
	int		len_input;
	int		tp_len;

	pos = 0;
	len_input = ft_strlen(input);
	tp_len = len_input;
	if (len_input % 3 != 0)
		tp_len = (len_input + (3 - (len_input % 3)));
	correct_input = (char *)malloc(tp_len * sizeof(char *));
	correct_input[0] = 0;
	if (ft_strlen(input) % 3 != 0)
	{
		while (pos < (3 - ft_strlen(input) % 3))
		{
			correct_input = ft_strcat(correct_input, "0");
			pos ++;
		}
	}
	correct_input = ft_strcat(correct_input, input);
	mega_tab = ft_separator(correct_input, tp_len);
	ft_cutter_for_printer(mega_tab, tp_len, (tp_len + (tp_len / 3 - 1)), filename);
	pos = 0;
	while (pos < (tp_len + (tp_len / 3 - 1)))
	{
		if ((pos % 4 == 0 || pos == 0))
			free(mega_tab[pos][0]);
		free(mega_tab[pos]);
		pos ++;
	}
	free(mega_tab);
}
