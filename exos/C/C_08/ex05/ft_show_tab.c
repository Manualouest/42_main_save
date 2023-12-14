/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:57:12 by mbirou            #+#    #+#             */
/*   Updated: 2023/09/06 17:57:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int nb)
{
	int	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	if (nb < 10 && nb > -10)
	{
		nb = nb + '0';
		if (nb - '0' < 0)
			nb = ((nb - '0') * -1) + '0';
		write(1, &nb, 1);
	}
	else
	{
		if (nb % 10 < 0)
			temp = (nb % 10) * -1 + '0';
		else
			temp = nb % 10 + '0';
		if (nb < 0)
			ft_putnbr((nb / 10) * -1);
		else
			ft_putnbr(nb / 10);
		write(1, &temp, 1);
	}
}

void	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != 0)
	{
		write(1, &str[pos], 1);
		pos ++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	pos;

	pos = 0;
	while (par[pos].str != 0)
	{
		ft_putstr(par[pos].str);
		write(1, "\n", 1);
		ft_putnbr(par[pos].size);
		write(1, "\n", 1);
		ft_putstr(par[pos].copy);
		write(1, "\n", 1);
		pos ++;
	}
}
