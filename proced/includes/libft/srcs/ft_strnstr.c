/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:13:30 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	tfl;
	int		save;

	i = 0;
	c = 0;
	tfl = ft_strlen(little);
	if (tfl == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[c])
			save = i;
		while ((little[c] == big[i + c]) && (little[c]) && (big[i]) && ((i
					+ c) < len))
			c++;
		if (tfl == c)
			return ((char *)big + save);
		c = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	c;
	size_t	tfl;
	int		save;

	i = 0;
	c = 0;
	tfl = ft_strlen(little);
	if (tfl == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[c])
			save = i;
		while ((little[c] == big[i + c]) && (little[c]) && (big[i]))
			c++;
		if (tfl == c)
			return ((char *)big + save);
		c = 0;
		i++;
	}
	return (NULL);
}
