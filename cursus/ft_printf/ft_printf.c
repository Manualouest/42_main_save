/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:36:44 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/13 10:21:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putvar(int total, const char *format, va_list var);

int	ft_printf(const char *format, ...)
{
	va_list	var;
	int		total;
	int		i;

	i = 0;
	total = 0;
	if (!format)
		return (-1);
	va_start(var, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			total = ft_putvar(total, &format[i], var);
			i++;
		}
		else if (format[i] != '%')
			total += ft_putcar(format[i]);
		i ++;
	}
	if (format[i - 1] == '%' && format[i - 2] != '%')
		return (-1);
	return (total);
}

static int	ft_putvar(int total, const char *format, va_list var)
{
	if (format[1] == 'c')
		total += ft_putcar((char)va_arg(var, int));
	else if (format[1] == 's')
		total += ft_putstr(va_arg(var, char *));
	else if (format[1] == 'p')
		total += ft_putvoid(va_arg(var, unsigned long long));
	else if (format[1] == 'd')
		total += ft_putint(va_arg(var, int));
	else if (format[1] == 'i')
		total += ft_putint(va_arg(var, int));
	else if (format[1] == 'u')
		total += ft_putuint(va_arg(var, unsigned int));
	else if (format[1] == 'x')
		total += ft_puthex(va_arg(var, unsigned int), "l"[0]);
	else if (format[1] == 'X')
		total += ft_puthex(va_arg(var, unsigned int), "u"[0]);
	else
		total += ft_putcar(format[1]);
	return (total);
}
