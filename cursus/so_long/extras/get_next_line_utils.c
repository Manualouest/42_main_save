/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/31 14:47:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

int	gnl_len_str_n(const char *s, int buflen, int chc)
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

char	*gnl_get_until_n(char *str, int free_chc)
{
	char	*new_str;
	int		nlen;
	int		i;

	i = 0;
	nlen = gnl_len_str_n(str, BUFFER_SIZE, 1);
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

char	*gnl_strlcat(char *dest, char *src, int free_chc)
{
	int		i;
	int		len;
	char	*tp;

	i = 0;
	len = gnl_len_str_n(dest, 0, 0) + gnl_len_str_n(src, 0, 0);
	tp = (char *)gnl_calloc(len, 1);
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

void	*gnl_calloc(size_t nmemb, size_t size)
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

char	*gnl_free_readd(char *str, char *new_str)
{
	free(str);
	return (new_str);
}
