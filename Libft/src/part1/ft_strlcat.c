/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:25:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:44:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_i;
	size_t	dst_i;

	src_i = -1;
	dst_i = -1;
	if (size == 0)
		return (0);
	while (dst[++dst_i] && dst_i < size)
		;
	while (src[++src_i] && dst_i + src_i < size - 1)
		dst[dst_i + src_i] = src[src_i];
	if (src_i > 0)
		dst[dst_i + src_i] = 0;
	src_i --;
	while (src[++src_i])
		;
	return (dst_i + src_i);
}
