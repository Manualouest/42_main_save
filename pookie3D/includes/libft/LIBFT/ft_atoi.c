/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:17:36 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/08 19:25:17 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = nptr[i] - '0' + num * 10;
		i++;
	}
	return (num * sign);
}
