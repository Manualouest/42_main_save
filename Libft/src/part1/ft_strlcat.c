/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:25:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	index;

	len_dst = 0;
	len_src = ft_strlen((char *)src);
	index = 0;
	if (size == 0)
		return (len_src);
	while (dst[len_dst] != 0 && len_dst < size)
		len_dst ++;
	while (src[index] != 0 && len_dst + index < size - 1)
	{
		dst[len_dst + index] = src[index];
		index ++;
	}
	if (len_dst + index > size - 1)
		return (len_dst + len_src);
	if (len_dst + len_src > size)
	{
		dst[len_dst + index] = 0;
		return (len_dst + len_src);
	}
	dst[len_dst + len_src] = 0;
	return (len_dst + len_src);
}
