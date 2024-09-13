/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:46 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:21 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*return_mem;

	i = 0;
	return_mem = (char *)s;
	if ((char)c == 0 && n > ft_strlen(s))
		return (&return_mem[ft_strlen(s)]);
	while (n > i)
	{
		if (((char *)s)[i] == (char)c)
			return (&return_mem[i]);
		i++;
	}
	return (0);
}
