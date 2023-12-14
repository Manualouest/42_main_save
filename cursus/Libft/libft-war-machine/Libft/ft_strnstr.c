/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:54:40 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 16:02:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_strlen(char *str);

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
	while (i < len && big[i] != 0)
	{
		if (big[i] == little[n])
			n ++;
		else
			n = 0;
		if (little[n] == 0)
		{
			if (i < n)
				return ((char *)big);
			return (&((char *)big)[i - n + 1]);
		}
		i ++;
	}
	return (NULL);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}
