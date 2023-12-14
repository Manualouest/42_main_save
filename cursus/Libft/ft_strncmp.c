/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:26:54 by Manualouest       #+#    #+#             */
/*   Updated: 2023/11/06 17:51:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (n < 1)
		return (0);
	while (pos < n - 1 && (unsigned char)s1[pos] != 0
		&& (unsigned char)s2[pos] != 0)
	{
		if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
		pos++;
	}
	if ((unsigned char)s1[pos] == 0 && (unsigned char)s2[pos] != 0)
		return (-1);
	if ((unsigned char)s2[pos] == 0 && (unsigned char)s1[pos] != 0)
		return (1);
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
