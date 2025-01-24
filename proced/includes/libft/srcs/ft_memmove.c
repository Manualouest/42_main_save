/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:14:05 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*desttmp;
	char	*srctmp;
	char	*tmp;

	desttmp = (char *)dest;
	srctmp = (char *)src;
	tmp = srctmp;
	i = 0;
	j = n - 1;
	if (dest > src)
	{
		while (i < n)
		{
			desttmp[j] = tmp[j];
			i++;
			j--;
		}
	}
	else
		desttmp = ft_memcpy(dest, src, n);
	return (dest);
}
