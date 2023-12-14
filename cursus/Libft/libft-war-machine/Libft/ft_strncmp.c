/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:26:54 by Manualouest       #+#    #+#             */
/*   Updated: 2023/10/31 15:34:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (n < 1)
		return (0);
	while (pos < n - 1 && s1[pos] != 0 && s2[pos] != 0)
	{
		if (s1[pos] != s2[pos])
			return (s1[pos] - s2[pos]);
		pos++;
	}
	if (s1[pos] == 0)
		return (-1);
	if (s2[pos] == 0)
		return (1);
	return (s1[pos] - s2[pos]);
}
