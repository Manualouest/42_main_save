/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:28:10 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/29 09:28:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_all(char **strs, int size, char *sep)
{
	int	tt;
	int	pos;
	int	pos2;
	int	tt_sep;

	tt = 0;
	pos = 0;
	tt_sep = 0;
	while (sep[tt_sep] != 0)
		tt_sep ++;
	while (pos < size)
	{
		pos2 = 0;
		while (strs[pos][pos2] != 0)
		{
			tt ++;
			pos2 ++;
		}
		tt = tt + tt_sep;
		pos ++;
	}
	tt = tt - tt_sep;
	return (tt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	pos;
	int	pos2;

	pos2 = 0;
	pos = 0;
	while (dest[pos] != 0)
	{
		pos ++;
	}
	while (src[pos2] != 0)
	{
		dest[pos] = src[pos2];
		pos ++;
		pos2 ++;
	}
	dest[pos] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*a;
	int		pos;

	pos = 0;
	a = malloc((ft_size_all(strs, size, sep) + 1) * sizeof(char));
	if (size == 0)
	{
		a[0] = 0;
		return (a);
	}
	a[0] = 0;
	while (pos < size)
	{
		a = ft_strcat(a, strs[pos]);
		if (pos < size - 1)
			a = ft_strcat(a, sep);
		pos ++;
	}
	a = ft_strcat(a, "\0");
	return (a);
}
