/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:32:25 by mscheman          #+#    #+#             */
/*   Updated: 2024/02/07 15:16:16 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctn(char *str, char *find)
{
	int	x;
	int	y;

	if (!str || !find)
		return (NULL);
	x = 0;
	while (str[x])
	{
		y = 0;
		while (find[y] == str[x])
		{
			if (find[y] == 0)
				return (&str[x - y]);
			y++;
			x++;
		}
		if (find[y] == 0)
			return (&str[x - y]);
		x++;
	}
	return (NULL);
}
