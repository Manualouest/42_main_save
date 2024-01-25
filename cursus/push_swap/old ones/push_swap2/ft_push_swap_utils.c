/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:04:25 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/29 14:22:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	skip_spaces(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = skip_spaces(nptr);
	sign = 1;
	num = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i ++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	return (num * sign);
}

static int	skip_spaces(const char *nptr)
{
	int	i;

	i = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		&& nptr[i] != 0)
	{
		i ++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	unsigned int	temp;
	char			num;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
	{
		ft_putnbr(temp / 10);
	}
	num = temp % 10 + '0';
	write(1, &num, 1);
}