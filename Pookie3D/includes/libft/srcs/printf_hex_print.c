/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:53 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	urecurse(int fd, unsigned int nb, size_t *count, char type)
{
	if (nb > 15)
		urecurse(fd, nb / 16, count, type);
	else if (nb == 0)
		return ;
	if (type == 'x')
		*count = *count + write(fd, &"0123456789abcdef"[nb % 16], 1);
	else if (type == 'X')
		*count = *count + write(fd, &"0123456789ABCDEF"[nb % 16], 1);
}

int	ft_convert_to_hex(int fd, unsigned int nb, char type)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		count += write(fd, "0", 1);
	else
		urecurse(fd, nb, &count, type);
	return (count);
}

static void	precurse(int fd, unsigned long long nb, size_t *count)
{
	if (nb > 15)
		precurse(fd, nb / 16, count);
	else if (nb == 0)
		return ;
	*count = *count + write(fd, &"0123456789abcdef"[nb % 16], 1);
}

int	ft_point_to_hex(int fd, unsigned long long nb)
{
	size_t	count;

	count = 0;
	count += write(fd, "0x", 2);
	if (nb == 0)
		count += write(fd, "0", 1);
	else
		precurse(fd, nb, &count);
	return (count);
}
