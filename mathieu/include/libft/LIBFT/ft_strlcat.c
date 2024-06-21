/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:47:52 by mscheman          #+#    #+#             */
/*   Updated: 2024/01/29 15:47:52 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:23 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:13 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	final_len;

	if ((!dst || !src) && size == 0)
		return (0);
	if (size < ft_strlen(dst) + 1)
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && size > i + 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	final_len = ft_strlen(dst) + ft_strlen(&src[j]);
	return (final_len);
}
