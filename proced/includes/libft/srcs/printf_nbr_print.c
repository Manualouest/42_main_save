/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:21:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	recurse(int fd, int nb, size_t *count)
{
	char	nb2;

	nb2 = 0;
	if (nb > 9)
	{
		recurse(fd, nb / 10, count);
	}
	nb2 = (nb % 10) + '0';
	*count = *count + write(fd, &nb2, 1);
}

int	ft_cputnbr(int fd, int nb)
{
	size_t	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		count += write(fd, "-", 1);
	}
	recurse(fd, nb, &count);
	return (count);
}

static void	urecurse(int fd, unsigned int nb, size_t *count)
{
	char	nb2;

	nb2 = 0;
	if (nb > 9)
	{
		urecurse(fd, nb / 10, count);
	}
	nb2 = (nb % 10) + '0';
	*count = *count + write(fd, &nb2, 1);
}

int	ft_cuputnbr(int fd, unsigned int nb)
{
	size_t	count;

	count = 0;
	urecurse(fd, nb, &count);
	return (count);
}
