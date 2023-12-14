/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:42:06 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/06 17:54:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcat_v2(char *dest, char *s1, char *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_join;

	if (!s1 || !s2)
		return (NULL);
	len = (int)(ft_strlen(s1) + ft_strlen(s2));
	s_join = malloc((len + 1) * sizeof(char));
	if (!s_join)
		return (NULL);
	s_join = ft_strcat_v2(s_join, (char *)s1, (char *)s2);
	return (s_join);
}

static char	*ft_strcat_v2(char *dest, char *s1, char *s2)
{
	int	pos;
	int	pos2;

	pos2 = 0;
	pos = 0;
	while (s1[pos] != 0)
	{
		dest[pos] = s1[pos];
		pos ++;
	}
	while (s2[pos2] != 0)
	{
		dest[pos + pos2] = s2[pos2];
		pos2 ++;
	}
	dest[pos + pos2] = 0;
	return (dest);
}
