/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:22:35 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*desttmp;
	unsigned char	*srctmp;

	desttmp = (unsigned char *)dest;
	srctmp = (unsigned char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < num)
	{
		desttmp[i] = srctmp[i];
		i++;
	}
	return (dest);
}
