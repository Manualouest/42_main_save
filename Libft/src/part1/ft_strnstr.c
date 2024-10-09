/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:54:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strnstr_rtn(const char *s, int i, int n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;
	int		lit_len;

	i = 0;
	n = 0;
	lit_len = ft_strlen((char *)little);
	if (lit_len == 0)
		return ((char *)big);
	while (i != len && big[i] != 0)
	{
		if (big[i] == little[n])
			n ++;
		else
		{
			i = i - n;
			n = 0;
		}
		if (little[n] == 0)
			return (ft_strnstr_rtn(big, i, n));
		i ++;
	}
	return (NULL);
}

static char	*ft_strnstr_rtn(const char *s, int i, int n)
{
	if (i < n)
		return ((char *)s);
	return (&((char *)s)[i - n + 1]);
}
