/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitary2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:32:23 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/06 13:32:25 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_itostr(int nb)
{
	char	*num_str;
	int		nb_stock;
	int		nb_len;

	nb_len = 0;
	nb_stock = nb;
	while (nb >= 1)
	{
		nb_len++;
		nb = nb / 10;
	}
	num_str = malloc((nb_len + 1) * sizeof(char));
	num_str[nb_len] = 0;
	while (nb_len > 0)
	{
		num_str[nb_len - 1] = nb_stock % 10 + '0';
		nb_stock = nb_stock / 10;
		nb_len --;
	}
	return (num_str);
}
