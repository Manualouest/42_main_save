/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:01:14 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/10 18:55:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	unsigned int	total;
	unsigned int	temp;
	char			num;

	total = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
		total ++;
	}
	else
		temp = n;
	if (temp > 9)
	{
		total += ft_putuint(temp / 10);
	}
	num = temp % 10 + '0';
	write(1, &num, 1);
	total ++;
	return (total);
}

int	ft_putuint(unsigned int n)
{
	int		total;
	char	num;

	total = 0;
	if (n > 9)
	{
		total += ft_putuint(n / 10);
	}
	num = n % 10 + '0';
	write(1, &num, 1);
	total ++;
	return (total);
}
