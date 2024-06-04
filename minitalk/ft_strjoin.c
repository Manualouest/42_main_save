/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:42:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/20 20:58:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char		*ft_strcat_v2(char *dest, char *s1, char s2);

char	*ft_strjoin(char *s1, char s2)
{
	int		len;
	char	*s_join;

	if (!s1 || !s2)
		return (NULL);
	len = (int)(ft_strlen(s1) + 1);
	s_join = malloc((len + 1) * sizeof(char));
	if (!s_join)
		return (NULL);
	s_join = ft_strcat_v2(s_join, s1, s2);
	if (s1)
		free(s1);
	return (s_join);
}

static char	*ft_strcat_v2(char *dest, char *s1, char s2)
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
	dest[pos + pos2] = s2;
	dest[pos + pos2 + 1] = 0;
	return (dest);
}
