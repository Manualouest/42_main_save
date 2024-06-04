/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LeCoqBeau <mathieu.petru@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:23:55 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/10 18:23:55 by LeCoqBeau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_callfunc(char format, long long data);
static int	ft_processformat(char format, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			len += ft_putchr(format[i]);
			i++;
			continue ;
		}
		i++;
		len += ft_processformat(format[i], ap);
		if (len < 0 || format[i] == '\0')
			return (-1);
		i++;
	}
	va_end(ap);
	return (len);
}

static int	ft_processformat(char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		len = ft_putptr(va_arg(ap, unsigned long long));
	else if (format == '%')
		len = ft_putchr('%');
	else if (format == '\0')
		return (INT_MIN);
	else
		len = ft_callfunc(format, va_arg(ap, long long));
	return (len);
}

static int	ft_callfunc(char format, long long data)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchr((int)data);
	else if (format == 'i' || format == 'd')
		len = ft_putnbr((int)data);
	else if (format == 'u')
		len = ft_putnbr((unsigned int)data);
	else if (format == 'x')
		len = ft_putnbr_hexa((unsigned int)data, "0123456789abcdef");
	else if (format == 'X')
		len = ft_putnbr_hexa((unsigned int)data, "0123456789ABCDEF");
	else
	{
		len += ft_putchr('%');
		len += ft_putchr(format);
	}
	return (len);
}
