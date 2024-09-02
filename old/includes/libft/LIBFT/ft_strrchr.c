/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:17 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:09 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		chr_pos;
	char	*return_str;

	i = 0;
	chr_pos = -1;
	return_str = (char *)s;
	if (c == 0)
		return (&return_str[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			chr_pos = i;
		i++;
	}
	if (chr_pos < 0)
		return (0);
	return (&return_str[chr_pos]);
}
