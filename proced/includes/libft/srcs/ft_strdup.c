/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:17:33 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	char	*buff;
	int		i;
	int		s_size;

	i = 0;
	s_size = ft_strlen(s);
	buff = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!buff)
		return (NULL);
	while (i < s_size)
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = 0;
	return (buff);
}
