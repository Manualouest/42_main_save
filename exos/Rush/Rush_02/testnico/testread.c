/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:53:43 by nberduck          #+#    #+#             */
/*   Updated: 2023/09/03 06:02:27 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_head(char *str);

int	ft_lenfile(void)
{
	char	a[1000000];
	int		f;
	int		n;

  f	= open("numbers.dict", O_RDONLY);
  n = read(f, a, 1000000);
	close(f);
	return (n);
}

char	*ft_readfile(int n)
{
	char	*file;
	int		f;

	file = malloc((n + 1) * sizeof(char));
	f = open("numbers.dict", O_RDONLY);
	read(f, file, n);
	close(f);
	return (file);
}
/*
char *ft_matrice_creation(char *str)
{
	char	***mat;
	int		i;
	int		j;
	int		nb;
	int		s;

	i = 0;
	nb = 0;
	{
	while(str[i])
		if(str[i] == '\n')
			nb++;
		i++;
	}
	mat = (char ***) malloc(nb * sizeof(char **));
	i = 0;
	while(i < nb)
	{
		mat[i] = (char **)malloc(2 * sizeof(char));
		i++;
	}
	i = 0;
	j = 0;
	nb = 0;
	while(str[i])
	{
		if (str[i] == '\n')
		{
			s = 0;
			while (j <= i)
				mat[nb][v][s++] = str[j++];
			mat[nb][s] = '\0';
			j = i + 1;
		}

}
*/
int	ft_oneline(char *str)
{
	int		i;
	int		j;
	int		s;
	char	*line;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			s = 0;
			line = (char *)malloc((i - j + 2) * sizeof(char));
			while (j <= i)
				line[s++] = str[j++];
			line[s] = '\0';
			j = i + 1;
			//if (is_line_correct(line) != 0)
			//	return (1);
			free(line);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int		n;
	char	*file;

	n = ft_lenfile();
	file = ft_readfile(n);
	file[n] = '\0';
	if(ft_oneline(file) == 0)
	{
		//SPLIT_MATRICE
		ft_head(file);
	}
	else
		write(1,"ERROR",6);
	free(file);
	return (0);
}*/
