/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:13:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:15:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_find_nb_subs(char const *str, char stop);
static int	ft_n_len(char const *s, char c, int index, int chc);
static char	**ft_fill_tab(char	**splitted, char const *s, char c, int nb_subs);
static void	ft_free_tab(char **splitted, int nb_elem);

char	**ft_split(char const *s, char c, int *nb_subs)
{
	char	**splitted;

	if (!s)
		return (NULL);
	*nb_subs = ft_find_nb_subs(s, c);
	splitted = malloc((*nb_subs + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted = ft_fill_tab(splitted, s, c, *nb_subs);
	if (!splitted)
		return (NULL);
	return (splitted);
}

static void	ft_free_tab(char **splitted, int nb_elem)
{
	while (nb_elem >= 0)
	{
		free(splitted[nb_elem]);
		nb_elem --;
	}
	free(splitted);
}

static char	**ft_fill_tab(char	**splitted, char const *s, char c, int nb_subs)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < nb_subs)
	{
		n = ft_n_len(s, c, n, 0);
		splitted[i] = ft_substr(s, n, ft_n_len(s, c, n, 1));
		if (!splitted)
		{
			ft_free_tab(splitted, i);
			return (NULL);
		}
		n = n + ft_n_len(s, c, n, 1);
		i ++;
	}
	splitted[i] = 0;
	return (splitted);
}

static int	ft_n_len(char const *s, char c, int index, int chc)
{
	int	res;

	res = 0;
	if (chc == 0)
	{
		res = index;
		while (s[res] == c && s[res] != 0)
			res ++;
	}
	else
	{
		while (s[index + res] != c && s[index + res] != 0)
			res ++;
	}
	return (res);
}

static int	ft_find_nb_subs(char const *str, char stop)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] != stop && str[i] != 0)
		res ++;
	while (str[i] != 0)
	{
		if (str[i] == stop)
		{
			while (str[i] == stop && str[i] != 0)
				i ++;
			if (str[i] != 0)
				res ++;
		}
		else
			i ++;
	}
	return (res);
}
