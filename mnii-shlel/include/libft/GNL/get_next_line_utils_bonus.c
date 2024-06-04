/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:32:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/03/24 15:09:06 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < n && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dlen;

	dlen = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != 0)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = 0;
	return (dest);
}

char	*ft_recalloc(char *src, size_t bytes, int iscalloc)
{
	char	*tmp;

	tmp = NULL;
	if (iscalloc == 1)
		src = NULL;
	if (!src || iscalloc == 1)
	{
		src = malloc(sizeof(char) * (bytes + 1));
		ft_bzero(src, bytes);
		return (src);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strncpy(tmp, src, ft_strlen(src) + 1);
	free(src);
	src = malloc(sizeof(char) * (ft_strlen(tmp) + bytes + 1));
	ft_bzero(src, ft_strlen(tmp) + bytes + 1);
	ft_strncpy(src, tmp, ft_strlen(tmp));
	free(tmp);
	return (src);
}

void	ft_freegnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}
