/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:12 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:10 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	if (len == 0 || !*big)
		return (NULL);
	while (big[i] && len > i)
	{
		j = 0;
		while (little[j] && len > i)
		{
			if (big[i] != little[j])
				break ;
			i++;
			j++;
			if (j == ft_strlen(little))
				return ((char *)&big[i - j]);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
