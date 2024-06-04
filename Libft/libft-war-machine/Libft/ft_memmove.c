/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:36:29 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = 0;
	while (i < n)
	{
		temp[i] = ((char *)src)[i];
		i ++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = temp[i];
		i ++;
	}
	return (dest);
}
