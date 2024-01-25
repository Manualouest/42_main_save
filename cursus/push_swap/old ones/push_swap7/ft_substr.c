/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:17:56 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/12 23:02:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		check_start(char const *s, unsigned int start);
static size_t	malloc_size(size_t max_sub, size_t len);
static size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			max_sub;
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s || check_start(s, start) == 0)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	max_sub = ft_strlen(&s[start]);
	max_sub = malloc_size(max_sub, len);
	sub = malloc((max_sub + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < max_sub)
	{
		sub[i] = s[start + i];
		i ++;
	}
	sub[i] = 0;
	return (sub);
}

static size_t	malloc_size(size_t max_sub, size_t len)
{
	if (max_sub > len)
		return (len);
	else
		return (max_sub);
}

static int	check_start(char const *s, unsigned int start)
{
	if (start > ft_strlen(s))
		return (0);
	return (1);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i ++;
	}
	return (i);
}
