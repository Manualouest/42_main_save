/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:23 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/06 17:54:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	int		i;
	char	*s_dup;

	s_len = ft_strlen((char *)s);
	i = 0;
	s_dup = malloc((s_len + 1) * sizeof(char));
	if (!s_dup)
		return (0);
	while (s[i] != 0)
	{
		s_dup[i] = s[i];
		i ++;
	}
	s_dup[i] = s[i];
	return (s_dup);
}
