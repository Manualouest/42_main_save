/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/09 19:34:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

long int	ps_atoi(const char *num)
{
	long int	i;
	long int	sign;
	long int	res;

	i = -1;
	while (num[++i])
		if (num[i] < '0' || num[i] > '9')
			return (-1);
	i = 0;
	sign = 1;
	if (num[i] == '-')
		sign = sign * -1;
	if (num[i] == '+' || num[i] == '-')
		i++;
	res = 0;
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = num[i] - '0' + res * 10;
		i++;
	}
	return (res * sign);
}

void	ps_putnbr(long int n)
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
		ps_putnbr(temp / 10);
	num = temp % 10 + '0';
	write(1, &num, 1);
}
