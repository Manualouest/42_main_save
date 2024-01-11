/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:44:12 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/28 17:44:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*a;
	int		pos;

	pos = 0;
	while (src[pos] != 0)
	{
		pos ++;
	}
	a = malloc((pos + 1) * sizeof (char));
	pos = 0;
	while (src[pos] != 0)
	{
		a[pos] = src[pos];
		pos ++;
	}
	a[pos] = 0;
	return (a);
}
