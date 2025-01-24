/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:36:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1tmp;
	unsigned char	*s2tmp;
	size_t			i;

	i = 0;
	s1tmp = (unsigned char *)s1;
	s2tmp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1tmp[i] != s2tmp[i])
		{
			return (s1tmp[i] - s2tmp[i]);
		}
		i++;
	}
	return (0);
}
