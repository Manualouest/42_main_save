/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:10:25 by nberduck          #+#    #+#             */
/*   Updated: 2023/09/03 14:27:19 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_number_selector(char *tab, char *str, int s, int e)
{
	int	i;

	tab = malloc((e - s -5) * sizeof(char *));
	i = 0;
	while (s <= e)
	{
		if (str[s] == ' ' || str[s] == ':')
			break ;
		tab[i] = str[s];
		i++;
		s++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_tabint_creation(char **tabint, int nb, char *str)
{
	int	i;
	int	s;
	int	n;

	tabint = malloc((nb) * sizeof(char *));
	i = 0;
	s = 0;
	n = -1;
	while (str[i])
	{
		if ((str[i] == '\n' || str[i] == '\0') && i != s)
		{
			n++;
			tabint[n] = ft_number_selector(tabint[n], str, s, i);
			s = i + 1;
		}
		i++;
	}
	return (tabint);
}

char	*ft_str_selector(char *tab, char *str, int s, int e)
{
	int	i;
	int	j;

	tab = malloc((e - s + 2) * sizeof(char *));
	i = 0;
	j = 0;
	while (s <= e)
	{
		if (str[s] == ':')
		{
			j = 1;
			s++;
			while (str[s] == ' ')
				s++;
		}
		if (str[s] == '\n')
			break ;
		if (j == 1)
			tab[i++] = str[s];
		s++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_tabstr_creation(char **tabstr, int nb, char *str)
{
	int	i;
	int	s;
	int	n;

	tabstr = malloc((nb) * sizeof(char *));
	i = 0;
	s = 0;
	n = -1;
	while (str[i])
	{
		if (str[i] == '\n' && i != s)
		{
			n++;
			tabstr[n] = ft_str_selector(tabstr[n], str, s, i);
			s = i + 1;
		}
		i++;
	}
	return (tabstr);
}
