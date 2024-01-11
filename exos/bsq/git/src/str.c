/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:07:50 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/05 17:10:55 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = 0;
	while (src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}
