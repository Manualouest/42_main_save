/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:26 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 15:16:49 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < size - 1 && src[i])
	{
		if (src_len == 0)
			break ;
		if (size < 1)
			break ;
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = 0;
	return (src_len);
}
