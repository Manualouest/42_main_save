/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			res = (char *)s;
			return (&res[i]);
		}
		i ++;
	}
	if (s[i] == (char)c)
	{
		res = (char *)s;
		return (&res[i]);
	}
	return (NULL);
}
