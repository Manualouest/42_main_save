/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:47:31 by nberduck          #+#    #+#             */
/*   Updated: 2023/09/03 17:27:53 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_lenfile(char *filename);
char	*ft_readfile(int n, char *filename);
char	**ft_tabint_creation(char **tabint, int nb, char *str);
char	**ft_tabstr_creation(char **tabstr, int nb, char *str);

int	ft_strfind(char **str, char *to_find, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		j = 0;
		while (str[i][j] == to_find[j])
		{
			if (to_find[j] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_write(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_strfind_main(char *to_find, char *filename)
{
	int		n;
	int		i;
	char	*file;
	char	**tabint;
	char	**tabstr;

	n = ft_lenfile(filename);
	file = ft_readfile(n,filename);
	file[n] = '\0';
	i = 0;
	n = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			n++;
		i++;
	}
	tabint = NULL;
	tabstr = NULL;
	tabint = ft_tabint_creation(tabint, n, file);
	tabstr = ft_tabstr_creation(tabstr, n, file);
	if (ft_strfind(tabint, to_find, n) != -1)
		ft_write(tabstr[ft_strfind(tabint, to_find, n)]);
	else
		write(1, "Dict Error\n", 11);
	free(file);
	i = 0;
	while (i < n)
	{
		free(tabint[i]);
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
	free(tabint);
}
