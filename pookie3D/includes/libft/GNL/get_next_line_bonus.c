/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:32:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/09/12 11:11:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		findnl(char *buffer);
char	*gnl_checkstr(char **str, char *buff, int chrread);
char	*gnl_processstr(char **str, char *buff, int chrread);
char	*gnl_extractline(char **str, char *buff, int chrread, int length);

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*tmp;
	int			chrread;
	int			length;
	char		*buff;

	if (fd < 0 || fd > 1024)
		return (NULL);
	length = 1 + ft_strlen(str[fd]);
	buff = NULL;
	buff = ft_recalloc(buff, BUFFER_SIZE + 1, 1);
	chrread = read(fd, buff, BUFFER_SIZE);
	tmp = gnl_checkstr(&str[fd], buff, chrread);
	if ((tmp) || (!tmp && chrread <= 0))
		return (tmp);
	while (chrread > BUFFER_SIZE - 1 && findnl(buff) == -1)
	{
		length += chrread;
		str[fd] = ft_recalloc(str[fd], (chrread + 1), 0);
		ft_strncat(str[fd], buff, chrread);
		chrread = read(fd, buff, BUFFER_SIZE);
	}
	tmp = gnl_extractline(&str[fd], buff, chrread, length);
	free(buff);
	return (tmp);
}

/**
 * @brief Check if the static string contains a new line.
If found selects the substring and puts it in tmp, and the other in str.
 * 
 * @param str Pointer to a static string
 * @param buff Characters read
 * @param chrread Number of characters read
 * @return NULL or a string
 */
char	*gnl_checkstr(char **str, char *buff, int chrread)
{
	char	*tmp;
	int		strlen;

	tmp = NULL;
	strlen = 0;
	if (findnl(*str) != -1)
	{
		tmp = ft_recalloc(tmp, (ft_strlen(*str) + 1), 1);
		ft_strncpy(tmp, *str, ft_strlen(*str));
		if (chrread == 0)
			chrread = 2 * findnl(tmp);
		*str = ft_recalloc(*str, (chrread - findnl(tmp) + 1), 0);
		strlen = ft_strlen(tmp) - findnl(tmp) + 1;
		ft_strncpy(*str, &tmp[findnl(tmp) + 1], strlen);
		ft_strncat(*str, buff, chrread);
		tmp[findnl(tmp) + 1] = 0;
		free(buff);
	}
	if (!tmp)
		tmp = gnl_processstr(str, buff, chrread);
	return (tmp);
}

/**
 * @brief In the continuity of 'Check Static'.
Copy str into tmp if no new line has been found in set str.
Else if only no chararacters has been read, simply free str and buff.
 * @param str Pointer to a static string
 * @param buff Characters read
 * @param chrread Number of characters read
 * @return Either a copy of str (with new a adress) or NULL.
 */
char	*gnl_processstr(char **str, char *buff, int chrread)
{
	char	*tmp;

	tmp = NULL;
	if (*str && **str && findnl(*str) == -1 && chrread <= 0)
	{
		tmp = ft_recalloc(tmp, (ft_strlen(*str) + 1), 1);
		ft_strncpy(tmp, *str, ft_strlen(*str));
		free(*str);
		free(buff);
		*str = NULL;
	}
	else if (chrread <= 0)
	{
		if (*str)
			free(*str);
		free(buff);
	}
	return (tmp);
}

/**
 * @brief	If gnl stopped reading perfectly at a new line, simply return
a copy of str. Else, exctract the substring containing the \\n into tmp
and saves the other part of the buffer into str.
 * 
 * @param str Pointer to a static string
 * @param buff Characters read
 * @param chrread Number of characters read
 * @param length Length of the static string
 * @return Returns a string terminated by a \\n (and '\0')
 */
char	*gnl_extractline(char **str, char *buff, int chrread, int length)
{
	char	*tmp;

	buff[chrread] = 0;
	tmp = NULL;
	if (length == ft_strlen(*str))
		free(*str);
	if (findnl(buff) != -1)
	{
		*str = ft_recalloc(*str, (chrread + 1), 0);
		tmp = ft_recalloc(tmp, (length + chrread + 1), 1);
		ft_strncpy(tmp, *str, ft_strlen(*str));
		ft_strncat(tmp, buff, findnl(buff) + 1);
		ft_strncpy(*str, &buff[findnl(buff) + 1], chrread - findnl(buff));
		if (findnl(tmp) == -1)
		{
			tmp = ft_recalloc(tmp, 2, 0);
			ft_strncat(tmp, "\n", 2);
		}
		return (tmp);
	}
	*str = ft_recalloc(*str, (chrread + 1), 0);
	ft_strncat(*str, buff, chrread);
	tmp = *str;
	*str = NULL;
	return (tmp);
}

/**
 *	@brief	Return the position of \\n in a string
 *
 *	@param	string	The string to check
 *	@return	Either the position of the \\n or -1 if not found
*/
int	findnl(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (-1);
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
