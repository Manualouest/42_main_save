/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slurp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:44:39 by mscheman          #+#    #+#             */
/*   Updated: 2024/03/27 22:31:33 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*slurp_strjoin(char *src, char *dst);

char	*slurp(int fd)
{
	char	*str;
	int		chrread;
	char	*buff;

	str = NULL;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	chrread = read(fd, buff, BUFFER_SIZE);
	while (chrread == BUFFER_SIZE)
	{
		if (str != NULL)
			str = slurp_strjoin(str, buff);
		else
			str = ft_strdup(buff);
		if (str == NULL)
			return (NULL);
		chrread = read(fd, buff, BUFFER_SIZE);
	}
	buff[chrread] = 0;
	str = slurp_strjoin(str, buff);
	free(buff);
	return (str);
}

static char	*slurp_strjoin(char *src, char *buff)
{
	char	*tmp;

	tmp = malloc((ft_strlen(src) + ft_strlen(buff) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = 0;
	ft_strlcpy(tmp, src, ft_strlen(src) + 1);
	tmp = ft_strncat(tmp, buff, ft_strlen(buff));
	free(src);
	src = tmp;
	return (src);
}
