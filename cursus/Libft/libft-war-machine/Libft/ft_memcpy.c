/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:29:27 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)dest)[i] != 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i ++;
	}
	return (&memcpy);
}
