/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:54:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:44:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;

	if (!little[0])
		return ((char *)big);
	i = -1;
	while (++i < len && big[i])
	{
		ii = -1;
		while (++ii + i < len && little[ii] && little[ii] == big[i + ii])
			;
		if (!little[ii])
			return (&((char *)big)[i]);
	}
	return (NULL);
}
