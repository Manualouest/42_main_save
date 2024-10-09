/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:17:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		check_start(char const *s, unsigned int start);
static size_t	malloc_size(size_t max_sub, size_t len);

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
