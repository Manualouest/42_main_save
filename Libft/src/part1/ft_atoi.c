/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:42:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = -1;
	while (nptr[++i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		;
	i --;
	sign = 0;
	num = 0;
	if (nptr[++i] && (nptr[i] == '-' || nptr[i] == '+'))
		sign = 1 - (2 * (nptr[i] == '-'));
	i -= (sign == 0);
	while (nptr[++i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		num = num * 10 + (nptr[i] - '0');
	return (num * (sign + (sign == 0)));
}
