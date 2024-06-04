/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/17 15:48:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_ncheck(const char *s, int buflen, int chc)
{
	int	i;

	i = 0;
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
		while (i < buflen - 1 && s[i] != 0)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_join;
	int		pos;
	int		pos2;

	pos2 = 0;
	pos = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (int)(ft_strlen_ncheck(s1, 0, 0) + ft_strlen_ncheck(s2, 0, 0));
	s_join = malloc((len + 1) * sizeof(char));
	if (!s_join)
		return (NULL);
	while (s1[pos] != 0)
	{
		s_join[pos] = s1[pos];
		pos ++;
	}
	while (s2[pos2] != 0)
	{
		s_join[pos + pos2] = s2[pos2];
		pos2 ++;
	}
	s_join[pos + pos2] = 0;
	return (s_join);
}

// void	complete_line(char *file, int fd, size_t BUFFER_SIZE);
// {
	
// }