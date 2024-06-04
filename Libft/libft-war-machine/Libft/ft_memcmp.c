/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:30 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (n == 0)
		return (0);
	while (pos < n - 1 && ((char *)s1)[pos] != 0
		&& ((char *)s2)[pos] != 0)
	{
		if (((char *)s1)[pos] != ((char *)s2)[pos])
			return (((char *)s1)[pos] - ((char *)s2)[pos]);
		pos++;
	}
	if (((char *)s1)[pos] == 0)
		return (-1);
	if (((char *)s2)[pos] == 0)
		return (1);
	return (((char *)s1)[pos] - ((char *)s2)[pos]);
}
