/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:36:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:46:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	if (dest < src)
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	else
	{
		n ++;
		while (--n > 0)
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
	}
	return (dest);
}
