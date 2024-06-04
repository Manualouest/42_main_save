/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:22:40 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/13 15:38:31 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long long nbr, char *base);

int	ft_putvoid(unsigned long long num)
{
	int	len;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_putnbr_base(num, "0123456789abcdef");
	return (len + 2);
}

static int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int				total;
	char			nb;

	total = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		total += ft_putnbr_base((nbr / 16) * -1, base);
		nb = base[(nbr % 16) * -1];
		write (1, &nb, 1);
	}
	else if (nbr < 16)
	{
		nb = base[nbr];
		write (1, &nb, 1);
	}
	else if (nbr >= 16)
	{
		total += ft_putnbr_base(nbr / 16, base);
		nb = base[nbr % 16];
		write (1, &nb, 1);
	}
	total ++;
	return (total);
}
