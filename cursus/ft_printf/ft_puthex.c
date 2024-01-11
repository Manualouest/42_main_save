/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:02:02 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/10 19:12:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned int nbr, char *base);

int	ft_puthex(unsigned int num, char kind)
{
	int	len;

	if (kind == "l"[0])
		len = ft_putnbr_base(num, "0123456789abcdef");
	else
		len = ft_putnbr_base(num, "0123456789ABCDEF");
	return (len);
}

static int	ft_putnbr_base(unsigned int nbr, char *base)
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
