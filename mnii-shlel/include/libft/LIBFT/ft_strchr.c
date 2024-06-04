/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:10 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:16 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*return_str;

	i = 0;
	return_str = (char *)s;
	if (c == 0)
		return (&return_str[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&return_str[i]);
		i++;
	}
	return (0);
}
