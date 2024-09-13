/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:56 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/13 14:28:34 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n)
		return (0);
	if (src > dest)
	{
		dest = ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n > 0)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}
