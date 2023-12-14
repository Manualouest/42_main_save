/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:01 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:39 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (s[i] != 0)
	{
		i ++;
	}
	while (i > 0)
	{
		if (s[i] == c)
			return (&res[i]);
		i --;
	}
	return (NULL);
}
