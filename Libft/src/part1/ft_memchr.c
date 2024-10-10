/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:44:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:43:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return (NULL);
	while (++i < n && ((unsigned char *)s)[i] != (unsigned char)c)
		;
	if (i == n || ((unsigned char *)s)[i] != (unsigned char)c)
		return (NULL);
	return (&((unsigned char *)s)[i]);
}
