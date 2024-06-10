/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:40:27 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 15:12:36 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iscontained(char const chr, char const *set);
static int	ft_getstart(char const *s1, char const *set);
static int	ft_getend(char const *s1, char const *set);
static int	ft_max(int a, int b);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*work_str;
	int		size;

	if (!set || !s1)
		return (0);
	size = ft_max(1, ft_getend(s1, set) - ft_getstart(s1, set) + 2);
	if (!*s1)
		size = 1;
	work_str = malloc(sizeof(char) * size);
	if (!work_str)
		return (0);
	if (size == 1)
	{
		work_str[0] = 0;
		return (work_str);
	}
	ft_strlcpy(work_str, (char *)&s1[ft_getstart(s1, set)], size);
	return (work_str);
}

static int	ft_iscontained(char const chr, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_iscontained(s1[i], set))
		i++;
	if ((size_t)i > ft_strlen(s1))
		i = ft_strlen(s1) - 1;
	return (i);
}

static int	ft_getend(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_iscontained(s1[i], set))
		i--;
	if (i < 0)
		i = 0;
	return (i);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
