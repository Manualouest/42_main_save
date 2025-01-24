/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:32:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 18:58:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

int	ft_printf_fd(int fd, const char *str, ...);
int	ft_printf(const char *str, ...);
int	ft_cputstr(int fd, char *str);
int	ft_cputnbr(int fd, int nb);
int	ft_cuputnbr(int fd, unsigned int nb);
int	ft_cputchar(int fd, char c);
int	ft_convert_to_hex(int fd, unsigned int nb, char type);
int	ft_point_to_hex(int fd, unsigned long long nb);

#endif
