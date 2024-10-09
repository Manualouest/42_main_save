/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (n == 0)
		return (0);
	while (pos < n - 1)
	{
		if (((unsigned char *)s1)[pos] != ((unsigned char *)s2)[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos++;
	}
	if (((unsigned char *)s1)[pos] == 0 && ((unsigned char *)s2)[pos] != 0)
		return (-1);
	if (((unsigned char *)s2)[pos] == 0 && ((unsigned char *)s1)[pos] != 0)
		return (1);
	return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
}
