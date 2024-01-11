/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:57:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/09/06 17:57:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = 0;
	dest = malloc((1 + ft_strlen(src)) * sizeof(char));
	while (src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*str_stock;
	int			pos;	

	pos = 0;
	str_stock = malloc((ac + 1) * sizeof(*str_stock));
	while (pos < ac)
	{
		str_stock[pos].size = ft_strlen(av[pos]);
		str_stock[pos].str = ft_strcpy(str_stock[pos].str, av[pos]);
		str_stock[pos].copy = ft_strcpy(str_stock[pos].copy, av[pos]);
		pos ++;
	}
	str_stock[pos].size = 0;
	str_stock[pos].str = 0;
	str_stock[pos].copy = 0;
	if (str_stock == NULL)
		return (NULL);
	return (str_stock);
}
