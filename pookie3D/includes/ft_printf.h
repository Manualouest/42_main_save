/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:23:15 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/15 14:56:03 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchr(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long nb);
int	ft_putnbr_hexa(unsigned long long nb, char *base);
int	ft_putptr(unsigned long long ptr);

#endif
