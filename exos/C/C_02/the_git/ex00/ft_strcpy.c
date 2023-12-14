/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:43:50 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/20 15:29:03 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
