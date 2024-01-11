/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/10 19:06:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putcar(char car);
int	ft_putint(int n);
int	ft_puthex(unsigned int num, char kind);
int	ft_putuint(unsigned int n);
int	ft_putvoid(unsigned long long num);

#endif