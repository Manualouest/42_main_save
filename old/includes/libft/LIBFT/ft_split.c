/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:34:35 by mscheman          #+#    #+#             */
/*   Updated: 2024/03/27 22:53:54 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:45:24 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 15:19:17 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c);
static int	ft_getwordlen(char const *s, char c, int index);
static int	ft_getnextindex(char const *s, char c, int index);
static void	ft_addwords(char **tab, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (0);
	ft_addwords(tab, s, c);
	return (tab);
}

static int	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	found_num;

	i = 0;
	found_num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		while (s[i] != c && s[i])
			i++;
		found_num++;
	}
	return (found_num);
}

static int	ft_getwordlen(char const *s, char c, int index)
{
	int	i;

	i = index;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i - index);
}

static int	ft_getnextindex(char const *s, char c, int index)
{
	while (s[index] == c && s[index])
		index++;
	return (index);
}

static void	ft_addwords(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = ft_getnextindex(s, c, 0);
	while (ft_countword(s, c) > j && s[i])
	{
		tab[j] = malloc(sizeof(char) * ft_getwordlen(s, c, i) + 1);
		if (!tab[j])
		{
			while (j >= 0)
				free(tab[j--]);
			free(tab);
			return ;
		}
		ft_strlcpy(tab[j++], (char *)&s[i], ft_getwordlen(s, c, i) + 1);
		i = ft_getnextindex(s, c, ft_getwordlen(s, c, i) + i);
	}
	tab[j] = 0;
}
