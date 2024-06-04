/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:23:19 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 15:13:20 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int strlen, int n);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*work_str;

	i = start;
	j = 0;
	if (!s || start > ft_strlen(s))
	{
		work_str = malloc(sizeof(char));
		if (!work_str)
			return (0);
		work_str[0] = 0;
		return (work_str);
	}
	size = ft_min(ft_strlen(&s[start]), len);
	work_str = malloc(sizeof(char) * size + 1);
	if (!work_str)
		return (0);
	while (size > j)
		work_str[j++] = s[i++];
	work_str[j] = 0;
	return (work_str);
}

static int	ft_min(int strlen, int n)
{
	if (strlen > n)
		return (n);
	return (strlen);
}
