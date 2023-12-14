/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:29:27 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/06 17:52:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((int *)dest) == NULL && ((int *)src) == NULL)
		{
			i = n;
			break ;
		}
		((char *)dest)[i] = ((char *)src)[i];
		i ++;
	}
	return (dest);
}
