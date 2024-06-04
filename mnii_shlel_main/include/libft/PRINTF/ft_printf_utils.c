/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:22:50 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/08 15:04:42 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		len += ft_putchr(str[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr(long nb)
{
	int	len;

	len = (nb < 0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchr(nb + '0');
	return (len);
}

int	ft_putnbr_hexa(unsigned long long nb, char *base)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_putnbr_hexa(nb / 16, base);
		len += ft_putnbr_hexa(nb % 16, base);
	}
	else
		len += ft_putchr(base[nb]);
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_putnbr_hexa(ptr, "0123456789abcdef");
	return (len);
}
