/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/17 18:55:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_ncheck(const char *s, int buflen, int chc)
{
	int	i;
 
	i = 0;
	if (!s)
		return (i);
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