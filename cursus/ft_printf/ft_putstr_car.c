/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_car.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:25:29 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/10 19:29:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[pos] != 0)
	{
		write(1, &str[pos], 1);
		pos ++;
	}
	return (pos);
}

int	ft_putcar(char car)
{
	write(1, &car, 1);
	return (1);
}
