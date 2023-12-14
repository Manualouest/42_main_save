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

////// for tests
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}

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

	if ((pos % 4 == 2 || pos % 4 == 1) && pos != 0)
	{
		tp_tab = malloc(1 * sizeof(char *));
		tp_tab[0] = malloc (2 * sizeof(char));
		tp_tab[0][0] = input[pos - (pos / 4)];
	}
	if (pos % 4 == 3 && pos != 0)
	{
		tp_tab = malloc((unit_incr + 1) * sizeof(char *));
		tp_tab[0] = "1";
		while (unit_incr > 0)
			tp_tab[unit_incr--] = "0";
	}
	if (pos % 4 == 0 || pos == 0)
	{
		tp_tab = malloc(2 * sizeof(char *));
		tp_tab[0] = malloc (2 * sizeof(char));
		tp_tab[0][0] = input[pos - (pos / 4)];
		tp_tab[1] = "100";
	}
	return (tp_tab);
}

char	***ft_separator(char *input, int len)
{
	char	***mega_inp;
	int		pos;
	int		unit_incr;

	mega_inp = malloc((len + (len / 3 - 1)) * sizeof(char **));
	pos = 0;
	unit_incr = len - 3;
	while (pos < (len + (len / 3)))
	{
		printf("%d, ", pos);
		mega_inp[pos] = (ft_separator2(pos, input, len, unit_incr));
		if (pos % 4 == 1)
		{
			mega_inp[pos][0][1] = *"0";
			printf("%s\n", mega_inp[pos][0]);/////////
		}
		if (pos % 4 == 2) //////////////////////////////////////////////
		{
			printf("%s\n", mega_inp[pos][0]);
		}///////////////////////////////////////////////////////////////
		if (pos % 4 == 3 && pos != 0)
			unit_incr = unit_incr - 3;
		pos ++;
	}
	/////////////////////////////////////////////////////////////////////
	pos = 0;
	printf("%d, %d", (len + (len / 3 - 1)), len);
	while (pos < (len + (len / 3 - 1)))
	{
		if ((pos % 4 == 0 || pos == 0))
			free(mega_inp[pos][0]);
		free(mega_inp[pos]);
		pos ++;
	}
	free(mega_inp);
	free(input); /////////////////////////////////////////////////////////
}

void	ft_cutter_for_printer(char ***mega_tab, int nb_num, int len_mt)
{
	int	pos1;
	int	pos2;

	pos1 = 0;
	pos2 = 0;
	while (pos1 < len_mt)
	{
		if (pos1 % 4 == 0 || pos1 == 0)
		{
			//ft_strfind_main(mega_tab[pos1][0][0]);
			//ft_strfind_main(mega_tab[pos1][0][1]);
			pos2 ++;
		}
		else
		{
			//ft_strfind_main(mega_tab[pos1][0]);
			pos2 ++;
		}
		pos1 ++;
	}
}

void	*ft_make_input(char *input)
{
	char	*correct_input;
	char	***mega_tab;
	int		pos;
	int		len_input;
	int		tp_len;

	pos = 0;
	len_input = ft_strlen(input);
	tp_len = (len_input + (len_input % 3)) + 1;
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
	tp_len = ft_strlen(correct_input);
	correct_input = ft_strcat(correct_input, input);
	printf(":%s\n", correct_input);
	mega_tab = ft_separator(correct_input, tp_len);
	//ft_cutter_for_printer(mega_tab, tp_len, (tp_len + (tp_len / 3 - 1)));
}

int	main(int c, char **a)
{
	if (c == 2)
		ft_make_input(a[1]);
	else
		printf("met un parametre orh\n");
}
