/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:18:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:44:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = -1;
	while (src[++len])
		;
	i = -1;
	if (size <= 0)
		return (len);
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = 0;
	return (len);
}
