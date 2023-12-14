/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:35:08 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/24 09:26:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	if (nb < 10 && nb > -10)
	{
		nb = nb + '0';
		if (nb - '0' < 0)
			nb = ((nb - '0') * -1) + '0';
		write(1, &nb, 1);
	}
	else
	{
		if (nb % 10 < 0)
			temp = (nb % 10) * -1 + '0';
		else
			temp = nb % 10 + '0';
		if (nb < 0)
			ft_putnbr((nb / 10) * -1);
		else
			ft_putnbr(nb / 10);
		write(1, &temp, 1);
	}
}
