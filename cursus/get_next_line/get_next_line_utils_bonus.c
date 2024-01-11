/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:37:45 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/19 19:55:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len_str_n(const char *s, int buflen, int chc)
{
	int	i;

	i = 0;
	if (!s)
		return (chc * -1);
	if (chc == 0)
	{
		while (s[i] != 0)
		{
			i ++;
		}
		return (i);
	}
	else
	{
		while (s[i] != 0)
		{
			if (s[i] == '\n')
				return (i);
			i ++;
		}
		if (s[i] == '\n' || (buflen < BUFFER_SIZE && s[i] == 0))
			return (i);
		return (-1);
	}
}

char	*ft_get_until_n(char *str, int free_chc)
{
	char	*new_str;
	int		nlen;
	int		i;

	i = 0;
	nlen = ft_len_str_n(str, BUFFER_SIZE, 1);
	if (!nlen)
		return (NULL);
	if (nlen == -1)
		return (str);
	new_str = malloc(nlen + 2);
	while (i < nlen)
	{
		new_str[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i ++;
	}
	new_str[i] = 0;
	if (free_chc == 1)
		free(str);
	return (new_str);
}

char	*ft_strlcat(char *dest, char *src, int free_chc)
{
	int		i;
	int		len;
	char	*tp;

	i = 0;
	len = ft_len_str_n(dest, 0, 0) + ft_len_str_n(src, 0, 0);
	tp = (char *)ft_calloc(len, 1);
	if (!tp)
		return (NULL);
	len = 0;
	while (dest && dest[i] != 0)
	{
		tp[i] = dest[i];
		i ++;
	}
	while (src && src[len] != 0)
	{
		tp[i] = src[len];
		i++;
		len ++;
	}
	if (dest && free_chc == 1)
		free(dest);
	return (tp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		array = malloc(1);
		((char *)array)[0] = 0;
		if (!array)
			return (NULL);
		return (array);
	}
	if ((nmemb >= 2147483647 || size >= 2147483647
			|| (nmemb * size > 2147483647)))
		return (0);
	array = malloc((size * nmemb) + 1);
	((char *)array)[size * nmemb] = 0;
	if (!array)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)array)[i] = 0;
		i ++;
	}
	return (array);
}

char	*redo(char *str, char *new_str)
{
	free(str);
	return (new_str);
}
